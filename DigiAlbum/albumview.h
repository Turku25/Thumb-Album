#ifndef ALBUMVIEW_H
#define ALBUMVIEW_H
#include <QWidget>
#include <QMediaPlayer>

#include <definitions.h>
#include "albumentry.h"

//forward declarations ////whay are these forward declerations instead of includes? diamond problem?
class QVBoxLayout;
class QHBoxLayout;
class QLabel;
class QPushButton;
class QSpacerItem;
class QFrame;

class AlbumView : public QWidget //inherit from QWidget
{
    Q_OBJECT
public:
    AlbumView(QWidget* parent, QColor background, int ind, bool label = true);//Q_NULLPTR, Qt::WindowFlags f = Qt::WindowFlags()); //don't forget to pass the parent
    ~AlbumView();
    void setEntry(AlbumEntry* entry);
    //#####v possibally obsolete v#####
    void SetDate(QString date);
    void SetDescription(QString description);
    void SetImage(QPixmap* image);//at least I think I want a QImage
    //#####^ possibally obsolete ^#####
    void setAlbumEntry(AlbumEntry* entry);
    void SetData(QString date, QString description, QPixmap* image);
    void ResizeImage();
    QString GetDate();
    QString GetDescription();
    QPixmap* GetImage();
    void setPlaceholder(bool p);

private:
//contained widgets:
    QVBoxLayout *mainLayout;

    QHBoxLayout* labelLayout;
    QFrame* labelFrame;
    QVBoxLayout* descriptionLayout;

    QLabel *imageLabel;
    QLabel *dateLabel;
    QLabel *descriptionLabel;
    QSpacerItem *spacer;
    QPixmap *img;

    AlbumEntry* albumEntry;
    int index = -1;
    bool showLabel = true;
    bool placeholder = false;

signals:
    void clicked(int index);
protected:
    void mouseReleaseEvent(QMouseEvent* event);
};
#endif // ALBUMVIEW_H
