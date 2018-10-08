#include "resourcemanager.h"
#include <QtCore>
//#include <QDebug>
#include <QSqlError>

//##### PUBLIC ######################################################################

ResourceManager::ResourceManager(AlbumViewer* viewer, QWidget* rootParent)
{
    albumViewer = viewer;
    parent = rootParent;
    connectToDatabase();//self explanitory
    loadDatabase();//load tags

}

void ResourceManager::loadView()
{  
    int end = viewMode;
    if(viewIndex + end > currentQuery.size())// dont go past the last picture
        end = currentQuery.size() - viewIndex;
    QImageReader* reader = new QImageReader();
    albumViewer->prepareView(end);

    int quality = 0;
    if(viewMode > 2)
        quality = MINI_QUALITY;
    else
        quality = FULL_QUALITY;


    int i = 0;
    for(; i < end; i++)
    {
        albumViewer->setEntry(loadEntryData(i + viewIndex, quality, reader), i);
    }
    delete reader;
}

bool ResourceManager::focusView(int realitiveIndex)
{
    if(viewMode == 1 && unfocusX * unfocusY == 1)//Don't use view mode 1 lol
        return false;
    if(viewMode == 1) //unfocus
    {
        if(viewIndex >= currentQuery.count())//unfocus after deletion of an image
            viewIndex = currentQuery.count() - 1;
        viewIndex -= viewIndex % (unfocusX * unfocusY);//view index is first of current page
        setShownGrid(unfocusX, unfocusY);
        return false;
    }
    else                        // focus
    {
        setShownGrid(1,1);
        viewIndex += realitiveIndex;
        return true;
    }
}

void ResourceManager::setShownGrid(int x, int y)
{
    viewMode = x * y;
    albumViewer->setGrid(x, y);
}

void ResourceManager::setGrid(int x, int y)
{
    unfocusX = x;
    unfocusY = y;
    viewIndex -= viewIndex % (unfocusX * unfocusY);
    setShownGrid(x, y);
}

bool ResourceManager::setIndex(int index)
{
    if( index > 0 && (index - 1) * viewMode < currentQuery.size())
    {
        viewIndex = (index - 1) * viewMode;
        return true;
    }
    return false;
}

bool ResourceManager::forwards()
{
    if(viewIndex + viewMode < currentQuery.size())
    {
        viewIndex += viewMode;
        return true;
    }
    return false;
}

bool ResourceManager::backwards()
{
    if(viewIndex - viewMode >= 0)
    {
        viewIndex -= viewMode;
        return true;
    }
    return false;
}

std::tuple<int, int> ResourceManager::getIndexStat()
{
    std::tuple<int, int> stat;
    std::get<0>(stat) = viewIndex / viewMode + 1;// +1 for 0-indexing
    std::get<1>(stat) = currentQuery.size() / viewMode + ((currentQuery.size() % viewMode == 0)?0:1);
    return stat;
}



void ResourceManager::importImages(QStringList files)
{
    ImportProgress* importDiolog= new ImportProgress(files.size(), parent);
    importDiolog->show();

    QSqlQuery qry;
    if(!qry.exec("SELECT ImportID FROM Imports ORDER BY ImportID DESC LIMIT 1;"))
        qDebug() << "query Failed. get importID";
    int importID = (qry.next())?qry.value(0).toInt():0;
    importID++;                                                         //AT LEAST ONE MUST ME ADDED FOR IMPORTID TO WORK!
    qry.clear();

    for(QString path: files)
    {

        QString filenameUnique = getUniqueFilename(path);
        importDiolog->currentTask(filenameUnique);
        if(filenameUnique != "")
        {
            QFile::copy(path, resPath+"imgs/original/" + filenameUnique);

            createScaledVersions(filenameUnique);

            if(!qry.exec("INSERT INTO Imports (Filename, ImportID) "
                         "VALUES ('" + filenameUnique + "', "+ QString::number(importID) + ")"))
                qDebug() << "query Failed. Imports insert.";
        }

        importDiolog->updateProgress();
        if(importDiolog->canceled)
        {
            importDiolog->currentTask("Reverting import...");
            revertImport(importID);
            break;
        }
    }
    delete importDiolog;
}


//##### PRIVATE ######################################################################


//############### FILE READING #######################################################
AlbumEntry* ResourceManager::loadEntryData(int index, int quality, QImageReader* reader = new QImageReader())
{
    AlbumEntry* entry = currentQuery.at(index);
    if(entry->img == nullptr || entry->quality < quality)
    {
        QString qualityPath;
        if(quality == FULL_QUALITY)
            qualityPath = "full/";
        if(quality == MINI_QUALITY)
            qualityPath = "mini/";

        reader->setFileName(resPath + "imgs/" + qualityPath + entry->filename);//check the proper folder for quality
        QPixmap* image = new QPixmap();
        *image = QPixmap::fromImageReader(reader);
        entry->img = image;
        entry->quality = quality;

        //cache stuff
        if(cache.size() > cacheSize)
            delete cache.dequeue();
        cache.enqueue(image);
    }
    return entry;
}

void ResourceManager::createScaledVersions(QString filename)
{
    QImageReader* reader = new QImageReader();

    reader->setFileName(resPath + "imgs/original/" +  filename);
    QImage full = reader->read();
    QImage mini = full.copy();

    if(full.width() > 1620 || full.height() > 1080)
        full = full.scaled(1620, 1080,Qt::AspectRatioMode::KeepAspectRatio, Qt::TransformationMode::SmoothTransformation);
    if(mini.width() > 810 || mini.height() > 540)
        mini = mini.scaled(810, 540,Qt::AspectRatioMode::KeepAspectRatio, Qt::TransformationMode::SmoothTransformation);

    full.save(resPath + "imgs/full/" +  filename);
    mini.save(resPath + "imgs/mini/" +  filename);

    delete reader;
}


//############### DATABASE ###########################################################
void ResourceManager::loadDatabase()
{
    QSqlQuery qry;
    qry.prepare("SELECT Tag, * FROM TagList");
    if(!qry.exec())
        qDebug() << "query Failed";

    while(qry.next())
        tags.append(qry.value(0).toString());
}

void ResourceManager::connectToDatabase()
{
    database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName(resPath+"DigiAlbum.db");
    if(!database.open())
    {
        qDebug() << "failed to open";
    }
}

void ResourceManager::disconnectFromDatabase()
{
    database.close();
    database.removeDatabase(QSqlDatabase::defaultConnection);
}

void ResourceManager::runImageQuery(QStringList* tags, QDate* start, QDate* end)//take in perameters of tags and date
{
    for(int i = currentQuery.size(); i > 0; i--)
        delete currentQuery.takeFirst();
    for(int i = cache.size(); i > 0; i--)
        delete cache.dequeue();

    QSqlQuery qry;
    QString qryString = "SELECT * "
                        "FROM Images as img ";
    qryString += tagQuerey(tags, start, end);
    //date studd here?
    qryString += "ORDER BY Time ASC";
    //qDebug() << qryString;

    if(!qry.exec(qryString))
        qDebug() << "query Failed";
    while(qry.next())
    {
        currentQuery.append(new AlbumEntry(qry.value(0).toString(),
                                           qry.value(1).toString(),
                                           dateTimeFromString(qry.value(2).toString())));//,
                                           //qry.value(3).toInt())); for data types
    }
}

//Assembles an AND search of active tags
QString ResourceManager::tagQuerey(QStringList* tags, QDate* start, QDate* end)
{
    QString tagSearch = "";
    if(tags->size() != 0)
    {
        tagSearch = "JOIN TagPairs as tags ON img.filename = tags.filename "
                            "WHERE tags.tag IN (";
        for(int i = 0; i < tags->size(); i++)
        {
            tagSearch += "'" + tags->at(i) + "'";
            if(i != tags->size() - 1)
                tagSearch += ", ";
        }
        tagSearch += ") "
                       "GROUP BY img.filename "
                        " HAVING COUNT(img.filename) = " + QString::number(tags->size()) + " ";
    }

    if(start->year() != 0 || end->year() != 0)
    {
        if(tags->size() != 0)
            tagSearch += "AND ";
        else
            tagSearch += "WHERE ";
    }

    //DATE
    if(start->year() != 0 && end->year() != 0)
        tagSearch += "img.Time BETWEEN '" + start->toString(Qt::DateFormat::ISODate) +"' AND '" + end->toString(Qt::DateFormat::ISODate) +"' ";
    if(start->year() != 0 && end->year() == 0)
        tagSearch += "img.Time > '" + start->toString(Qt::DateFormat::ISODate) + "' ";
    if(start->year() == 0 && end->year() != 0)
        tagSearch += "img.Time < '" + end->toString(Qt::DateFormat::ISODate) + "' ";

    return tagSearch;
}

QString ResourceManager::getUniqueFilename(QString filepath) // try returning a string list. 1 if no collision, (new, collidePath) if collide
{
    QString filename = filepath.split("/").last();
    QSqlQuery qry;
    bool unique = false;

    while(!unique)
    {
        unique = true;

        if(!qry.exec("SELECT * FROM Images WHERE Filename = '" + filename +"';"))
            qDebug() << "query Failed. Images search.";
        unique &= !qry.next();

        qry.clear();
        if(!qry.exec("SELECT * FROM Imports WHERE Filename = '" + filename +"';"))
            qDebug() << "query Failed. Imports search.";
        unique &= !qry.next();

        if(!unique)
        {
            //check if copy
            CollisionDialog collision(resPath + "imgs/original/" + filename, filepath, parent);//need images or at least file paths
            collision.setModal(true);
            if(collision.exec() == 1) // 1 IS copy, 0 is NOT copy
            {
                return "";
            }
            //if not copy
            QStringList halfs = filename.split(".");
            filename = halfs[0] + "D." + halfs[1]; // D for duplicate I guess?? Just appending more Ds might not be the best idea.
        }
    }
    return filename;
}

void ResourceManager::revertImport(int importID)
{
    QSqlQuery qry;
    if(!qry.exec("SELECT Filename FROM Imports where ImportID = " + QString::number(importID)))
        qDebug() << "revert query failed";

    while(qry.next())
    {
        QFile file (resPath + "imgs/original/" + qry.value(0).toString());
        file.remove();
        file.setFileName(resPath + "imgs/full/" + qry.value(0).toString());
        file.remove();
        file.setFileName(resPath + "imgs/mini/" + qry.value(0).toString());
        file.remove();
    }
    qry.clear();
    if(!qry.exec("DELETE FROM Imports WHERE ImportID = " + QString::number(importID)))
        qDebug() << "Failed to revert Imports table";
}

QStringList ResourceManager::getImportQueue()
{
    QStringList queue;
    QSqlQuery qry;
    if(!qry.exec("SELECT Filename FROM Imports"))
        qDebug() << "failed to get import queue";

    while(qry.next())
        queue.append(qry.value(0).toString());

    return queue;
}

void ResourceManager::removeImage(QString filename)
{
    //qDebug() << filename;
    QSqlQuery qry;
    if(!qry.exec("DELETE FROM Imports WHERE Filename = '" + filename + "'"))
        qDebug() << "failed to remove entry: " << qry.lastError();
    qry.clear();
    if(!qry.exec("DELETE FROM Images WHERE Filename = '" + filename + "'"))
        qDebug() << "failed to remove entry";
    QFile(resPath + "imgs/original/"+filename).remove();
    QFile(resPath + "imgs/full/"+filename).remove();
    QFile(resPath + "imgs/mini/"+filename).remove();
}

void ResourceManager::saveImage(QString filename, QString description, QDateTime date, QStringList tags)
{
    //Add to Images table
    QSqlQuery qry;
    QString formatedTime = getFormatedDate(date);
    if(!qry.exec("INSERT INTO Images (Filename, Description, Time, Filetype)"
                 "VALUES ('" + filename + "','" + description + "', "
                 "'" + formatedTime +"', 1)"))
        qDebug() << "failed to add entry: " << qry.lastError();
    qry.clear();
    //Remove from Imports table
    if(!qry.exec("DELETE FROM Imports WHERE Filename = '" + filename + "'"))
            qDebug() << "failed to remove import after saving: ";
        qry.clear();
    //Add new tags to Tags table
    addTags(tags, filename);
}

QStringList ResourceManager::getTagsOfImage(int index)
{
    AlbumEntry* entry = currentQuery.at(index);
    QStringList tags;
    if(entry != nullptr)
    {
        if(entry->tags == nullptr)
        {
            entry->tags = new QStringList();
            QSqlQuery qry;
            if(!qry.exec("SELECT Tag FROM TagPairs WHERE Filename = '" + entry->filename + "'"))
                qDebug() << "failed to get tagList";
            while(qry.next())
                entry->tags->append(qry.value(0).toString());
        }
        tags = *entry->tags;
    }
    return tags;

}

void ResourceManager::startEdit()
{
    editing = currentQuery.at(viewIndex);
}

void ResourceManager::saveEdit(QString filename, QString description, QDateTime date, QStringList tags)
{
    if(editing == nullptr)
    {
        qDebug() << "not editing any record! what's going on???";
        return;
    }

    //qDebug() << "Image table";
    QSqlQuery qry;
    if(filename != editing->filename || description != editing->description || date != editing->date)
    {
        if(!qry.exec("UPDATE Images SET Filename = '" + filename + "', Description = '" + description +
                     "', Time = '" + getFormatedDate(date) + "' WHERE Filename = '" + editing->filename + "'"))
                qDebug() << "failed to update Images table: " << qry.lastError();
            qry.clear();
    }

    //Tag updating
    //find differences. this is 2N + N^2 as oppsed to looping twice which would be 2N^2
    QStringList addedTags(tags);
    QStringList removedTags(*editing->tags);
    for(QString tag: addedTags)
    {
        if(removedTags.contains(tag))
        {
            addedTags.removeOne(tag);
            removedTags.removeOne(tag);
        }
    }
    //add new ones to TagList table
    //add connections of new tags
    addTags(addedTags, filename);
    //remove connections of old tags
    if(removedTags.count() > 0)
    {
        qDebug() << "removing at least one tag pair";
        //this uses the new filename because of cascading changes from the potential rename
        QString removeQuery = "DELETE FROM TagPairs WHERE Filename = '" + filename +"' AND (Tag = '" + removedTags[0] + "'";

        for(int i = 1; i < removedTags.count(); i++)
        {
            removeQuery += " OR Tag = '" + removedTags[i] + "'";
            //next case
        }
        removeQuery += ")"; // end of tag OR tag
        if(!qry.exec(removeQuery))
                qDebug() << "failed to delete tag pairs";
            qry.clear();
    }
    //remove tags that have no pairs? do in an update maybe..
    //change local copy
    editing->filename = filename;
    editing->description = description;
    editing->date = date;
    if(editing->tags != nullptr) // this should always be true, but just in case
        delete editing->tags;
    editing->tags = new QStringList(tags);
}

QStringList ResourceManager::getTagsOfCurrentImage()
{
    return getTagsOfImage(viewIndex);
}

QString ResourceManager::getFormatedDate(QDateTime date)
{
    QDate d = date.date();
    QTime t = date.time();
    return QString::number(d.year()) + "-" + QString::number(d.month()) + "-" + QString::number(d.day()) +
            " " + QString::number(t.hour()) + "-" + QString::number(t.minute()) + "-" + QString::number(t.second()); //YYYY-MM-DD HH:MM:SS
}

void ResourceManager::addTags(QStringList tags, QString filename)
{
    QSqlQuery qry;
    for(QString tag: tags)
    {
        if(!ResourceManager::tags.contains(tag, Qt::CaseInsensitive))
        {
            ResourceManager::tags.append(tag);
            if(!qry.exec("INSERT INTO TagList (Tag) VALUES('" + tag + "')"))
                    qDebug() << "failed to add new tag: ";
                qry.clear();
        }
        //Connect tags in TagPairs table
        if(!qry.exec("INSERT INTO TagPairs (Tag, Filename) VALUES('" + tag + "', '" + filename + "')"))
                qDebug() << "failed to add tagp pair: ";
            qry.clear();
    }
}
QDateTime ResourceManager::dateTimeFromString(QString dateStr)
{
    QDateTime date;
    if(dateStr != "")
    {
        QStringList pieces = dateStr.split(QRegularExpression("[-: ]"));
        date.setDate(QDate(pieces[0].toInt(), pieces[1].toInt(), pieces[2].toInt()));
        date.setTime(QTime(pieces[3].toInt(), pieces[4].toInt(), pieces[5].toInt()));
    }
    else
        qDebug() << "couldn't read the datetime";
    return date;
}

