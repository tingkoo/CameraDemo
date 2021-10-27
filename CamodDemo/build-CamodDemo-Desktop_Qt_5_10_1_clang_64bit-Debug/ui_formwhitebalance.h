/********************************************************************************
** Form generated from reading UI file 'formwhitebalance.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMWHITEBALANCE_H
#define UI_FORMWHITEBALANCE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormWhiteBalance
{
public:
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *labelColorTemp;
    QSpinBox *spinBoxColorTemp;
    QSlider *horizontalSliderColorTemp;
    QHBoxLayout *horizontalLayout_3;
    QLabel *labelTint;
    QSpinBox *spinBoxTint;
    QSlider *horizontalSliderTint;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLabel *label_3;
    QLabel *labelX;
    QSpinBox *spinBoxX;
    QLabel *labelY;
    QSpinBox *spinBoxY;
    QLabel *labelWidth;
    QSpinBox *spinBoxWidth;
    QLabel *labelHeight;
    QSpinBox *spinBoxHeight;
    QHBoxLayout *horizontalLayout;
    QCheckBox *checkBoxAuto;
    QPushButton *onepushBtn;
    QPushButton *DefaultsBtn;

    void setupUi(QWidget *FormWhiteBalance)
    {
        if (FormWhiteBalance->objectName().isEmpty())
            FormWhiteBalance->setObjectName(QStringLiteral("FormWhiteBalance"));
        FormWhiteBalance->resize(280, 400);
        gridLayout_2 = new QGridLayout(FormWhiteBalance);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        labelColorTemp = new QLabel(FormWhiteBalance);
        labelColorTemp->setObjectName(QStringLiteral("labelColorTemp"));

        horizontalLayout_2->addWidget(labelColorTemp);

        spinBoxColorTemp = new QSpinBox(FormWhiteBalance);
        spinBoxColorTemp->setObjectName(QStringLiteral("spinBoxColorTemp"));

        horizontalLayout_2->addWidget(spinBoxColorTemp);


        gridLayout_2->addLayout(horizontalLayout_2, 0, 0, 1, 1);

        horizontalSliderColorTemp = new QSlider(FormWhiteBalance);
        horizontalSliderColorTemp->setObjectName(QStringLiteral("horizontalSliderColorTemp"));
        horizontalSliderColorTemp->setOrientation(Qt::Horizontal);

        gridLayout_2->addWidget(horizontalSliderColorTemp, 1, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        labelTint = new QLabel(FormWhiteBalance);
        labelTint->setObjectName(QStringLiteral("labelTint"));

        horizontalLayout_3->addWidget(labelTint);

        spinBoxTint = new QSpinBox(FormWhiteBalance);
        spinBoxTint->setObjectName(QStringLiteral("spinBoxTint"));

        horizontalLayout_3->addWidget(spinBoxTint);


        gridLayout_2->addLayout(horizontalLayout_3, 2, 0, 1, 1);

        horizontalSliderTint = new QSlider(FormWhiteBalance);
        horizontalSliderTint->setObjectName(QStringLiteral("horizontalSliderTint"));
        horizontalSliderTint->setOrientation(Qt::Horizontal);

        gridLayout_2->addWidget(horizontalSliderTint, 3, 0, 1, 1);

        groupBox = new QGroupBox(FormWhiteBalance);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMinimumSize(QSize(0, 80));
        label_3->setWordWrap(true);

        gridLayout->addWidget(label_3, 0, 0, 1, 4);

        labelX = new QLabel(groupBox);
        labelX->setObjectName(QStringLiteral("labelX"));

        gridLayout->addWidget(labelX, 1, 0, 1, 1);

        spinBoxX = new QSpinBox(groupBox);
        spinBoxX->setObjectName(QStringLiteral("spinBoxX"));

        gridLayout->addWidget(spinBoxX, 1, 1, 1, 1);

        labelY = new QLabel(groupBox);
        labelY->setObjectName(QStringLiteral("labelY"));

        gridLayout->addWidget(labelY, 1, 2, 1, 1);

        spinBoxY = new QSpinBox(groupBox);
        spinBoxY->setObjectName(QStringLiteral("spinBoxY"));

        gridLayout->addWidget(spinBoxY, 1, 3, 1, 1);

        labelWidth = new QLabel(groupBox);
        labelWidth->setObjectName(QStringLiteral("labelWidth"));

        gridLayout->addWidget(labelWidth, 2, 0, 1, 1);

        spinBoxWidth = new QSpinBox(groupBox);
        spinBoxWidth->setObjectName(QStringLiteral("spinBoxWidth"));

        gridLayout->addWidget(spinBoxWidth, 2, 1, 1, 1);

        labelHeight = new QLabel(groupBox);
        labelHeight->setObjectName(QStringLiteral("labelHeight"));

        gridLayout->addWidget(labelHeight, 2, 2, 1, 1);

        spinBoxHeight = new QSpinBox(groupBox);
        spinBoxHeight->setObjectName(QStringLiteral("spinBoxHeight"));

        gridLayout->addWidget(spinBoxHeight, 2, 3, 1, 1);


        gridLayout_2->addWidget(groupBox, 4, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        checkBoxAuto = new QCheckBox(FormWhiteBalance);
        checkBoxAuto->setObjectName(QStringLiteral("checkBoxAuto"));

        horizontalLayout->addWidget(checkBoxAuto);

        onepushBtn = new QPushButton(FormWhiteBalance);
        onepushBtn->setObjectName(QStringLiteral("onepushBtn"));

        horizontalLayout->addWidget(onepushBtn);

        DefaultsBtn = new QPushButton(FormWhiteBalance);
        DefaultsBtn->setObjectName(QStringLiteral("DefaultsBtn"));

        horizontalLayout->addWidget(DefaultsBtn);


        gridLayout_2->addLayout(horizontalLayout, 5, 0, 1, 1);


        retranslateUi(FormWhiteBalance);

        QMetaObject::connectSlotsByName(FormWhiteBalance);
    } // setupUi

    void retranslateUi(QWidget *FormWhiteBalance)
    {
        FormWhiteBalance->setWindowTitle(QApplication::translate("FormWhiteBalance", "Form", nullptr));
        labelColorTemp->setText(QApplication::translate("FormWhiteBalance", "Color Temperature", nullptr));
        labelTint->setText(QApplication::translate("FormWhiteBalance", "Tint", nullptr));
        groupBox->setTitle(QString());
        label_3->setText(QApplication::translate("FormWhiteBalance", "Move the ROI (Marked by a red rectangle) to a pure white or gray object and click \" White Balance\" to establish the white balance for future video", nullptr));
        labelX->setText(QApplication::translate("FormWhiteBalance", "X", nullptr));
        labelY->setText(QApplication::translate("FormWhiteBalance", "Y", nullptr));
        labelWidth->setText(QApplication::translate("FormWhiteBalance", "Width", nullptr));
        labelHeight->setText(QApplication::translate("FormWhiteBalance", "Height", nullptr));
        checkBoxAuto->setText(QApplication::translate("FormWhiteBalance", "Auto", nullptr));
        onepushBtn->setText(QApplication::translate("FormWhiteBalance", "One Push", nullptr));
        DefaultsBtn->setText(QApplication::translate("FormWhiteBalance", "Defaults", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FormWhiteBalance: public Ui_FormWhiteBalance {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMWHITEBALANCE_H
