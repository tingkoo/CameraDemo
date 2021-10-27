/********************************************************************************
** Form generated from reading UI file 'formcapresolution.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMCAPRESOLUTION_H
#define UI_FORMCAPRESOLUTION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormCapResolution
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *labelLive;
    QComboBox *comboBox;
    QLabel *labelSnap;
    QComboBox *comboBox_2;
    QLabel *labelFormat;
    QComboBox *comboBox_3;
    QHBoxLayout *horizontalLayout;
    QCheckBox *checkBox;
    QPushButton *pushButton;

    void setupUi(QWidget *FormCapResolution)
    {
        if (FormCapResolution->objectName().isEmpty())
            FormCapResolution->setObjectName(QStringLiteral("FormCapResolution"));
        FormCapResolution->resize(245, 171);
        verticalLayout = new QVBoxLayout(FormCapResolution);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        labelLive = new QLabel(FormCapResolution);
        labelLive->setObjectName(QStringLiteral("labelLive"));

        gridLayout->addWidget(labelLive, 0, 0, 1, 1);

        comboBox = new QComboBox(FormCapResolution);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        gridLayout->addWidget(comboBox, 0, 1, 1, 1);

        labelSnap = new QLabel(FormCapResolution);
        labelSnap->setObjectName(QStringLiteral("labelSnap"));

        gridLayout->addWidget(labelSnap, 1, 0, 1, 1);

        comboBox_2 = new QComboBox(FormCapResolution);
        comboBox_2->setObjectName(QStringLiteral("comboBox_2"));

        gridLayout->addWidget(comboBox_2, 1, 1, 1, 1);

        labelFormat = new QLabel(FormCapResolution);
        labelFormat->setObjectName(QStringLiteral("labelFormat"));

        gridLayout->addWidget(labelFormat, 2, 0, 1, 1);

        comboBox_3 = new QComboBox(FormCapResolution);
        comboBox_3->setObjectName(QStringLiteral("comboBox_3"));

        gridLayout->addWidget(comboBox_3, 2, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        checkBox = new QCheckBox(FormCapResolution);
        checkBox->setObjectName(QStringLiteral("checkBox"));

        horizontalLayout->addWidget(checkBox);

        pushButton = new QPushButton(FormCapResolution);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout->addWidget(pushButton);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(FormCapResolution);

        QMetaObject::connectSlotsByName(FormCapResolution);
    } // setupUi

    void retranslateUi(QWidget *FormCapResolution)
    {
        FormCapResolution->setWindowTitle(QApplication::translate("FormCapResolution", "Form", nullptr));
        labelLive->setText(QApplication::translate("FormCapResolution", "Live", nullptr));
        labelSnap->setText(QApplication::translate("FormCapResolution", "Snap", nullptr));
        labelFormat->setText(QApplication::translate("FormCapResolution", "Format", nullptr));
        checkBox->setText(QApplication::translate("FormCapResolution", "Record", nullptr));
        pushButton->setText(QApplication::translate("FormCapResolution", "Snap", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FormCapResolution: public Ui_FormCapResolution {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMCAPRESOLUTION_H
