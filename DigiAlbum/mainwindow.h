#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql>
#include <QCompleter>
#include <QFileDialog>

#include "definitions.h"
#include "albumview.h"
#include "resourcemanager.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void resizeEvent(QResizeEvent* event);
    void refreshGUI();
    void updateStat();
    ~MainWindow();

private slots:

    void on_pageBackButton_clicked();

    void on_pageForwardsButton_clicked();

    void on_sheetViewButton_clicked();

    void viewClicked(int realitiveIndex);

    void on_currentImageBox_editingFinished();

    void on_presentCheckbox_stateChanged(int arg1);

    void on_delayBox_valueChanged(int arg1);

    void on_addTagButton_clicked();

    void on_removeTagButton_clicked();

    void on_searchButton_clicked();

    void on_addPhotoButton_clicked();

    void on_returnButton_clicked();

    void on_importButton_clicked();

    void on_importQueue_currentRowChanged(int currentRow);

    void on_imporAddTag_clicked();

    void on_importRemoveTag_clicked();

    void on_removeButton_clicked();

    void on_saveImportButton_clicked();

    void on_pageViewButton_clicked();

    void on_editEntryButton_clicked();

private:
    void clearSheetView();

    //#################################################################### GUI
    void enterSingleView(int index);
    void loadPage();
    void loadImageTable();
    void updateTags();
    void clearImportFields();
    void refreshCurrentQuery();

    Ui::MainWindow *ui;
    AlbumView** albumViews = new AlbumView*[4];
    //#################################################################### DATA

    ResourceManager* rm;
    AlbumViewer* viewer;

    QTimer* timer;
    QCompleter* tagComplete;

    bool focused = false;
    bool pageView = true;
    bool editMode = false;

    QStringList* currentTags = new QStringList();
    QDate* currentStart = new QDate(0, 0, 0);
    QDate* currentEnd = new QDate(0, 0, 0);

};

#endif // MAINWINDOW_H
