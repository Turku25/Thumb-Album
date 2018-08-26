#ifndef ALBUMENTRY_H
#define ALBUMENTRY_H

#define FULL_QUALITY 2
#define MINI_QUALITY 1

#include <QString>
#include <QtCore>
#include <QMediaPlayer>
#include <QMovie>


struct AlbumEntry
{
    QString filename;
    QString description;
    QString date;
    int quality;

    QPixmap* img = nullptr;
    //QMediaPlayer* vid;
    //QMovie* gif;

    //static QMutex dataMutex;//close mutex before changing data pointers and before displaying their contents

    AlbumEntry(QString filename_, QString description_, QString date_/*, int filetype_*/)
    {
        filename = filename_;
        description = description_;
        date = date_;
        //filetype = filetype_;
    }
};

#endif // ALBUMENTRY_H

