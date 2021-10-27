/********************************************************************************
** Form generated from reading UI file 'camod.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CAMOD_H
#define UI_CAMOD_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Camod
{
public:
    QAction *actionNew;
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionSave_As;
    QAction *actionEXit;
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QMenu *menuAbout;
    QStatusBar *statusBar;
    QDockWidget *dockWidget;
    QWidget *dockWidgetContents;
    QVBoxLayout *verticalLayout;
    QTreeWidget *treeWidget;

    void setupUi(QMainWindow *Camod)
    {
        if (Camod->objectName().isEmpty())
            Camod->setObjectName(QStringLiteral("Camod"));
        Camod->resize(1000, 700);
        actionNew = new QAction(Camod);
        actionNew->setObjectName(QStringLiteral("actionNew"));
        actionOpen = new QAction(Camod);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        actionSave = new QAction(Camod);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        actionSave_As = new QAction(Camod);
        actionSave_As->setObjectName(QStringLiteral("actionSave_As"));
        actionEXit = new QAction(Camod);
        actionEXit->setObjectName(QStringLiteral("actionEXit"));
        centralWidget = new QWidget(Camod);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        Camod->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Camod);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1000, 22));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QStringLiteral("menuEdit"));
        menuAbout = new QMenu(menuBar);
        menuAbout->setObjectName(QStringLiteral("menuAbout"));
        Camod->setMenuBar(menuBar);
        statusBar = new QStatusBar(Camod);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        Camod->setStatusBar(statusBar);
        dockWidget = new QDockWidget(Camod);
        dockWidget->setObjectName(QStringLiteral("dockWidget"));
        dockWidget->setMinimumSize(QSize(280, 120));
        dockWidget->setMaximumSize(QSize(400, 524287));
        dockWidget->setAllowedAreas(Qt::LeftDockWidgetArea|Qt::RightDockWidgetArea);
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QStringLiteral("dockWidgetContents"));
        verticalLayout = new QVBoxLayout(dockWidgetContents);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        treeWidget = new QTreeWidget(dockWidgetContents);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QStringLiteral("1"));
        treeWidget->setHeaderItem(__qtreewidgetitem);
        treeWidget->setObjectName(QStringLiteral("treeWidget"));
        treeWidget->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
        treeWidget->setIndentation(0);
        treeWidget->setRootIsDecorated(false);
        treeWidget->setAnimated(true);
        treeWidget->setHeaderHidden(true);
        treeWidget->header()->setVisible(false);

        verticalLayout->addWidget(treeWidget);

        dockWidget->setWidget(dockWidgetContents);
        Camod->addDockWidget(static_cast<Qt::DockWidgetArea>(1), dockWidget);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuBar->addAction(menuAbout->menuAction());
        menuFile->addAction(actionNew);
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionSave);
        menuFile->addAction(actionSave_As);
        menuFile->addAction(actionEXit);

        retranslateUi(Camod);

        QMetaObject::connectSlotsByName(Camod);
    } // setupUi

    void retranslateUi(QMainWindow *Camod)
    {
        Camod->setWindowTitle(QApplication::translate("Camod", "Camod", nullptr));
        actionNew->setText(QApplication::translate("Camod", "New", nullptr));
        actionOpen->setText(QApplication::translate("Camod", "Open", nullptr));
        actionSave->setText(QApplication::translate("Camod", "Save", nullptr));
        actionSave_As->setText(QApplication::translate("Camod", "Save As", nullptr));
        actionEXit->setText(QApplication::translate("Camod", "EXit", nullptr));
        menuFile->setTitle(QApplication::translate("Camod", "File", nullptr));
        menuEdit->setTitle(QApplication::translate("Camod", "Edit", nullptr));
        menuAbout->setTitle(QApplication::translate("Camod", "About", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Camod: public Ui_Camod {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CAMOD_H
