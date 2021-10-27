/********************************************************************************
** Form generated from reading UI file 'formframerate.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMFRAMERATE_H
#define UI_FORMFRAMERATE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormFrameRate
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QLabel *label_2;
    QSlider *horizontalSlider;
    QLabel *label_3;

    void setupUi(QWidget *FormFrameRate)
    {
        if (FormFrameRate->objectName().isEmpty())
            FormFrameRate->setObjectName(QStringLiteral("FormFrameRate"));
        FormFrameRate->resize(245, 200);
        verticalLayout = new QVBoxLayout(FormFrameRate);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(FormFrameRate);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label_2 = new QLabel(FormFrameRate);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout->addWidget(label_2);


        verticalLayout->addLayout(horizontalLayout);

        horizontalSlider = new QSlider(FormFrameRate);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setOrientation(Qt::Horizontal);

        verticalLayout->addWidget(horizontalSlider);

        label_3 = new QLabel(FormFrameRate);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMinimumSize(QSize(0, 108));
        label_3->setWordWrap(true);

        verticalLayout->addWidget(label_3);


        retranslateUi(FormFrameRate);

        QMetaObject::connectSlotsByName(FormFrameRate);
    } // setupUi

    void retranslateUi(QWidget *FormFrameRate)
    {
        FormFrameRate->setWindowTitle(QApplication::translate("FormFrameRate", "Form", nullptr));
        label->setText(QApplication::translate("FormFrameRate", "Low", nullptr));
        label_2->setText(QApplication::translate("FormFrameRate", "High", nullptr));
        label_3->setText(QApplication::translate("FormFrameRate", "Move the slider to the right to ensure that the camera plays live video at the fastest frame rate that the computer USB hub supports. If live video fails to display, move theslider to the left to decrease the frame rate.", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FormFrameRate: public Ui_FormFrameRate {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMFRAMERATE_H
