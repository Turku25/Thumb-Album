#ifndef ALBUMVIEWER_H
#define ALBUMVIEWER_H

//#include <QMainWindow>
#include <QWidget>
#include <QGridLayout>
#include <QFrame>

#include "albumentry.h"
#include "albumview.h"
//#include "mainwindow.h"

//class MainWindow : QMainWindow{};
class QGridLayout;

//class QGridLayout

class AlbumViewer : public QWidget
{
    Q_OBJECT
public:
    AlbumViewer(QWidget* parent, const QObject* main);

    void clear();
    void setGrid(int width, int height);
    void setEntry(AlbumEntry* entry, int index);
    void prepareView(int entries);

private:
    const QObject* controller;
    QGridLayout* layout;
    QList<AlbumView*> views;
    int horizViews = 0;
    int vertiViews = 0;
};

#endif // ALBUMVIEWER_H
