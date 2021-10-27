/********************************************************************************
** Form generated from reading UI file 'formbitdepth.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMBITDEPTH_H
#define UI_FORMBITDEPTH_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormBitDepth
{
public:
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;

    void setupUi(QWidget *FormBitDepth)
    {
        if (FormBitDepth->objectName().isEmpty())
            FormBitDepth->setObjectName(QStringLiteral("FormBitDepth"));
        FormBitDepth->resize(245, 98);
        verticalLayout_2 = new QVBoxLayout(FormBitDepth);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        groupBox = new QGroupBox(FormBitDepth);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        radioButton = new QRadioButton(groupBox);
        radioButton->setObjectName(QStringLiteral("radioButton"));

        verticalLayout->addWidget(radioButton);

        radioButton_2 = new QRadioButton(groupBox);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));

        verticalLayout->addWidget(radioButton_2);


        verticalLayout_2->addWidget(groupBox);


        retranslateUi(FormBitDepth);

        QMetaObject::connectSlotsByName(FormBitDepth);
    } // setupUi

    void retranslateUi(QWidget *FormBitDepth)
    {
        FormBitDepth->setWindowTitle(QApplication::translate("FormBitDepth", "Form", nullptr));
        groupBox->setTitle(QString());
        radioButton->setText(QApplication::translate("FormBitDepth", "8 Bits", nullptr));
        radioButton_2->setText(QApplication::translate("FormBitDepth", "14 Bits", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FormBitDepth: public Ui_FormBitDepth {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMBITDEPTH_H
