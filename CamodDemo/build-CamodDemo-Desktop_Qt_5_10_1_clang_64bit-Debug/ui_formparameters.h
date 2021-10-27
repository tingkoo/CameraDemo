/********************************************************************************
** Form generated from reading UI file 'formparameters.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMPARAMETERS_H
#define UI_FORMPARAMETERS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormParameters
{
public:
    QGridLayout *gridLayout;
    QComboBox *comboBox;
    QPushButton *pushButton;
    QPushButton *pushButton_4;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;

    void setupUi(QWidget *FormParameters)
    {
        if (FormParameters->objectName().isEmpty())
            FormParameters->setObjectName(QStringLiteral("FormParameters"));
        FormParameters->resize(245, 120);
        gridLayout = new QGridLayout(FormParameters);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        comboBox = new QComboBox(FormParameters);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        gridLayout->addWidget(comboBox, 0, 0, 1, 2);

        pushButton = new QPushButton(FormParameters);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy);
        pushButton->setMinimumSize(QSize(113, 0));
        pushButton->setMaximumSize(QSize(113, 16777215));

        gridLayout->addWidget(pushButton, 1, 0, 1, 1);

        pushButton_4 = new QPushButton(FormParameters);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        sizePolicy.setHeightForWidth(pushButton_4->sizePolicy().hasHeightForWidth());
        pushButton_4->setSizePolicy(sizePolicy);
        pushButton_4->setMinimumSize(QSize(113, 0));
        pushButton_4->setMaximumSize(QSize(113, 16777215));

        gridLayout->addWidget(pushButton_4, 1, 1, 1, 1);

        pushButton_2 = new QPushButton(FormParameters);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        sizePolicy.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy);
        pushButton_2->setMinimumSize(QSize(113, 0));
        pushButton_2->setMaximumSize(QSize(113, 16777215));

        gridLayout->addWidget(pushButton_2, 2, 0, 1, 1);

        pushButton_3 = new QPushButton(FormParameters);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        sizePolicy.setHeightForWidth(pushButton_3->sizePolicy().hasHeightForWidth());
        pushButton_3->setSizePolicy(sizePolicy);
        pushButton_3->setMinimumSize(QSize(113, 0));
        pushButton_3->setMaximumSize(QSize(113, 16777215));

        gridLayout->addWidget(pushButton_3, 2, 1, 1, 1);


        retranslateUi(FormParameters);

        QMetaObject::connectSlotsByName(FormParameters);
    } // setupUi

    void retranslateUi(QWidget *FormParameters)
    {
        FormParameters->setWindowTitle(QApplication::translate("FormParameters", "Form", nullptr));
        pushButton->setText(QApplication::translate("FormParameters", "Load", nullptr));
        pushButton_4->setText(QApplication::translate("FormParameters", "Save", nullptr));
        pushButton_2->setText(QApplication::translate("FormParameters", "Overwrite", nullptr));
        pushButton_3->setText(QApplication::translate("FormParameters", "Management", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FormParameters: public Ui_FormParameters {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMPARAMETERS_H
