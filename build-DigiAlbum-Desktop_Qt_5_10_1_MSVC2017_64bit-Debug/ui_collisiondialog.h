/********************************************************************************
** Form generated from reading UI file 'collisiondialog.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COLLISIONDIALOG_H
#define UI_COLLISIONDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_CollisionDialog
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QLabel *imageOne;
    QLabel *imageTwo;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *dupeButton;
    QPushButton *notDupeButton;

    void setupUi(QDialog *CollisionDialog)
    {
        if (CollisionDialog->objectName().isEmpty())
            CollisionDialog->setObjectName(QStringLiteral("CollisionDialog"));
        CollisionDialog->resize(401, 300);
        verticalLayout = new QVBoxLayout(CollisionDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(CollisionDialog);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setPointSize(24);
        label->setFont(font);

        verticalLayout->addWidget(label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        imageOne = new QLabel(CollisionDialog);
        imageOne->setObjectName(QStringLiteral("imageOne"));
        imageOne->setStyleSheet(QStringLiteral("background: rgb(85, 0, 255)"));

        horizontalLayout->addWidget(imageOne);

        imageTwo = new QLabel(CollisionDialog);
        imageTwo->setObjectName(QStringLiteral("imageTwo"));
        imageTwo->setStyleSheet(QStringLiteral("background: rgb(0, 0, 255)"));

        horizontalLayout->addWidget(imageTwo);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        dupeButton = new QPushButton(CollisionDialog);
        dupeButton->setObjectName(QStringLiteral("dupeButton"));
        QFont font1;
        font1.setPointSize(14);
        dupeButton->setFont(font1);

        horizontalLayout_2->addWidget(dupeButton);

        notDupeButton = new QPushButton(CollisionDialog);
        notDupeButton->setObjectName(QStringLiteral("notDupeButton"));
        notDupeButton->setFont(font1);

        horizontalLayout_2->addWidget(notDupeButton);


        verticalLayout->addLayout(horizontalLayout_2);

        verticalLayout->setStretch(1, 1);

        retranslateUi(CollisionDialog);
        QObject::connect(dupeButton, SIGNAL(clicked()), CollisionDialog, SLOT(accept()));
        QObject::connect(notDupeButton, SIGNAL(clicked()), CollisionDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(CollisionDialog);
    } // setupUi

    void retranslateUi(QDialog *CollisionDialog)
    {
        CollisionDialog->setWindowTitle(QApplication::translate("CollisionDialog", "Dialog", nullptr));
        label->setText(QApplication::translate("CollisionDialog", "Possible duplicate pictures!", nullptr));
        imageOne->setText(QApplication::translate("CollisionDialog", "TextLabel", nullptr));
        imageTwo->setText(QApplication::translate("CollisionDialog", "TextLabel", nullptr));
        dupeButton->setText(QApplication::translate("CollisionDialog", "These ARE the \n"
"same picture", nullptr));
        notDupeButton->setText(QApplication::translate("CollisionDialog", "These are NOT the \n"
"same picture", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CollisionDialog: public Ui_CollisionDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COLLISIONDIALOG_H
