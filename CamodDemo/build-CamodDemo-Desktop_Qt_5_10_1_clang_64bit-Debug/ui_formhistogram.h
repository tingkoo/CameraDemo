/********************************************************************************
** Form generated from reading UI file 'formhistogram.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMHISTOGRAM_H
#define UI_FORMHISTOGRAM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormHistogram
{
public:
    QGridLayout *gridLayout;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QComboBox *comboBox;
    QLabel *label;
    QSpinBox *spinBox;
    QComboBox *comboBox_2;
    QLabel *label_2;
    QSpinBox *spinBox_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;

    void setupUi(QWidget *FormHistogram)
    {
        if (FormHistogram->objectName().isEmpty())
            FormHistogram->setObjectName(QStringLiteral("FormHistogram"));
        FormHistogram->resize(245, 222);
        gridLayout = new QGridLayout(FormHistogram);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        groupBox = new QGroupBox(FormHistogram);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(groupBox);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        verticalLayout->addWidget(pushButton_2);


        gridLayout->addWidget(groupBox, 0, 0, 1, 3);

        comboBox = new QComboBox(FormHistogram);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        gridLayout->addWidget(comboBox, 1, 0, 1, 1);

        label = new QLabel(FormHistogram);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 1, 1, 1, 1);

        spinBox = new QSpinBox(FormHistogram);
        spinBox->setObjectName(QStringLiteral("spinBox"));

        gridLayout->addWidget(spinBox, 1, 2, 1, 1);

        comboBox_2 = new QComboBox(FormHistogram);
        comboBox_2->setObjectName(QStringLiteral("comboBox_2"));

        gridLayout->addWidget(comboBox_2, 2, 0, 1, 1);

        label_2 = new QLabel(FormHistogram);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 2, 1, 1, 1);

        spinBox_2 = new QSpinBox(FormHistogram);
        spinBox_2->setObjectName(QStringLiteral("spinBox_2"));

        gridLayout->addWidget(spinBox_2, 2, 2, 1, 1);

        pushButton_3 = new QPushButton(FormHistogram);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        gridLayout->addWidget(pushButton_3, 3, 0, 1, 1);

        pushButton_4 = new QPushButton(FormHistogram);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));

        gridLayout->addWidget(pushButton_4, 3, 1, 1, 2);


        retranslateUi(FormHistogram);

        QMetaObject::connectSlotsByName(FormHistogram);
    } // setupUi

    void retranslateUi(QWidget *FormHistogram)
    {
        FormHistogram->setWindowTitle(QApplication::translate("FormHistogram", "Form", nullptr));
        groupBox->setTitle(QApplication::translate("FormHistogram", "GroupBox", nullptr));
        pushButton->setText(QApplication::translate("FormHistogram", "PushButton", nullptr));
        pushButton_2->setText(QApplication::translate("FormHistogram", "PushButton", nullptr));
        label->setText(QApplication::translate("FormHistogram", "Left", nullptr));
        label_2->setText(QApplication::translate("FormHistogram", "Right", nullptr));
        pushButton_3->setText(QApplication::translate("FormHistogram", "PushButton", nullptr));
        pushButton_4->setText(QApplication::translate("FormHistogram", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FormHistogram: public Ui_FormHistogram {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMHISTOGRAM_H
