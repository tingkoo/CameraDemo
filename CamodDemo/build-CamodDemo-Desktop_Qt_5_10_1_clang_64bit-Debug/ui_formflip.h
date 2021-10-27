/********************************************************************************
** Form generated from reading UI file 'formflip.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMFLIP_H
#define UI_FORMFLIP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormFlip
{
public:
    QVBoxLayout *verticalLayout;
    QCheckBox *checkBox;
    QCheckBox *checkBox_2;

    void setupUi(QWidget *FormFlip)
    {
        if (FormFlip->objectName().isEmpty())
            FormFlip->setObjectName(QStringLiteral("FormFlip"));
        FormFlip->resize(245, 100);
        verticalLayout = new QVBoxLayout(FormFlip);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        checkBox = new QCheckBox(FormFlip);
        checkBox->setObjectName(QStringLiteral("checkBox"));

        verticalLayout->addWidget(checkBox);

        checkBox_2 = new QCheckBox(FormFlip);
        checkBox_2->setObjectName(QStringLiteral("checkBox_2"));

        verticalLayout->addWidget(checkBox_2);


        retranslateUi(FormFlip);

        QMetaObject::connectSlotsByName(FormFlip);
    } // setupUi

    void retranslateUi(QWidget *FormFlip)
    {
        FormFlip->setWindowTitle(QApplication::translate("FormFlip", "Form", nullptr));
        checkBox->setText(QApplication::translate("FormFlip", "Horizontal", nullptr));
        checkBox_2->setText(QApplication::translate("FormFlip", "Vertical", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FormFlip: public Ui_FormFlip {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMFLIP_H
