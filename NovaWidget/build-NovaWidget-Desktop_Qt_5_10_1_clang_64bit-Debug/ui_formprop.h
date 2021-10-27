/********************************************************************************
** Form generated from reading UI file 'formprop.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMPROP_H
#define UI_FORMPROP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormProp
{
public:
    QGridLayout *gridLayout;
    QTextEdit *textEdit;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QWidget *FormProp)
    {
        if (FormProp->objectName().isEmpty())
            FormProp->setObjectName(QStringLiteral("FormProp"));
        FormProp->resize(800, 500);
        gridLayout = new QGridLayout(FormProp);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        textEdit = new QTextEdit(FormProp);
        textEdit->setObjectName(QStringLiteral("textEdit"));

        gridLayout->addWidget(textEdit, 0, 0, 1, 3);

        horizontalSpacer = new QSpacerItem(543, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 0, 1, 1);

        pushButton = new QPushButton(FormProp);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        gridLayout->addWidget(pushButton, 1, 1, 1, 1);

        pushButton_2 = new QPushButton(FormProp);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        gridLayout->addWidget(pushButton_2, 1, 2, 1, 1);


        retranslateUi(FormProp);

        QMetaObject::connectSlotsByName(FormProp);
    } // setupUi

    void retranslateUi(QWidget *FormProp)
    {
        FormProp->setWindowTitle(QApplication::translate("FormProp", "Form", nullptr));
        pushButton->setText(QApplication::translate("FormProp", "PushButton", nullptr));
        pushButton_2->setText(QApplication::translate("FormProp", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FormProp: public Ui_FormProp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMPROP_H
