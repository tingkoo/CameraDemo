/********************************************************************************
** Form generated from reading UI file 'formmisc.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMMISC_H
#define UI_FORMMISC_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormMisc
{
public:
    QGridLayout *gridLayout;
    QCheckBox *checkBox;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QWidget *FormMisc)
    {
        if (FormMisc->objectName().isEmpty())
            FormMisc->setObjectName(QStringLiteral("FormMisc"));
        FormMisc->resize(245, 100);
        gridLayout = new QGridLayout(FormMisc);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        checkBox = new QCheckBox(FormMisc);
        checkBox->setObjectName(QStringLiteral("checkBox"));

        gridLayout->addWidget(checkBox, 0, 0, 1, 2);

        horizontalSpacer = new QSpacerItem(53, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 0, 1, 1);

        pushButton = new QPushButton(FormMisc);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        gridLayout->addWidget(pushButton, 1, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(53, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 2, 1, 1);


        retranslateUi(FormMisc);

        QMetaObject::connectSlotsByName(FormMisc);
    } // setupUi

    void retranslateUi(QWidget *FormMisc)
    {
        FormMisc->setWindowTitle(QApplication::translate("FormMisc", "Form", nullptr));
        checkBox->setText(QApplication::translate("FormMisc", "CheckBox", nullptr));
        pushButton->setText(QApplication::translate("FormMisc", "Defaults", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FormMisc: public Ui_FormMisc {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMMISC_H
