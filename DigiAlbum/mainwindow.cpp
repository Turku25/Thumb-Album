#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "albumview.h"
#include "exif.h"
#include "albumviewer.h"
//#include <QDebug>
#include <QImageReader>
#include <QObject>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    showMaximized();

    timer = new QTimer();
    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(on_pageForwardsButton_clicked()));
    on_delayBox_valueChanged(ui->delayBox->value());

    QHBoxLayout* layout = (QHBoxLayout*)ui->view->layout();
    viewer = new AlbumViewer(ui->view, this);
    layout->insertWidget(0, viewer);

    rm = new ResourceManager(viewer, this);

    ui->importQueue->addItems(rm->getImportQueue());
    updateTags();
    ui->tagError->setVisible(false);

    rm->setGrid(2, 2);
    refreshGUI();
}

MainWindow::~MainWindow()
{
    delete timer;
    delete rm;
    delete viewer;
    delete ui;

    delete  currentTags;
    delete currentStart;
    delete currentEnd;
}

//#################################################################### GUI
void MainWindow::refreshGUI()
{
    updateStat();
    ui->imageTagList->clear();
    if(focused)
        ui->imageTagList->addItems(rm->getTagsOfCurrentImage());
    rm->loadView();
    if(timer->isActive())
        timer->start();
}

void MainWindow::resizeEvent(QResizeEvent* event)
{

}

void MainWindow::viewClicked(int realitiveIndex)
{
    focused = rm->focusView(realitiveIndex);
    if(focused)
    {
        ui->pageViewButton->setEnabled(false);
        ui->sheetViewButton->setEnabled(false);

        ui->editEntryButton->setEnabled(true);
        ui->imageTagLabel->setEnabled(true);
        ui->imageTagList->setEnabled(true);
    }
    else
    {
        ui->editEntryButton->setEnabled(false);
        ui->imageTagLabel->setEnabled(false);
        ui->imageTagList->setEnabled(false);

        ui->pageViewButton->setEnabled(!pageView);
        ui->sheetViewButton->setEnabled(pageView);
    }
    refreshGUI();
}

void MainWindow::updateStat()
{
    std::tuple<int, int> stat = rm->getIndexStat();
    ui->currentImageBox->setValue(std::get<0>(stat));
    ui->totalImagesLabel->setText(" / " + QString::number(std::get<1>(stat)));
}
void MainWindow::on_pageBackButton_clicked()
{
    if(rm->backwards())
        refreshGUI();
}

void MainWindow::on_pageForwardsButton_clicked()
{
    if(rm->forwards())
        refreshGUI();
    else if(timer->isActive())// looping during presentation mode
    {
        rm->setIndex(1);
        refreshGUI();
    }

}

void MainWindow::on_sheetViewButton_clicked()
{
    rm->setGrid(4, 4);
    refreshGUI();
    pageView = false;
    ui->pageViewButton->setEnabled(!pageView);
    ui->sheetViewButton->setEnabled(pageView);
}

void MainWindow::on_pageViewButton_clicked()
{
    rm->setGrid(2, 2);
    refreshGUI();
    pageView = true;
    ui->pageViewButton->setEnabled(!pageView);
    ui->sheetViewButton->setEnabled(pageView);
}

void MainWindow::on_currentImageBox_editingFinished()
{
    if(rm->setIndex(ui->currentImageBox->value()))
        rm->loadView();
    updateStat();
}


void MainWindow::on_presentCheckbox_stateChanged(int arg1)
{
    if(arg1 == 2) // 2 means box is checked
        timer->start();
    else
        timer->stop();
}

void MainWindow::on_delayBox_valueChanged(int arg1)
{
    timer->setInterval(1000 * arg1);
}

void MainWindow::on_addTagButton_clicked()
{
    for(int i = 0; i < ui->tagList->count(); i++)
    {
        if( ui->tagList->item(i)->text() == ui->tagEdit->text())
        {
            ui->tagError->setText("Tag already in list.");
            ui->tagError->setVisible(true);
            return;
        }
    }

    if(rm->tags.contains(ui->tagEdit->text(), Qt::CaseInsensitive))
    {
        ui->tagList->addItem( ui->tagEdit->text());
        ui->tagError->setVisible(false);
    }
    else
    {
        ui->tagError->setText("No such tag exists.");
        ui->tagError->setVisible(true);
    }
    ui->tagEdit->setText("");
}

void MainWindow::on_removeTagButton_clicked()
{
    delete ui->tagList->currentItem();
}

void MainWindow::on_searchButton_clicked()
{
    //get a string list from taglist
    QStringList* tags = new QStringList();
    for(int i = 0; i < ui->tagList->count(); i++)
    {
        tags->append(ui->tagList->item(i)->text());
    }
    QDate* start = new QDate(0, 0, 0);
    QDate* end = new QDate(0, 0, 0);

    if(ui->afterCheckBox->isChecked())
        *start = ui->afterDate->date();//year month day

    if(ui->beforeCheckBox->isChecked())
        *end = ui->beforeDate->date();//year month day

    delete  currentTags;
    delete currentStart;
    delete currentEnd;
    currentTags = tags;
    currentStart = start;
    currentEnd = end;
    rm->runImageQuery(tags, start, end);
    refreshGUI();
}

void MainWindow::on_addPhotoButton_clicked()
{
    editMode = false;
    ui->editFrame->setVisible(false);
    ui->importButton->setVisible(true);
    ui->importQueue->setVisible(true);

    clearImportFields();
    ui->importQueue->setCurrentRow(-1);

    ui->presentCheckbox->setCheckState(Qt::CheckState::Unchecked);
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_returnButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_importButton_clicked()
{
    QStringList filenames = QFileDialog::getOpenFileNames(this,
                                                          tr("OPEN FiLe"),
                                                          "C://",
                                                          "Images (*.jpg *.jpeg *.png)");
    qDebug() << filenames;
    rm->importImages(filenames);
    ui->importQueue->clear();
    ui->importQueue->addItems(rm->getImportQueue());
}

void MainWindow::on_importQueue_currentRowChanged(int currentRow)
{
    clearImportFields();
    if(currentRow < 0)
        return;
    int width = ui->importImage->width();
    int height = ui->importImage->height();
    QImageReader* reader = new QImageReader();
    reader->setFileName("res/imgs/mini/"+ ui->importQueue->currentItem()->text());//BAD, file reading shouldn't happen here
    ui->importImage->setPixmap(QPixmap::fromImageReader(reader).scaled(width,height,Qt::KeepAspectRatio));
    delete reader;

    //###########################################
    QFile imgFile("res/imgs/original/"+ ui->importQueue->currentItem()->text());//BAD, file reading should happen here!
    char* data;
    if(!imgFile.open(QIODevice::ReadOnly))
    {
        //qDebug() << "Failed to open image file.";
        return;
    }
    data = new char[imgFile.size()];
    imgFile.read(data, imgFile.size());
    easyexif::EXIFInfo meta;
    meta.parseFrom((unsigned char*)data, imgFile.size());
    QString dateTime = meta.DateTime.c_str();
    ui->dateTimeEdit->setDateTime(rm->dateTimeFromString(dateTime));
}

void MainWindow::updateTags()
{
    tagComplete = new QCompleter(rm->tags, this);
    ui->tagEdit->setCompleter(tagComplete);
    ui->importTagEdit->setCompleter(tagComplete);
}

void MainWindow::on_imporAddTag_clicked()
{
    QString text = ui->importTagEdit->text();
    for(int i = 0; i < ui->importTagList->count(); i++)
    {
        if( ui->importTagList->item(i)->text() == text)
            return;
    }
    ui->importTagList->addItem(text);
    ui->importTagEdit->setText("");
}

void MainWindow::on_importRemoveTag_clicked()
{
    delete ui->importTagList->currentItem();
}

void MainWindow::on_removeButton_clicked()
{
    if(!editMode && ui->importQueue->currentRow() < 0)
        return;

    switch( QMessageBox::question(
                this,
                tr("Deletion Warning"),
                tr("Are you sure you want to permanently delete this picture?"),

                QMessageBox::Yes |
                QMessageBox::No) )
    {
      case QMessageBox::Yes:
        break;
      case QMessageBox::No:
      default:
        return;
    }

    QString filename;
    if(editMode)
        filename = ui->editFileLabel->text();
    else
    {
        filename = ui->importQueue->currentItem()->text();
        delete ui->importQueue->currentItem();
    }
    rm->removeImage(filename);
    if(editMode)
    {
        refreshCurrentQuery();
        viewClicked(0);//get out of focus mode
        ui->stackedWidget->setCurrentIndex(0);
    }
}

//replaces are to account for sql string esscape codes
void MainWindow::on_saveImportButton_clicked()
{
    if(!editMode && ui->importQueue->currentRow() < 0)
        return;
    QString filename;
    QString description = ui->importDescription->text().replace("'","''");
    QDateTime date = ui->dateTimeEdit->dateTime();
    QStringList tags;
    for(int i = 0; i < ui->importTagList->count(); i++)
        tags.append(ui->importTagList->item(i)->text().replace("'","''"));
    if(editMode)
    {
        filename = ui->editFileLabel->text().replace("'","''");
        rm->saveEdit(filename, description, date, tags);
        refreshCurrentQuery();
        refreshGUI();
        ui->stackedWidget->setCurrentIndex(0);
    }
    else
    {
        filename = ui->importQueue->currentItem()->text().replace("'","''");
        rm->saveImage(filename, description, date, tags);
        delete ui->importQueue->currentItem();
    }
    updateTags();
}

void MainWindow::on_editEntryButton_clicked()
{
    rm->startEdit();
    editMode = true;
    ui->importButton->setVisible(false);
    ui->importQueue->setVisible(false);
    ui->editFrame->setVisible(true);

    clearImportFields();
    int width = ui->importImage->width();
    int height = ui->importImage->height();
    ui->importImage->setPixmap((*rm->editing->img).scaled(width,height,Qt::KeepAspectRatio));
    ui->editFileLabel->setText(rm->editing->filename);
    ui->importDescription->setText(rm->editing->description);
    ui->dateTimeEdit->setDateTime(rm->editing->date);
    //qDebug() << rm->editing->date;
    ui->importTagList->addItems(*rm->editing->tags);

    ui->presentCheckbox->setCheckState(Qt::CheckState::Unchecked);
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::clearImportFields()
{
    ui->importDescription->setText("");
    ui->importTagEdit->setText("");
    ui->importTagList->clear();
    ui->importImage->setPixmap(QPixmap());
}

void MainWindow::refreshCurrentQuery()
{
    rm->runImageQuery(currentTags, currentStart, currentEnd);
}
