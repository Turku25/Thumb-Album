#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "albumview.h"
#include "albumviewer.h"
#include <QDebug>
#include <QImageReader>
#include <QObject>


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

    tagComplete = new QCompleter(rm->tags, this);
    ui->tagEdit->setCompleter(tagComplete);
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

    //disconnect db
}

//#################################################################### GUI
void MainWindow::refreshGUI()
{
    updateStat();
    rm->loadView();
    if(timer->isActive())
        timer->start();//hopefully this resets it
}

void MainWindow::resizeEvent(QResizeEvent* event)
{

}

void MainWindow::viewClicked(int realitiveIndex)
{
    rm->focusView(realitiveIndex);
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

}

void MainWindow::on_currentImageBox_editingFinished()
{
    if(rm->setIndex(ui->currentImageBox->value()))
        rm->loadView();
    updateStat();
}


void MainWindow::on_presentCheckbox_stateChanged(int arg1) // 2 is checked
{
    if(arg1 == 2)
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
    //if tag edit is in tagDB and not already in taglist add it to tag list
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
}

void MainWindow::on_removeTagButton_clicked()
{
    //ui->tagList->removeItemWidget(ui->tagList->currentItem());
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

    rm->runImageQuery(tags, start, end);
    refreshGUI();
}

void MainWindow::on_addPhotoButton_clicked()
{
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
                                                          "Images (*.jpg)");
    qDebug() << filenames;
    rm->importImages(filenames);
}
