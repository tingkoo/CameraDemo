/********************************************************************************
** Form generated from reading UI file 'novawidget.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NOVAWIDGET_H
#define UI_NOVAWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NovaWidget
{
public:

    void setupUi(QWidget *NovaWidget)
    {
        if (NovaWidget->objectName().isEmpty())
            NovaWidget->setObjectName(QStringLiteral("NovaWidget"));
        NovaWidget->resize(800, 500);

        retranslateUi(NovaWidget);

        QMetaObject::connectSlotsByName(NovaWidget);
    } // setupUi

    void retranslateUi(QWidget *NovaWidget)
    {
        NovaWidget->setWindowTitle(QApplication::translate("NovaWidget", "NovaWidget", nullptr));
    } // retranslateUi

};

namespace Ui {
    class NovaWidget: public Ui_NovaWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NOVAWIDGET_H
