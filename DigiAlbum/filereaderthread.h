#ifndef FILEREADERTHREAD_H
#define FILEREADERTHREAD_H

#include <QObject>
#include <QtCore>
#include <QPixmap>

#include "definitions.h"
#include "albumentry.h"

class FileReaderThread : public QObject
{
    Q_OBJECT
public:
    FileReaderThread();

public slots:
    void fileReadLoop();
    void addReadTask(AlbumEntry* entry, int quality);//filepath, quality, AlbumEntry(to put data in)
private:
    void readImage(AlbumEntry* entry, int quality);
    void readVideo(AlbumEntry* entry, int quality);
    void readGif(AlbumEntry* entry, int quality);
    QList<std::tuple<AlbumEntry* ,int>> readTasks;
    QMutex taskMutex;
};

#endif // FILEREADERTHREAD_H

/*
QThread* thread = new QThread;
Worker* worker = new Worker();
worker->moveToThread(thread);
connect(worker, SIGNAL(error(QString)), this, SLOT(errorString(QString)));
connect(thread, SIGNAL(started()), worker, SLOT(process()));
connect(worker, SIGNAL(finished()), thread, SLOT(quit()));
connect(worker, SIGNAL(finished()), worker, SLOT(deleteLater()));
connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));
thread->start();
*/
