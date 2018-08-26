#include "filereaderthread.h"

FileReaderThread::FileReaderThread()
{

}

void FileReaderThread::fileReadLoop()
{
    /*while(true) // deadly...
    {
        if(readTasks.size() == 0)
            QThread::yieldCurrentThread();
        std::tuple<AlbumEntry* ,int> task = readTasks.at(0);
        AlbumEntry* entry = std::get<0>(task);
        int quality = std::get<1>(task);

        if(entry->filetype == IMAGE_MODE)
            readImage(entry, quality);

        readTasks.removeFirst();
    }*/
}

void FileReaderThread::addReadTask(AlbumEntry* entry, int quality)
{
    /*taskMutex.lock();
    readTasks.append(std::tuple<AlbumEntry* ,int>(entry, quality));
    taskMutex.unlock();*/
}

void FileReaderThread::readImage(AlbumEntry* entry, int quality)
{
    /*QImageReader* reader = new QImageReader();
    reader->setFileName("debug/res/imgs/" + entry->filename);//check the proper folder for quality
    QPixmap* image = new QPixmap();
    *image = QPixmap::fromImageReader(reader);
    //set the data of entry within a lock
    AlbumEntry::dataMutex.lock();
    entry->img = image;
    AlbumEntry::dataMutex.unlock();*/
}

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
