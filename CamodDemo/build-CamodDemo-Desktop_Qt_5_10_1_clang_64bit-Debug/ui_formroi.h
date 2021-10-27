/********************************************************************************
** Form generated from reading UI file 'formroi.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMROI_H
#define UI_FORMROI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormRoi
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QSpinBox *spinBox;
    QLabel *label_5;
    QSpinBox *spinBox_3;
    QLabel *label_4;
    QSpinBox *spinBox_2;
    QLabel *label_6;
    QSpinBox *spinBox_4;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QWidget *FormRoi)
    {
        if (FormRoi->objectName().isEmpty())
            FormRoi->setObjectName(QStringLiteral("FormRoi"));
        FormRoi->resize(245, 150);
        gridLayout = new QGridLayout(FormRoi);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(FormRoi);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        spinBox = new QSpinBox(FormRoi);
        spinBox->setObjectName(QStringLiteral("spinBox"));

        gridLayout->addWidget(spinBox, 0, 1, 1, 1);

        label_5 = new QLabel(FormRoi);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout->addWidget(label_5, 0, 2, 1, 1);

        spinBox_3 = new QSpinBox(FormRoi);
        spinBox_3->setObjectName(QStringLiteral("spinBox_3"));

        gridLayout->addWidget(spinBox_3, 0, 3, 1, 1);

        label_4 = new QLabel(FormRoi);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 1, 0, 1, 1);

        spinBox_2 = new QSpinBox(FormRoi);
        spinBox_2->setObjectName(QStringLiteral("spinBox_2"));

        gridLayout->addWidget(spinBox_2, 1, 1, 1, 1);

        label_6 = new QLabel(FormRoi);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout->addWidget(label_6, 1, 2, 1, 1);

        spinBox_4 = new QSpinBox(FormRoi);
        spinBox_4->setObjectName(QStringLiteral("spinBox_4"));

        gridLayout->addWidget(spinBox_4, 1, 3, 1, 1);

        pushButton = new QPushButton(FormRoi);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        gridLayout->addWidget(pushButton, 2, 0, 1, 2);

        pushButton_2 = new QPushButton(FormRoi);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        gridLayout->addWidget(pushButton_2, 2, 2, 1, 2);


        retranslateUi(FormRoi);

        QMetaObject::connectSlotsByName(FormRoi);
    } // setupUi

    void retranslateUi(QWidget *FormRoi)
    {
        FormRoi->setWindowTitle(QApplication::translate("FormRoi", "Form", nullptr));
        label->setText(QApplication::translate("FormRoi", "X", nullptr));
        label_5->setText(QApplication::translate("FormRoi", "Y", nullptr));
        label_4->setText(QApplication::translate("FormRoi", "Width", nullptr));
        label_6->setText(QApplication::translate("FormRoi", "Height", nullptr));
        pushButton->setText(QApplication::translate("FormRoi", "Apply", nullptr));
        pushButton_2->setText(QApplication::translate("FormRoi", "Defaults", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FormRoi: public Ui_FormRoi {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMROI_H
