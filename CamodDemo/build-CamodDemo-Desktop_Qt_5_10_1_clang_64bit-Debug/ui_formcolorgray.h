/********************************************************************************
** Form generated from reading UI file 'formcolorgray.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMCOLORGRAY_H
#define UI_FORMCOLORGRAY_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormColorGray
{
public:
    QVBoxLayout *verticalLayout;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton_3;

    void setupUi(QWidget *FormColorGray)
    {
        if (FormColorGray->objectName().isEmpty())
            FormColorGray->setObjectName(QStringLiteral("FormColorGray"));
        FormColorGray->resize(245, 100);
        verticalLayout = new QVBoxLayout(FormColorGray);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        radioButton = new QRadioButton(FormColorGray);
        radioButton->setObjectName(QStringLiteral("radioButton"));

        verticalLayout->addWidget(radioButton);

        radioButton_2 = new QRadioButton(FormColorGray);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));

        verticalLayout->addWidget(radioButton_2);

        radioButton_3 = new QRadioButton(FormColorGray);
        radioButton_3->setObjectName(QStringLiteral("radioButton_3"));

        verticalLayout->addWidget(radioButton_3);


        retranslateUi(FormColorGray);

        QMetaObject::connectSlotsByName(FormColorGray);
    } // setupUi

    void retranslateUi(QWidget *FormColorGray)
    {
        FormColorGray->setWindowTitle(QApplication::translate("FormColorGray", "Form", nullptr));
        radioButton->setText(QApplication::translate("FormColorGray", "Color", nullptr));
        radioButton_2->setText(QApplication::translate("FormColorGray", "Gray", nullptr));
        radioButton_3->setText(QApplication::translate("FormColorGray", "Negative", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FormColorGray: public Ui_FormColorGray {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMCOLORGRAY_H
