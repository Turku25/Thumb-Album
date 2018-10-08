#include "albumviewer.h"

//#include <QDebug>
#include <QApplication>


AlbumViewer::AlbumViewer(QWidget* parent, const QObject* main) : QWidget(parent)
{
    controller = main;
    layout = new QGridLayout(this);
    layout->setMargin(0);
}

//removes all widgets from the layout
void AlbumViewer::clear()
{
    //dissconnect sig/slot FOR all in views list
    for(int i = views.size() - 1; i >= 0 ; i--)
        disconnect(views.at(i), SIGNAL(clicked(int)), controller, SLOT(viewClicked(int)));
    views.clear();

    for(int i = layout->count() - 1; i >= 0 ; i--)
    {
        QLayoutItem* item = layout->itemAt(i);
        layout->removeItem(item);
        delete item->widget();
        delete item->layout();
        delete item;
    }
}

void AlbumViewer::setGrid(int width, int height)
{
    clear();//only clear if it's a different size
    horizViews = width;
    vertiViews = height;
    bool tags = horizViews * vertiViews < 6;

    for(int y = 0; y < vertiViews; y++)
        for(int x = 0; x < horizViews; x++)
        {
            int r = x * 20/ horizViews + 5;
            int b = y * 20 / horizViews + 5;

            AlbumView* view = new AlbumView(this, QColor(r, 0 ,b), (y * horizViews + x), tags);
            connect(view, SIGNAL(clicked(int)), controller, SLOT(viewClicked(int))); //placeholders also get sig/slots, but are dissableed
            layout->addWidget(view, y, x);
            views.append(view);
        }
}

void AlbumViewer::setEntry(AlbumEntry* entry, int index)
{
    views.at(index)->setEntry(entry);

    QApplication::processEvents();
}

void AlbumViewer::prepareView(int entries)
{
    int index = 0;
    for(AlbumView* view : views)
    {

        if(index < entries)
            view->setPlaceholder(false);
        else
            view->setPlaceholder(true);
        index++;
    }

    QApplication::processEvents();
}
