/********************************************************************************
** Form generated from reading UI file 'formcooling.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMCOOLING_H
#define UI_FORMCOOLING_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormCooling
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QLabel *label;
    QSpinBox *spinBox;
    QPushButton *pushButton;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QSpacerItem *horizontalSpacer;
    QLabel *label_3;
    QSlider *horizontalSlider;
    QLabel *label_4;
    QGroupBox *groupBox_3;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;

    void setupUi(QWidget *FormCooling)
    {
        if (FormCooling->objectName().isEmpty())
            FormCooling->setObjectName(QStringLiteral("FormCooling"));
        FormCooling->resize(245, 320);
        verticalLayout = new QVBoxLayout(FormCooling);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        groupBox = new QGroupBox(FormCooling);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        radioButton = new QRadioButton(groupBox);
        radioButton->setObjectName(QStringLiteral("radioButton"));

        gridLayout->addWidget(radioButton, 0, 0, 1, 1);

        radioButton_2 = new QRadioButton(groupBox);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));

        gridLayout->addWidget(radioButton_2, 0, 1, 1, 1);

        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 1, 0, 1, 1);

        spinBox = new QSpinBox(groupBox);
        spinBox->setObjectName(QStringLiteral("spinBox"));

        gridLayout->addWidget(spinBox, 1, 1, 1, 1);

        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        gridLayout->addWidget(pushButton, 2, 0, 1, 2);


        verticalLayout->addWidget(groupBox);

        groupBox_2 = new QGroupBox(FormCooling);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        horizontalSpacer = new QSpacerItem(121, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 0, 1, 1, 1);

        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout_2->addWidget(label_3, 0, 0, 1, 1);

        horizontalSlider = new QSlider(groupBox_2);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setPageStep(1);
        horizontalSlider->setOrientation(Qt::Horizontal);
        horizontalSlider->setTickPosition(QSlider::TicksAbove);

        gridLayout_2->addWidget(horizontalSlider, 1, 0, 1, 3);

        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout_2->addWidget(label_4, 0, 2, 1, 1);


        verticalLayout->addWidget(groupBox_2);

        groupBox_3 = new QGroupBox(FormCooling);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        horizontalLayout = new QHBoxLayout(groupBox_3);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_2 = new QLabel(groupBox_3);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout->addWidget(label_2);


        verticalLayout->addWidget(groupBox_3);


        retranslateUi(FormCooling);

        QMetaObject::connectSlotsByName(FormCooling);
    } // setupUi

    void retranslateUi(QWidget *FormCooling)
    {
        FormCooling->setWindowTitle(QApplication::translate("FormCooling", "Form", nullptr));
        groupBox->setTitle(QApplication::translate("FormCooling", "TEC", nullptr));
        radioButton->setText(QApplication::translate("FormCooling", "On", nullptr));
        radioButton_2->setText(QApplication::translate("FormCooling", "Off", nullptr));
        label->setText(QApplication::translate("FormCooling", "Target Terr", nullptr));
        pushButton->setText(QApplication::translate("FormCooling", "Apply", nullptr));
        groupBox_2->setTitle(QApplication::translate("FormCooling", "Fan", nullptr));
        label_3->setText(QApplication::translate("FormCooling", "Off", nullptr));
        label_4->setText(QApplication::translate("FormCooling", "High", nullptr));
        groupBox_3->setTitle(QApplication::translate("FormCooling", "Current Temperature (C):", nullptr));
        label_2->setText(QApplication::translate("FormCooling", "N/A", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FormCooling: public Ui_FormCooling {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMCOOLING_H
