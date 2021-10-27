/********************************************************************************
** Form generated from reading UI file 'formflusyn.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMFLUSYN_H
#define UI_FORMFLUSYN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormFluSyn
{
public:
    QGridLayout *gridLayout;
    QTextEdit *textEdit;
    QCheckBox *checkBox;
    QPushButton *pushButton;

    void setupUi(QWidget *FormFluSyn)
    {
        if (FormFluSyn->objectName().isEmpty())
            FormFluSyn->setObjectName(QStringLiteral("FormFluSyn"));
        FormFluSyn->resize(800, 500);
        gridLayout = new QGridLayout(FormFluSyn);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        textEdit = new QTextEdit(FormFluSyn);
        textEdit->setObjectName(QStringLiteral("textEdit"));

        gridLayout->addWidget(textEdit, 0, 0, 1, 1);

        checkBox = new QCheckBox(FormFluSyn);
        checkBox->setObjectName(QStringLiteral("checkBox"));

        gridLayout->addWidget(checkBox, 1, 0, 1, 1);

        pushButton = new QPushButton(FormFluSyn);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        gridLayout->addWidget(pushButton, 1, 1, 1, 1);


        retranslateUi(FormFluSyn);

        QMetaObject::connectSlotsByName(FormFluSyn);
    } // setupUi

    void retranslateUi(QWidget *FormFluSyn)
    {
        FormFluSyn->setWindowTitle(QApplication::translate("FormFluSyn", "Form", nullptr));
        checkBox->setText(QApplication::translate("FormFluSyn", "CheckBox", nullptr));
        pushButton->setText(QApplication::translate("FormFluSyn", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FormFluSyn: public Ui_FormFluSyn {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMFLUSYN_H
