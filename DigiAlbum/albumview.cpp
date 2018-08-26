#include "albumview.h"
#include <QDebug>

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QSpacerItem>

#include <QMouseEvent>


AlbumView::AlbumView(QWidget* parent, QColor background, int ind, bool label)/*, Qt::WindowFlags f)*/ : QWidget(parent)
{
    index = ind;
    showLabel = label;
    mainLayout = new QVBoxLayout(this);

    labelLayout = new QHBoxLayout();
    labelFrame = new QFrame();


    imageLabel = new QLabel();
    dateLabel = new QLabel("second label");
    descriptionLabel = new QLabel("second label v2s");
    spacer = new QSpacerItem(15, 0);
    spacer2 = new QSpacerItem(0,0,QSizePolicy::Policy::Expanding);//do 0s work for height widh?

    mainLayout->addWidget(imageLabel);
    if(showLabel)
    {
        mainLayout->addWidget(labelFrame);
        labelFrame->setLayout(labelLayout);

        labelLayout->addWidget(dateLabel);
        labelLayout->addSpacerItem(spacer);
        labelLayout->addWidget(descriptionLabel);
        labelLayout->addSpacerItem(spacer2);

        dateLabel->setText("");
        descriptionLabel->setText("LOADING...");

        //size policy
        QSizePolicy vertical;
        vertical.setVerticalPolicy(QSizePolicy::Policy::Fixed);
        vertical.setHorizontalPolicy(QSizePolicy::Policy::Minimum);

        dateLabel->setSizePolicy(vertical);
        dateLabel->setAlignment(Qt::AlignLeft);
        descriptionLabel->setSizePolicy(vertical);
        descriptionLabel->setAlignment(Qt::AlignLeft);
        labelFrame->setSizePolicy(vertical);
        //labelFrame->v
        labelLayout->setMargin(0);
    }
    mainLayout->setSpacing(3);// this is between the image and the text
    mainLayout->setMargin(0);

    QSizePolicy imagePolicy;
    imagePolicy.setVerticalPolicy(QSizePolicy::Policy::Minimum);
    imagePolicy.setHorizontalPolicy(QSizePolicy::Policy::Minimum);
    imageLabel->setMinimumHeight(1);
    imageLabel->setMinimumWidth(1);
    imageLabel->setSizePolicy(imagePolicy);

    //style
    QString style = "background: rgb(%1, %2, %3);";
    dateLabel->setStyleSheet("background: white;");
    descriptionLabel->setStyleSheet("background: white;");
    imageLabel->setStyleSheet(style.arg(background.red()).arg(background.green()).arg(background.blue()));
    labelFrame->setStyleSheet(style.arg(background.red()).arg(background.green()).arg(background.blue()));
    //background.
    imageLabel->setAlignment(Qt::AlignCenter);
    QFont font;
    font.setPointSize(15);//font size!
    dateLabel->setFont(font);
    descriptionLabel->setFont(font);

    //img = albumEntry->img;
}

void AlbumView::setPlaceholder(bool p)
{
    placeholder = p;
    imageLabel->clear();
    if(placeholder)
    {
        if(showLabel)
        {
            dateLabel->setVisible(false);
            descriptionLabel->setVisible(false);
        }
    }
    else
    {
        if(showLabel)
        {
            dateLabel->setVisible(true);
            descriptionLabel->setVisible(true);
        }
    }
}

AlbumView::~AlbumView()
{
    delete mainLayout;
    delete imageLabel;
    delete dateLabel;
    delete descriptionLabel;

}

void AlbumView::setEntry(AlbumEntry* entry)
{
    albumEntry = entry;
    dateLabel->setText(entry->date);
    descriptionLabel->setText(entry->description);
    ResizeImage();
}

void AlbumView::mouseReleaseEvent(QMouseEvent* event) {
    //When the left mouse button is released
    if(event->button() & Qt::LeftButton & !placeholder)
        emit clicked(index);
}

void AlbumView::setAlbumEntry(AlbumEntry* entry)//unused
{

}

void AlbumView::SetDate(QString date)
{
    dateLabel->setText(date);
}

void AlbumView::SetDescription(QString description)
{
    descriptionLabel->setText(description);

}

void AlbumView::SetImage(QPixmap *image)
{
}

void AlbumView::SetData(QString date, QString description, QPixmap* image)
{
    SetDate(date);
    SetDescription(description);
    SetImage(image);
}

void AlbumView::ResizeImage()
{
    int width = imageLabel->width();
    int height = imageLabel->height();
    if(!albumEntry->img->isNull())
    {
        imageLabel->setPixmap(albumEntry->img->scaled(width,height,Qt::KeepAspectRatio));
        //imageLabel->setStyleSheet("background: red;");
    }
    else
    {
        qDebug() << "image IS null";
        //imageLabel->setPixmap(img);
    }

}

QString AlbumView::GetDate()
{
    return dateLabel->text();
}

QString AlbumView::GetDescription()
{
    return descriptionLabel->text();
}

QPixmap* AlbumView::GetImage()
{
    return img;
}
