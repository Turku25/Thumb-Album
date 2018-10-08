#ifndef IMPORTPROGRESS_H
#define IMPORTPROGRESS_H

#include <QDialog>
#include <QDebug>

namespace Ui {
class ImportProgress;
}

class ImportProgress : public QDialog
{
    Q_OBJECT

public:
    explicit ImportProgress(int totalCount, QWidget *parent = nullptr);
    ~ImportProgress();
    void updateProgress();
    void currentTask(QString task);
    bool canceled = false;

private slots:
    void on_ImportProgress_finished(int result);

private:
    Ui::ImportProgress *ui;
    int total = 0;
    int count = 0;
};

#endif // IMPORTPROGRESS_H
