/********************************************************************************
** Form generated from reading UI file 'formdarkfield.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMDARKFIELD_H
#define UI_FORMDARKFIELD_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormDarkField
{
public:
    QGridLayout *gridLayout;
    QCheckBox *checkBox;
    QPushButton *pushButton;
    QLabel *label;
    QSpinBox *spinBox;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QLabel *label_2;

    void setupUi(QWidget *FormDarkField)
    {
        if (FormDarkField->objectName().isEmpty())
            FormDarkField->setObjectName(QStringLiteral("FormDarkField"));
        FormDarkField->resize(249, 200);
        gridLayout = new QGridLayout(FormDarkField);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        checkBox = new QCheckBox(FormDarkField);
        checkBox->setObjectName(QStringLiteral("checkBox"));

        gridLayout->addWidget(checkBox, 0, 0, 1, 1);

        pushButton = new QPushButton(FormDarkField);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        gridLayout->addWidget(pushButton, 1, 0, 1, 1);

        label = new QLabel(FormDarkField);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 1, 1, 1, 1);

        spinBox = new QSpinBox(FormDarkField);
        spinBox->setObjectName(QStringLiteral("spinBox"));

        gridLayout->addWidget(spinBox, 1, 2, 1, 1);

        pushButton_2 = new QPushButton(FormDarkField);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        gridLayout->addWidget(pushButton_2, 2, 0, 1, 1);

        pushButton_3 = new QPushButton(FormDarkField);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        gridLayout->addWidget(pushButton_3, 2, 1, 1, 2);

        label_2 = new QLabel(FormDarkField);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMinimumSize(QSize(0, 77));
        label_2->setWordWrap(true);

        gridLayout->addWidget(label_2, 3, 0, 1, 3);


        retranslateUi(FormDarkField);

        QMetaObject::connectSlotsByName(FormDarkField);
    } // setupUi

    void retranslateUi(QWidget *FormDarkField)
    {
        FormDarkField->setWindowTitle(QApplication::translate("FormDarkField", "Form", nullptr));
        checkBox->setText(QApplication::translate("FormDarkField", "Enable", nullptr));
        pushButton->setText(QApplication::translate("FormDarkField", "PushButton", nullptr));
        label->setText(QApplication::translate("FormDarkField", "Quantity", nullptr));
        pushButton_2->setText(QApplication::translate("FormDarkField", "PushButton", nullptr));
        pushButton_3->setText(QApplication::translate("FormDarkField", "Export", nullptr));
        label_2->setText(QApplication::translate("FormDarkField", "Cover the lens, and then push the \"Capture\" button to capture the dark field. Check the \"Enable\" button to enable \"Dark Field Correction\".", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FormDarkField: public Ui_FormDarkField {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMDARKFIELD_H
