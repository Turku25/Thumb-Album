/********************************************************************************
** Form generated from reading UI file 'importprogress.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMPORTPROGRESS_H
#define UI_IMPORTPROGRESS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ImportProgress
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QProgressBar *progressBar;

    void setupUi(QDialog *ImportProgress)
    {
        if (ImportProgress->objectName().isEmpty())
            ImportProgress->setObjectName(QStringLiteral("ImportProgress"));
        ImportProgress->resize(400, 81);
        verticalLayout = new QVBoxLayout(ImportProgress);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(ImportProgress);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        progressBar = new QProgressBar(ImportProgress);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setValue(0);

        verticalLayout->addWidget(progressBar);


        retranslateUi(ImportProgress);

        QMetaObject::connectSlotsByName(ImportProgress);
    } // setupUi

    void retranslateUi(QDialog *ImportProgress)
    {
        ImportProgress->setWindowTitle(QApplication::translate("ImportProgress", "Dialog", nullptr));
        label->setText(QApplication::translate("ImportProgress", "Importing files", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ImportProgress: public Ui_ImportProgress {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMPORTPROGRESS_H
