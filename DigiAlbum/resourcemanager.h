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
#include "importProgress.h"
#include "collisiondialog.h"



class ResourceManager
{
public:
    explicit ResourceManager(AlbumViewer* viewer, QWidget* rootParent);
    void loadView();
    void setGrid(int x, int y);
    bool setIndex(int index);
    void runImageQuery(QStringList* tags, QDate* start, QDate* end);
    void focusView(int realitiveIndex);
    void exitFocus();

    bool forwards();
    bool backwards();

    void importImages(QStringList files);

    std::tuple<int, int> getIndexStat();// current / total

    QList<AlbumEntry*> currentQuery;//ints are the indexes of allImages

    QStringList tags;

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


    //void RunImageQuery();

    QSqlDatabase database;
    QString resPath = "debug/res/";

    AlbumViewer* albumViewer;
    int viewIndex = 0;
    int viewMode = PAGE_SIZE;
    int focusReturnIndex = 0;
    int unfocusX = 2;
    int unfocusY = 2;
    const int cacheSize = 50;
    QQueue<QPixmap*> cache;

    bool importCanceled = false;
};

#endif // RESOURCEMANAGER_H
