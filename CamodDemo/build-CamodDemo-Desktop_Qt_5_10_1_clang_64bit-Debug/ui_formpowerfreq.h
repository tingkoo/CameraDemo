/********************************************************************************
** Form generated from reading UI file 'formpowerfreq.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMPOWERFREQ_H
#define UI_FORMPOWERFREQ_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormPowerFreq
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton_3;
    QLabel *label;

    void setupUi(QWidget *FormPowerFreq)
    {
        if (FormPowerFreq->objectName().isEmpty())
            FormPowerFreq->setObjectName(QStringLiteral("FormPowerFreq"));
        FormPowerFreq->resize(245, 250);
        verticalLayout = new QVBoxLayout(FormPowerFreq);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        groupBox = new QGroupBox(FormPowerFreq);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        radioButton = new QRadioButton(groupBox);
        radioButton->setObjectName(QStringLiteral("radioButton"));

        verticalLayout_2->addWidget(radioButton);

        radioButton_2 = new QRadioButton(groupBox);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));

        verticalLayout_2->addWidget(radioButton_2);

        radioButton_3 = new QRadioButton(groupBox);
        radioButton_3->setObjectName(QStringLiteral("radioButton_3"));

        verticalLayout_2->addWidget(radioButton_3);


        verticalLayout->addWidget(groupBox);

        label = new QLabel(FormPowerFreq);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(231, 0));
        label->setWordWrap(true);

        verticalLayout->addWidget(label);


        retranslateUi(FormPowerFreq);

        QMetaObject::connectSlotsByName(FormPowerFreq);
    } // setupUi

    void retranslateUi(QWidget *FormPowerFreq)
    {
        FormPowerFreq->setWindowTitle(QApplication::translate("FormPowerFreq", "Form", nullptr));
        groupBox->setTitle(QString());
        radioButton->setText(QApplication::translate("FormPowerFreq", "AC (50 Hz)", nullptr));
        radioButton_2->setText(QApplication::translate("FormPowerFreq", "AC (60 Hz)", nullptr));
        radioButton_3->setText(QApplication::translate("FormPowerFreq", "DC", nullptr));
        label->setText(QApplication::translate("FormPowerFreq", "Anti-flicked function is only available for cameras with rolling shutter detector ( most of cmos sensors) and auto exposure mode must be disabled. Enable this function will make only some certain exposure time values avaiable which depend on the power frequency this is selected.", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FormPowerFreq: public Ui_FormPowerFreq {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMPOWERFREQ_H
