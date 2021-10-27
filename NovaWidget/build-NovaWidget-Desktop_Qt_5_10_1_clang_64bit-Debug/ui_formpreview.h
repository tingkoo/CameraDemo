/********************************************************************************
** Form generated from reading UI file 'formpreview.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMPREVIEW_H
#define UI_FORMPREVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormPreview
{
public:
    QHBoxLayout *horizontalLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGridLayout *gridLayout;
    QPushButton *pushButton_4;
    QSlider *verticalSlider;
    QLabel *label_3;
    QSlider *horizontalSlider;
    QPushButton *pushButton_2;
    QLabel *label_2;
    QPushButton *pushButton_6;
    QLabel *label;
    QPushButton *pushButton_3;
    QPushButton *pushButton_5;
    QWidget *tab_2;
    QWidget *tab_3;

    void setupUi(QWidget *FormPreview)
    {
        if (FormPreview->objectName().isEmpty())
            FormPreview->setObjectName(QStringLiteral("FormPreview"));
        FormPreview->resize(800, 500);
        horizontalLayout = new QHBoxLayout(FormPreview);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        tabWidget = new QTabWidget(FormPreview);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setTabPosition(QTabWidget::North);
        tabWidget->setTabShape(QTabWidget::Rounded);
        tabWidget->setElideMode(Qt::ElideRight);
        tabWidget->setMovable(false);
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        gridLayout = new QGridLayout(tab);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        pushButton_4 = new QPushButton(tab);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));

        gridLayout->addWidget(pushButton_4, 4, 0, 1, 1);

        verticalSlider = new QSlider(tab);
        verticalSlider->setObjectName(QStringLiteral("verticalSlider"));
        verticalSlider->setOrientation(Qt::Vertical);
        verticalSlider->setTickPosition(QSlider::TicksBelow);

        gridLayout->addWidget(verticalSlider, 2, 6, 1, 1);

        label_3 = new QLabel(tab);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 0, 0, 4, 4);

        horizontalSlider = new QSlider(tab);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setMouseTracking(false);
        horizontalSlider->setTabletTracking(false);
        horizontalSlider->setOrientation(Qt::Horizontal);
        horizontalSlider->setInvertedAppearance(false);
        horizontalSlider->setInvertedControls(false);
        horizontalSlider->setTickPosition(QSlider::TicksBelow);

        gridLayout->addWidget(horizontalSlider, 4, 2, 1, 1);

        pushButton_2 = new QPushButton(tab);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        gridLayout->addWidget(pushButton_2, 4, 3, 1, 2);

        label_2 = new QLabel(tab);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 6, 1, 1);

        pushButton_6 = new QPushButton(tab);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));

        gridLayout->addWidget(pushButton_6, 3, 5, 1, 2);

        label = new QLabel(tab);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 4, 1, 1, 1);

        pushButton_3 = new QPushButton(tab);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        gridLayout->addWidget(pushButton_3, 0, 4, 2, 3);

        pushButton_5 = new QPushButton(tab);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));

        gridLayout->addWidget(pushButton_5, 4, 5, 1, 2);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        tabWidget->addTab(tab_3, QString());

        horizontalLayout->addWidget(tabWidget);


        retranslateUi(FormPreview);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(FormPreview);
    } // setupUi

    void retranslateUi(QWidget *FormPreview)
    {
        FormPreview->setWindowTitle(QApplication::translate("FormPreview", "Form", nullptr));
        pushButton_4->setText(QApplication::translate("FormPreview", "1", nullptr));
        label_3->setText(QApplication::translate("FormPreview", "TextLabel", nullptr));
        pushButton_2->setText(QApplication::translate("FormPreview", "2", nullptr));
        label_2->setText(QApplication::translate("FormPreview", "0", nullptr));
        pushButton_6->setText(QApplication::translate("FormPreview", "0", nullptr));
        label->setText(QApplication::translate("FormPreview", "0", nullptr));
        pushButton_3->setText(QApplication::translate("FormPreview", "3", nullptr));
        pushButton_5->setText(QApplication::translate("FormPreview", "0", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("FormPreview", "\350\247\206\351\242\221\351\242\204\350\247\210", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("FormPreview", "\345\233\276\345\203\217\351\242\204\350\247\210", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("FormPreview", "GPU\345\212\240\351\200\237\345\244\204\347\220\206", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FormPreview: public Ui_FormPreview {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMPREVIEW_H
