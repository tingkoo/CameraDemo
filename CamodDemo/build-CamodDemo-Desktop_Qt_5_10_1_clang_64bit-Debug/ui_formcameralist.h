/********************************************************************************
** Form generated from reading UI file 'formcameralist.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMCAMERALIST_H
#define UI_FORMCAMERALIST_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormCameraList
{
public:
    QGridLayout *gridLayout;
    QPushButton *playBtn;
    QPushButton *pauseBtn;
    QLabel *label;

    void setupUi(QWidget *FormCameraList)
    {
        if (FormCameraList->objectName().isEmpty())
            FormCameraList->setObjectName(QStringLiteral("FormCameraList"));
        FormCameraList->resize(245, 80);
        gridLayout = new QGridLayout(FormCameraList);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        playBtn = new QPushButton(FormCameraList);
        playBtn->setObjectName(QStringLiteral("playBtn"));

        gridLayout->addWidget(playBtn, 1, 0, 1, 1);

        pauseBtn = new QPushButton(FormCameraList);
        pauseBtn->setObjectName(QStringLiteral("pauseBtn"));

        gridLayout->addWidget(pauseBtn, 1, 1, 1, 1);

        label = new QLabel(FormCameraList);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 2);


        retranslateUi(FormCameraList);

        QMetaObject::connectSlotsByName(FormCameraList);
    } // setupUi

    void retranslateUi(QWidget *FormCameraList)
    {
        FormCameraList->setWindowTitle(QApplication::translate("FormCameraList", "Form", nullptr));
        playBtn->setText(QApplication::translate("FormCameraList", "Play", nullptr));
        pauseBtn->setText(QApplication::translate("FormCameraList", "Pause", nullptr));
        label->setText(QApplication::translate("FormCameraList", "No Device", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FormCameraList: public Ui_FormCameraList {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMCAMERALIST_H
