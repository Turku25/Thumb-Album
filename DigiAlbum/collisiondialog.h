#ifndef COLLISIONDIALOG_H
#define COLLISIONDIALOG_H

#include <QDialog>
#include <QPixmap>
#include <QImageReader>

namespace Ui {
class CollisionDialog;
}

class CollisionDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CollisionDialog(QString oneFilepath, QString twoFilepath, QWidget *parent = nullptr);
    ~CollisionDialog();

private:
    Ui::CollisionDialog *ui;
};

#endif // COLLISIONDIALOG_H
