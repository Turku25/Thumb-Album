#include "collisiondialog.h"
#include "ui_collisiondialog.h"

CollisionDialog::CollisionDialog(QString oneFilepath, QString twoFilepath, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CollisionDialog)
{
    ui->setupUi(this);

    ui->imageOne->setScaledContents(true);
    ui->imageTwo->setScaledContents(true);

    QImageReader* reader = new QImageReader();
    reader->setScaledSize(QSize(100,100));

    reader->setFileName(oneFilepath);
    ui->imageOne->setPixmap(QPixmap::fromImageReader(reader));

    reader->setFileName(twoFilepath);
    ui->imageTwo->setPixmap(QPixmap::fromImageReader(reader));

    delete reader;
}

CollisionDialog::~CollisionDialog()
{
    delete ui;
}

/*//check for duplication
QImageReader* reader = new QImageReader();
reader->setFileName("debug/res/imgs/" + qualityPath + entry->filename);//check the proper folder for quality
QPixmap* image = new QPixmap();
*image = QPixmap::fromImageReader(reader);
QEventLoop::processEvents();*/
