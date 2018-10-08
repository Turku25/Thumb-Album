#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

//#include <QThread>
#include <QObject>
#include <QtCore>
#include <QImageReader>
#include <QSqlQuery>
#include <QPixmap>
#include <QMediaPlayer>

#include "definitions.h"
#include "albumentry.h"
#include "albumviewer.h"
#include "importprogress.h"
#include "collisiondialog.h"



class ResourceManager
{
public:
    explicit ResourceManager(AlbumViewer* viewer, QWidget* rootParent);
    void loadView();
    void setGrid(int x, int y);
    bool setIndex(int index);
    void runImageQuery(QStringList* tags, QDate* start, QDate* end);
    bool focusView(int realitiveIndex);
    void exitFocus();
    void removeImage(QString filename);
    void saveImage(QString filename, QString description, QDateTime date, QStringList tags);
    QStringList getTagsOfImage(int index);
    QStringList getTagsOfCurrentImage();
    void startEdit();
    void saveEdit(QString filename, QString description, QDateTime date, QStringList tags);
    QDateTime dateTimeFromString(QString dateStr);

    bool forwards();
    bool backwards();

    void importImages(QStringList files);
    QStringList getImportQueue();

    std::tuple<int, int> getIndexStat();// current / total

    QList<AlbumEntry*> currentQuery;//ints are the indexes of allImages
    QStringList tags;
    AlbumEntry* editing = nullptr;

signals:

public slots:


private:
    QWidget* parent;
    void setShownGrid(int x, int y);

    void connectToDatabase();
    void loadDatabase();
    void disconnectFromDatabase();
    AlbumEntry* loadEntryData(int index, int quality,  QImageReader* reader);
    QString getUniqueFilename(QString filename);
    QString tagQuerey(QStringList* tags, QDate* start, QDate* end);

    void createScaledVersions(QString filename);
    void revertImport(int importID);
    QString getFormatedDate(QDateTime date);
    void addTags(QStringList tags, QString filename);



    //void RunImageQuery();

    QSqlDatabase database;
    QString resPath = "res/";

    AlbumViewer* albumViewer;
    int viewIndex = 0;
    int viewMode = PAGE_SIZE;
    int focusReturnIndex = 0;
    int unfocusX = 2;
    int unfocusY = 2;
    const int cacheSize = 50;
    QQueue<QPixmap*> cache;
};

#endif // RESOURCEMANAGER_H
