/********************************************************************************
** Form generated from reading UI file 'formsampling.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMSAMPLING_H
#define UI_FORMSAMPLING_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormSampling
{
public:
    QVBoxLayout *verticalLayout;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;

    void setupUi(QWidget *FormSampling)
    {
        if (FormSampling->objectName().isEmpty())
            FormSampling->setObjectName(QStringLiteral("FormSampling"));
        FormSampling->resize(245, 100);
        verticalLayout = new QVBoxLayout(FormSampling);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        radioButton = new QRadioButton(FormSampling);
        radioButton->setObjectName(QStringLiteral("radioButton"));

        verticalLayout->addWidget(radioButton);

        radioButton_2 = new QRadioButton(FormSampling);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));

        verticalLayout->addWidget(radioButton_2);


        retranslateUi(FormSampling);

        QMetaObject::connectSlotsByName(FormSampling);
    } // setupUi

    void retranslateUi(QWidget *FormSampling)
    {
        FormSampling->setWindowTitle(QApplication::translate("FormSampling", "Form", nullptr));
        radioButton->setText(QApplication::translate("FormSampling", "Bin", nullptr));
        radioButton_2->setText(QApplication::translate("FormSampling", "Skip", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FormSampling: public Ui_FormSampling {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMSAMPLING_H
