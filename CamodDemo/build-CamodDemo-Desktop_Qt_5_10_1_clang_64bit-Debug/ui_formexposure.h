/********************************************************************************
** Form generated from reading UI file 'formexposure.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMEXPOSURE_H
#define UI_FORMEXPOSURE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormExposure
{
public:
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *comboBox;
    QSlider *horizontalSlider;
    QTabWidget *tabWidget;
    QWidget *tab;
    QVBoxLayout *verticalLayout_4;
    QCheckBox *checkBox;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QComboBox *comboBox_2;
    QSlider *horizontalSlider_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QComboBox *comboBox_3;
    QSlider *horizontalSlider_3;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout;
    QLabel *label_4;
    QComboBox *comboBox_4;
    QLabel *label_6;
    QComboBox *comboBox_6;
    QLabel *label_5;
    QComboBox *comboBox_5;
    QLabel *label_7;
    QComboBox *comboBox_7;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_8;
    QComboBox *comboBox_8;
    QLabel *label_9;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_10;
    QSpinBox *spinBox;
    QLabel *label_11;
    QSpinBox *spinBox_2;
    QLabel *label_12;
    QSpinBox *spinBox_3;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_13;
    QSpinBox *spinBox_4;
    QLabel *label_14;
    QSpinBox *spinBox_5;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QWidget *FormExposure)
    {
        if (FormExposure->objectName().isEmpty())
            FormExposure->setObjectName(QStringLiteral("FormExposure"));
        FormExposure->resize(391, 430);
        verticalLayout_2 = new QVBoxLayout(FormExposure);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        groupBox = new QGroupBox(FormExposure);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        comboBox = new QComboBox(groupBox);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        horizontalLayout->addWidget(comboBox);


        verticalLayout->addLayout(horizontalLayout);

        horizontalSlider = new QSlider(groupBox);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setOrientation(Qt::Horizontal);

        verticalLayout->addWidget(horizontalSlider);


        verticalLayout_2->addWidget(groupBox);

        tabWidget = new QTabWidget(FormExposure);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        verticalLayout_4 = new QVBoxLayout(tab);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        checkBox = new QCheckBox(tab);
        checkBox->setObjectName(QStringLiteral("checkBox"));

        verticalLayout_4->addWidget(checkBox);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(tab);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        comboBox_2 = new QComboBox(tab);
        comboBox_2->setObjectName(QStringLiteral("comboBox_2"));

        horizontalLayout_2->addWidget(comboBox_2);


        verticalLayout_4->addLayout(horizontalLayout_2);

        horizontalSlider_2 = new QSlider(tab);
        horizontalSlider_2->setObjectName(QStringLiteral("horizontalSlider_2"));
        horizontalSlider_2->setOrientation(Qt::Horizontal);

        verticalLayout_4->addWidget(horizontalSlider_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_3 = new QLabel(tab);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_3->addWidget(label_3);

        comboBox_3 = new QComboBox(tab);
        comboBox_3->setObjectName(QStringLiteral("comboBox_3"));

        horizontalLayout_3->addWidget(comboBox_3);


        verticalLayout_4->addLayout(horizontalLayout_3);

        horizontalSlider_3 = new QSlider(tab);
        horizontalSlider_3->setObjectName(QStringLiteral("horizontalSlider_3"));
        horizontalSlider_3->setOrientation(Qt::Horizontal);

        verticalLayout_4->addWidget(horizontalSlider_3);

        groupBox_2 = new QGroupBox(tab);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setFlat(false);
        groupBox_2->setCheckable(false);
        gridLayout = new QGridLayout(groupBox_2);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(8, 8, 8, 8);
        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 0, 0, 1, 1);

        comboBox_4 = new QComboBox(groupBox_2);
        comboBox_4->setObjectName(QStringLiteral("comboBox_4"));

        gridLayout->addWidget(comboBox_4, 0, 1, 1, 1);

        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout->addWidget(label_6, 0, 2, 1, 1);

        comboBox_6 = new QComboBox(groupBox_2);
        comboBox_6->setObjectName(QStringLiteral("comboBox_6"));

        gridLayout->addWidget(comboBox_6, 0, 3, 1, 1);

        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout->addWidget(label_5, 1, 0, 1, 1);

        comboBox_5 = new QComboBox(groupBox_2);
        comboBox_5->setObjectName(QStringLiteral("comboBox_5"));

        gridLayout->addWidget(comboBox_5, 1, 1, 1, 1);

        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout->addWidget(label_7, 1, 2, 1, 1);

        comboBox_7 = new QComboBox(groupBox_2);
        comboBox_7->setObjectName(QStringLiteral("comboBox_7"));

        gridLayout->addWidget(comboBox_7, 1, 3, 1, 1);


        verticalLayout_4->addWidget(groupBox_2);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        verticalLayout_3 = new QVBoxLayout(tab_2);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_8 = new QLabel(tab_2);
        label_8->setObjectName(QStringLiteral("label_8"));

        horizontalLayout_4->addWidget(label_8);

        comboBox_8 = new QComboBox(tab_2);
        comboBox_8->setObjectName(QStringLiteral("comboBox_8"));

        horizontalLayout_4->addWidget(comboBox_8);


        verticalLayout_3->addLayout(horizontalLayout_4);

        label_9 = new QLabel(tab_2);
        label_9->setObjectName(QStringLiteral("label_9"));

        verticalLayout_3->addWidget(label_9);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_10 = new QLabel(tab_2);
        label_10->setObjectName(QStringLiteral("label_10"));

        horizontalLayout_5->addWidget(label_10);

        spinBox = new QSpinBox(tab_2);
        spinBox->setObjectName(QStringLiteral("spinBox"));

        horizontalLayout_5->addWidget(spinBox);

        label_11 = new QLabel(tab_2);
        label_11->setObjectName(QStringLiteral("label_11"));

        horizontalLayout_5->addWidget(label_11);

        spinBox_2 = new QSpinBox(tab_2);
        spinBox_2->setObjectName(QStringLiteral("spinBox_2"));

        horizontalLayout_5->addWidget(spinBox_2);

        label_12 = new QLabel(tab_2);
        label_12->setObjectName(QStringLiteral("label_12"));

        horizontalLayout_5->addWidget(label_12);

        spinBox_3 = new QSpinBox(tab_2);
        spinBox_3->setObjectName(QStringLiteral("spinBox_3"));

        horizontalLayout_5->addWidget(spinBox_3);


        verticalLayout_3->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_13 = new QLabel(tab_2);
        label_13->setObjectName(QStringLiteral("label_13"));

        horizontalLayout_6->addWidget(label_13);

        spinBox_4 = new QSpinBox(tab_2);
        spinBox_4->setObjectName(QStringLiteral("spinBox_4"));

        horizontalLayout_6->addWidget(spinBox_4);

        label_14 = new QLabel(tab_2);
        label_14->setObjectName(QStringLiteral("label_14"));

        horizontalLayout_6->addWidget(label_14);

        spinBox_5 = new QSpinBox(tab_2);
        spinBox_5->setObjectName(QStringLiteral("spinBox_5"));

        horizontalLayout_6->addWidget(spinBox_5);


        verticalLayout_3->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        pushButton = new QPushButton(tab_2);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout_7->addWidget(pushButton);

        pushButton_2 = new QPushButton(tab_2);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        horizontalLayout_7->addWidget(pushButton_2);


        verticalLayout_3->addLayout(horizontalLayout_7);

        tabWidget->addTab(tab_2, QString());

        verticalLayout_2->addWidget(tabWidget);


        retranslateUi(FormExposure);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(FormExposure);
    } // setupUi

    void retranslateUi(QWidget *FormExposure)
    {
        FormExposure->setWindowTitle(QApplication::translate("FormExposure", "Form", nullptr));
        groupBox->setTitle(QString());
        label->setText(QApplication::translate("FormExposure", "Gain", nullptr));
        checkBox->setText(QApplication::translate("FormExposure", "CheckBox", nullptr));
        label_2->setText(QApplication::translate("FormExposure", "Exposure Target", nullptr));
        label_3->setText(QApplication::translate("FormExposure", "Exposure Time", nullptr));
        groupBox_2->setTitle(QString());
        label_4->setText(QApplication::translate("FormExposure", "X", nullptr));
        label_6->setText(QApplication::translate("FormExposure", "Y", nullptr));
        label_5->setText(QApplication::translate("FormExposure", "Width", nullptr));
        label_7->setText(QApplication::translate("FormExposure", "Height", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("FormExposure", "Video Mode", nullptr));
        label_8->setText(QApplication::translate("FormExposure", "Trigger Sources", nullptr));
        label_9->setText(QApplication::translate("FormExposure", "Exposure TIme", nullptr));
        label_10->setText(QApplication::translate("FormExposure", "h", nullptr));
        label_11->setText(QApplication::translate("FormExposure", "m", nullptr));
        label_12->setText(QApplication::translate("FormExposure", "s", nullptr));
        label_13->setText(QApplication::translate("FormExposure", "ms", nullptr));
        label_14->setText(QApplication::translate("FormExposure", "\316\274s", nullptr));
        pushButton->setText(QApplication::translate("FormExposure", "Single", nullptr));
        pushButton_2->setText(QApplication::translate("FormExposure", "Loop", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("FormExposure", "Trigger Mode", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FormExposure: public Ui_FormExposure {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMEXPOSURE_H
