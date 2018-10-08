/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QFrame *baseFrame;
    QHBoxLayout *horizontalLayout_2;
    QStackedWidget *stackedWidget;
    QWidget *view;
    QHBoxLayout *horizontalLayout_3;
    QFrame *frame;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *pageBackButton;
    QPushButton *pageForwardsButton;
    QHBoxLayout *horizontalLayout_5;
    QSpinBox *currentImageBox;
    QLabel *totalImagesLabel;
    QCheckBox *presentCheckbox;
    QHBoxLayout *horizontalLayout_10;
    QSpinBox *delayBox;
    QLabel *label_6;
    QFrame *line;
    QLabel *label_8;
    QLineEdit *tagEdit;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *addTagButton;
    QPushButton *removeTagButton;
    QLabel *tagError;
    QListWidget *tagList;
    QFrame *line_2;
    QLabel *label_9;
    QHBoxLayout *horizontalLayout_8;
    QCheckBox *afterCheckBox;
    QDateEdit *afterDate;
    QHBoxLayout *horizontalLayout_9;
    QCheckBox *beforeCheckBox;
    QDateEdit *beforeDate;
    QFrame *line_3;
    QPushButton *searchButton;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_11;
    QPushButton *pageViewButton;
    QPushButton *sheetViewButton;
    QFrame *line_5;
    QPushButton *editEntryButton;
    QLabel *imageTagLabel;
    QListWidget *imageTagList;
    QSpacerItem *verticalSpacer;
    QPushButton *addPhotoButton;
    QWidget *import_2;
    QHBoxLayout *horizontalLayout_6;
    QFrame *frame_2;
    QHBoxLayout *horizontalLayout_16;
    QVBoxLayout *verticalLayout;
    QFrame *editFrame;
    QVBoxLayout *verticalLayout_5;
    QLabel *editLabel;
    QLabel *editFileLabel;
    QSpacerItem *verticalSpacer_3;
    QPushButton *importButton;
    QListWidget *importQueue;
    QPushButton *removeButton;
    QFrame *line_4;
    QVBoxLayout *verticalLayout_3;
    QLabel *label;
    QLineEdit *importDescription;
    QHBoxLayout *horizontalLayout_13;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_3;
    QDateTimeEdit *dateTimeEdit;
    QLabel *label_4;
    QLineEdit *importTagEdit;
    QHBoxLayout *horizontalLayout_12;
    QPushButton *imporAddTag;
    QPushButton *importRemoveTag;
    QListWidget *importTagList;
    QLabel *importImage;
    QHBoxLayout *horizontalLayout_15;
    QPushButton *saveImportButton;
    QPushButton *returnButton;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1000, 866);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(0, 0));
        MainWindow->setStyleSheet(QStringLiteral("background: silver;"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        sizePolicy.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy);
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        baseFrame = new QFrame(centralWidget);
        baseFrame->setObjectName(QStringLiteral("baseFrame"));
        sizePolicy.setHeightForWidth(baseFrame->sizePolicy().hasHeightForWidth());
        baseFrame->setSizePolicy(sizePolicy);
        baseFrame->setStyleSheet(QStringLiteral(""));
        baseFrame->setFrameShape(QFrame::StyledPanel);
        baseFrame->setFrameShadow(QFrame::Plain);
        baseFrame->setLineWidth(1);
        horizontalLayout_2 = new QHBoxLayout(baseFrame);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        stackedWidget = new QStackedWidget(baseFrame);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        sizePolicy.setHeightForWidth(stackedWidget->sizePolicy().hasHeightForWidth());
        stackedWidget->setSizePolicy(sizePolicy);
        stackedWidget->setStyleSheet(QStringLiteral("background: black"));
        view = new QWidget();
        view->setObjectName(QStringLiteral("view"));
        sizePolicy.setHeightForWidth(view->sizePolicy().hasHeightForWidth());
        view->setSizePolicy(sizePolicy);
        horizontalLayout_3 = new QHBoxLayout(view);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        frame = new QFrame(view);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setMinimumSize(QSize(240, 0));
        frame->setMaximumSize(QSize(200, 16777215));
        frame->setStyleSheet(QStringLiteral("background: silver"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout_2 = new QVBoxLayout(frame);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        pageBackButton = new QPushButton(frame);
        pageBackButton->setObjectName(QStringLiteral("pageBackButton"));
        QFont font;
        font.setPointSize(16);
        pageBackButton->setFont(font);
        pageBackButton->setStyleSheet(QStringLiteral("background: green;"));

        horizontalLayout_4->addWidget(pageBackButton);

        pageForwardsButton = new QPushButton(frame);
        pageForwardsButton->setObjectName(QStringLiteral("pageForwardsButton"));
        pageForwardsButton->setFont(font);
        pageForwardsButton->setStyleSheet(QStringLiteral("background: green;"));

        horizontalLayout_4->addWidget(pageForwardsButton);


        verticalLayout_2->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(0);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        currentImageBox = new QSpinBox(frame);
        currentImageBox->setObjectName(QStringLiteral("currentImageBox"));
        QFont font1;
        font1.setPointSize(12);
        currentImageBox->setFont(font1);
        currentImageBox->setStyleSheet(QStringLiteral("background: white"));
        currentImageBox->setButtonSymbols(QAbstractSpinBox::NoButtons);
        currentImageBox->setMinimum(1);

        horizontalLayout_5->addWidget(currentImageBox);

        totalImagesLabel = new QLabel(frame);
        totalImagesLabel->setObjectName(QStringLiteral("totalImagesLabel"));
        totalImagesLabel->setFont(font1);

        horizontalLayout_5->addWidget(totalImagesLabel);


        verticalLayout_2->addLayout(horizontalLayout_5);

        presentCheckbox = new QCheckBox(frame);
        presentCheckbox->setObjectName(QStringLiteral("presentCheckbox"));
        presentCheckbox->setFont(font1);

        verticalLayout_2->addWidget(presentCheckbox);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(1);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        delayBox = new QSpinBox(frame);
        delayBox->setObjectName(QStringLiteral("delayBox"));
        delayBox->setEnabled(true);
        delayBox->setFont(font1);
        delayBox->setStyleSheet(QStringLiteral("background: white"));
        delayBox->setMinimum(1);
        delayBox->setValue(5);

        horizontalLayout_10->addWidget(delayBox);

        label_6 = new QLabel(frame);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setEnabled(true);
        label_6->setFont(font1);

        horizontalLayout_10->addWidget(label_6);


        verticalLayout_2->addLayout(horizontalLayout_10);

        line = new QFrame(frame);
        line->setObjectName(QStringLiteral("line"));
        line->setLineWidth(5);
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(line);

        label_8 = new QLabel(frame);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setFont(font);
        label_8->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_8);

        tagEdit = new QLineEdit(frame);
        tagEdit->setObjectName(QStringLiteral("tagEdit"));
        tagEdit->setStyleSheet(QStringLiteral("background: white"));

        verticalLayout_2->addWidget(tagEdit);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        addTagButton = new QPushButton(frame);
        addTagButton->setObjectName(QStringLiteral("addTagButton"));
        addTagButton->setFont(font1);
        addTagButton->setStyleSheet(QStringLiteral("background: green;"));

        horizontalLayout_7->addWidget(addTagButton);

        removeTagButton = new QPushButton(frame);
        removeTagButton->setObjectName(QStringLiteral("removeTagButton"));
        removeTagButton->setFont(font1);
        removeTagButton->setStyleSheet(QStringLiteral("background: green;"));

        horizontalLayout_7->addWidget(removeTagButton);


        verticalLayout_2->addLayout(horizontalLayout_7);

        tagError = new QLabel(frame);
        tagError->setObjectName(QStringLiteral("tagError"));
        tagError->setEnabled(true);
        tagError->setFont(font1);
        tagError->setStyleSheet(QStringLiteral("color: red"));

        verticalLayout_2->addWidget(tagError);

        tagList = new QListWidget(frame);
        tagList->setObjectName(QStringLiteral("tagList"));
        tagList->setMaximumSize(QSize(16777215, 200));
        tagList->setStyleSheet(QStringLiteral("background: rgb(232, 232, 232)"));

        verticalLayout_2->addWidget(tagList);

        line_2 = new QFrame(frame);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setLineWidth(5);
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(line_2);

        label_9 = new QLabel(frame);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setFont(font);
        label_9->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_9);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        afterCheckBox = new QCheckBox(frame);
        afterCheckBox->setObjectName(QStringLiteral("afterCheckBox"));
        afterCheckBox->setFont(font1);

        horizontalLayout_8->addWidget(afterCheckBox);

        afterDate = new QDateEdit(frame);
        afterDate->setObjectName(QStringLiteral("afterDate"));
        afterDate->setEnabled(false);
        afterDate->setFont(font1);
        afterDate->setStyleSheet(QStringLiteral("background: white"));
        afterDate->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_8->addWidget(afterDate);


        verticalLayout_2->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        beforeCheckBox = new QCheckBox(frame);
        beforeCheckBox->setObjectName(QStringLiteral("beforeCheckBox"));
        beforeCheckBox->setFont(font1);

        horizontalLayout_9->addWidget(beforeCheckBox);

        beforeDate = new QDateEdit(frame);
        beforeDate->setObjectName(QStringLiteral("beforeDate"));
        beforeDate->setEnabled(false);
        beforeDate->setFont(font1);
        beforeDate->setStyleSheet(QStringLiteral("background: white"));
        beforeDate->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_9->addWidget(beforeDate);


        verticalLayout_2->addLayout(horizontalLayout_9);

        line_3 = new QFrame(frame);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setLineWidth(5);
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(line_3);

        searchButton = new QPushButton(frame);
        searchButton->setObjectName(QStringLiteral("searchButton"));
        searchButton->setFont(font1);
        searchButton->setStyleSheet(QStringLiteral("background: green;"));

        verticalLayout_2->addWidget(searchButton);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        pageViewButton = new QPushButton(frame);
        pageViewButton->setObjectName(QStringLiteral("pageViewButton"));
        pageViewButton->setEnabled(false);

        horizontalLayout_11->addWidget(pageViewButton);

        sheetViewButton = new QPushButton(frame);
        sheetViewButton->setObjectName(QStringLiteral("sheetViewButton"));

        horizontalLayout_11->addWidget(sheetViewButton);


        verticalLayout_2->addLayout(horizontalLayout_11);

        line_5 = new QFrame(frame);
        line_5->setObjectName(QStringLiteral("line_5"));
        line_5->setFrameShape(QFrame::HLine);
        line_5->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(line_5);

        editEntryButton = new QPushButton(frame);
        editEntryButton->setObjectName(QStringLiteral("editEntryButton"));
        editEntryButton->setEnabled(false);
        editEntryButton->setFont(font1);
        editEntryButton->setStyleSheet(QStringLiteral(""));

        verticalLayout_2->addWidget(editEntryButton);

        imageTagLabel = new QLabel(frame);
        imageTagLabel->setObjectName(QStringLiteral("imageTagLabel"));
        imageTagLabel->setEnabled(false);
        imageTagLabel->setFont(font1);
        imageTagLabel->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(imageTagLabel);

        imageTagList = new QListWidget(frame);
        imageTagList->setObjectName(QStringLiteral("imageTagList"));
        imageTagList->setEnabled(false);
        imageTagList->setStyleSheet(QStringLiteral("background: white"));

        verticalLayout_2->addWidget(imageTagList);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        addPhotoButton = new QPushButton(frame);
        addPhotoButton->setObjectName(QStringLiteral("addPhotoButton"));
        addPhotoButton->setFont(font1);
        addPhotoButton->setStyleSheet(QStringLiteral("background: green;"));

        verticalLayout_2->addWidget(addPhotoButton);


        horizontalLayout_3->addWidget(frame);

        stackedWidget->addWidget(view);
        import_2 = new QWidget();
        import_2->setObjectName(QStringLiteral("import_2"));
        horizontalLayout_6 = new QHBoxLayout(import_2);
        horizontalLayout_6->setSpacing(0);
        horizontalLayout_6->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        frame_2 = new QFrame(import_2);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        sizePolicy.setHeightForWidth(frame_2->sizePolicy().hasHeightForWidth());
        frame_2->setSizePolicy(sizePolicy);
        frame_2->setStyleSheet(QStringLiteral("background: silver"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        horizontalLayout_16 = new QHBoxLayout(frame_2);
        horizontalLayout_16->setSpacing(6);
        horizontalLayout_16->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_16->setObjectName(QStringLiteral("horizontalLayout_16"));
        horizontalLayout_16->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(6, 6, 6, 6);
        editFrame = new QFrame(frame_2);
        editFrame->setObjectName(QStringLiteral("editFrame"));
        editFrame->setMinimumSize(QSize(0, 0));
        editFrame->setFrameShape(QFrame::StyledPanel);
        editFrame->setFrameShadow(QFrame::Raised);
        verticalLayout_5 = new QVBoxLayout(editFrame);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        editLabel = new QLabel(editFrame);
        editLabel->setObjectName(QStringLiteral("editLabel"));
        editLabel->setMaximumSize(QSize(200, 25));
        QFont font2;
        font2.setPointSize(14);
        editLabel->setFont(font2);

        verticalLayout_5->addWidget(editLabel);

        editFileLabel = new QLabel(editFrame);
        editFileLabel->setObjectName(QStringLiteral("editFileLabel"));
        editFileLabel->setMaximumSize(QSize(200, 25));
        editFileLabel->setFont(font1);
        editFileLabel->setStyleSheet(QStringLiteral("background: white"));

        verticalLayout_5->addWidget(editFileLabel);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer_3);


        verticalLayout->addWidget(editFrame);

        importButton = new QPushButton(frame_2);
        importButton->setObjectName(QStringLiteral("importButton"));
        importButton->setMaximumSize(QSize(200, 16777215));
        importButton->setFont(font2);
        importButton->setStyleSheet(QStringLiteral("background: green"));

        verticalLayout->addWidget(importButton);

        importQueue = new QListWidget(frame_2);
        importQueue->setObjectName(QStringLiteral("importQueue"));
        importQueue->setMaximumSize(QSize(200, 16777215));
        importQueue->setStyleSheet(QStringLiteral("background: white;"));

        verticalLayout->addWidget(importQueue);

        removeButton = new QPushButton(frame_2);
        removeButton->setObjectName(QStringLiteral("removeButton"));
        removeButton->setFont(font2);
        removeButton->setStyleSheet(QStringLiteral("background: red;"));

        verticalLayout->addWidget(removeButton);


        horizontalLayout_16->addLayout(verticalLayout);

        line_4 = new QFrame(frame_2);
        line_4->setObjectName(QStringLiteral("line_4"));
        line_4->setFrameShape(QFrame::VLine);
        line_4->setFrameShadow(QFrame::Sunken);

        horizontalLayout_16->addWidget(line_4);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(6, 6, 6, 6);
        label = new QLabel(frame_2);
        label->setObjectName(QStringLiteral("label"));
        label->setMaximumSize(QSize(16777215, 25));
        label->setFont(font2);

        verticalLayout_3->addWidget(label);

        importDescription = new QLineEdit(frame_2);
        importDescription->setObjectName(QStringLiteral("importDescription"));
        importDescription->setFont(font2);
        importDescription->setStyleSheet(QStringLiteral("background: white;"));

        verticalLayout_3->addWidget(importDescription);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setSpacing(9);
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        label_3 = new QLabel(frame_2);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMaximumSize(QSize(16777215, 25));
        label_3->setFont(font2);

        verticalLayout_4->addWidget(label_3);

        dateTimeEdit = new QDateTimeEdit(frame_2);
        dateTimeEdit->setObjectName(QStringLiteral("dateTimeEdit"));
        dateTimeEdit->setMaximumSize(QSize(200, 16777215));
        dateTimeEdit->setFont(font2);
        dateTimeEdit->setStyleSheet(QStringLiteral("background: white;"));

        verticalLayout_4->addWidget(dateTimeEdit);

        label_4 = new QLabel(frame_2);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setMaximumSize(QSize(16777215, 25));
        label_4->setFont(font2);

        verticalLayout_4->addWidget(label_4);

        importTagEdit = new QLineEdit(frame_2);
        importTagEdit->setObjectName(QStringLiteral("importTagEdit"));
        importTagEdit->setMaximumSize(QSize(200, 16777215));
        importTagEdit->setFont(font2);
        importTagEdit->setStyleSheet(QStringLiteral("background: white;"));

        verticalLayout_4->addWidget(importTagEdit);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        imporAddTag = new QPushButton(frame_2);
        imporAddTag->setObjectName(QStringLiteral("imporAddTag"));
        imporAddTag->setMaximumSize(QSize(240, 16777215));
        imporAddTag->setFont(font2);
        imporAddTag->setLayoutDirection(Qt::LeftToRight);
        imporAddTag->setStyleSheet(QStringLiteral("background: green"));

        horizontalLayout_12->addWidget(imporAddTag);

        importRemoveTag = new QPushButton(frame_2);
        importRemoveTag->setObjectName(QStringLiteral("importRemoveTag"));
        importRemoveTag->setMaximumSize(QSize(240, 16777215));
        importRemoveTag->setFont(font2);
        importRemoveTag->setStyleSheet(QStringLiteral("background: green"));

        horizontalLayout_12->addWidget(importRemoveTag);


        verticalLayout_4->addLayout(horizontalLayout_12);

        importTagList = new QListWidget(frame_2);
        importTagList->setObjectName(QStringLiteral("importTagList"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(importTagList->sizePolicy().hasHeightForWidth());
        importTagList->setSizePolicy(sizePolicy1);
        importTagList->setMaximumSize(QSize(300, 16777215));
        importTagList->setFont(font2);
        importTagList->setStyleSheet(QStringLiteral("background: white;"));

        verticalLayout_4->addWidget(importTagList);


        horizontalLayout_13->addLayout(verticalLayout_4);

        importImage = new QLabel(frame_2);
        importImage->setObjectName(QStringLiteral("importImage"));
        importImage->setMaximumSize(QSize(16777215, 16777215));
        importImage->setFont(font2);
        importImage->setStyleSheet(QLatin1String("color: white;\n"
"background:black;"));
        importImage->setAlignment(Qt::AlignCenter);

        horizontalLayout_13->addWidget(importImage);

        horizontalLayout_13->setStretch(0, 1);
        horizontalLayout_13->setStretch(1, 2);

        verticalLayout_3->addLayout(horizontalLayout_13);

        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setSpacing(6);
        horizontalLayout_15->setObjectName(QStringLiteral("horizontalLayout_15"));
        saveImportButton = new QPushButton(frame_2);
        saveImportButton->setObjectName(QStringLiteral("saveImportButton"));
        saveImportButton->setFont(font);
        saveImportButton->setStyleSheet(QStringLiteral("background: green;"));

        horizontalLayout_15->addWidget(saveImportButton);

        returnButton = new QPushButton(frame_2);
        returnButton->setObjectName(QStringLiteral("returnButton"));
        returnButton->setFont(font2);
        returnButton->setStyleSheet(QStringLiteral("background: red;"));

        horizontalLayout_15->addWidget(returnButton);


        verticalLayout_3->addLayout(horizontalLayout_15);


        horizontalLayout_16->addLayout(verticalLayout_3);

        horizontalLayout_16->setStretch(0, 1);
        horizontalLayout_16->setStretch(2, 3);

        horizontalLayout_6->addWidget(frame_2);

        stackedWidget->addWidget(import_2);

        horizontalLayout_2->addWidget(stackedWidget);


        horizontalLayout->addWidget(baseFrame);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);
        QObject::connect(afterCheckBox, SIGNAL(clicked(bool)), afterDate, SLOT(setEnabled(bool)));
        QObject::connect(beforeCheckBox, SIGNAL(clicked(bool)), beforeDate, SLOT(setEnabled(bool)));

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        pageBackButton->setText(QApplication::translate("MainWindow", "<-", nullptr));
        pageForwardsButton->setText(QApplication::translate("MainWindow", "->", nullptr));
        totalImagesLabel->setText(QApplication::translate("MainWindow", "/99999", nullptr));
        presentCheckbox->setText(QApplication::translate("MainWindow", "Presentation", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "Seconds delay", nullptr));
        label_8->setText(QApplication::translate("MainWindow", "Tags", nullptr));
        addTagButton->setText(QApplication::translate("MainWindow", "Add Tag", nullptr));
        removeTagButton->setText(QApplication::translate("MainWindow", "Remove Tag", nullptr));
        tagError->setText(QApplication::translate("MainWindow", "No such tag exists", nullptr));
        label_9->setText(QApplication::translate("MainWindow", "Date", nullptr));
        afterCheckBox->setText(QApplication::translate("MainWindow", "After", nullptr));
        beforeCheckBox->setText(QApplication::translate("MainWindow", "Before", nullptr));
        searchButton->setText(QApplication::translate("MainWindow", "Search", nullptr));
        pageViewButton->setText(QApplication::translate("MainWindow", "Page", nullptr));
        sheetViewButton->setText(QApplication::translate("MainWindow", "Sheet", nullptr));
        editEntryButton->setText(QApplication::translate("MainWindow", "Edit Entry", nullptr));
        imageTagLabel->setText(QApplication::translate("MainWindow", "Tags on this image:", nullptr));
        addPhotoButton->setText(QApplication::translate("MainWindow", "Add Photos", nullptr));
        editLabel->setText(QApplication::translate("MainWindow", "Editing Image:", nullptr));
        editFileLabel->setText(QApplication::translate("MainWindow", "TextLabel", nullptr));
        importButton->setText(QApplication::translate("MainWindow", "Import Photos", nullptr));
        removeButton->setText(QApplication::translate("MainWindow", "Remove Selected", nullptr));
        label->setText(QApplication::translate("MainWindow", "Description", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "Date", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "Tags", nullptr));
        imporAddTag->setText(QApplication::translate("MainWindow", "Add Tag", nullptr));
        importRemoveTag->setText(QApplication::translate("MainWindow", "Remove Tag", nullptr));
        importImage->setText(QApplication::translate("MainWindow", "Loading Image...", nullptr));
        saveImportButton->setText(QApplication::translate("MainWindow", "Save", nullptr));
        returnButton->setText(QApplication::translate("MainWindow", "Return to Viewer", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
