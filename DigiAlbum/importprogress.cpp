#include "importprogress.h"
#include "ui_importprogress.h"

ImportProgress::ImportProgress(int totalCount, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ImportProgress)
{
    ui->setupUi(this);
    total = totalCount;
}

ImportProgress::~ImportProgress()
{
    delete ui;
}

void ImportProgress::updateProgress()
{
    count++;
    ui->progressBar->setValue((count * 100) / total);
    qApp->processEvents();// display progress bar to screen
}

void ImportProgress::currentTask(QString task)
{
    ui->label->setText(task);
    qApp->processEvents();// display progress bar to screen
}
