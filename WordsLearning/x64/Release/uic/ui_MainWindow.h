/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <WordsLearning.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindowClass
{
public:
    QAction *actionLearning;
    QAction *actionBrowse;
    QAction *actionPath_2;
    QAction *actionSetting;
    QAction *actionSave;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    WordsLearning *widget;
    QMenuBar *menuBar;
    QMenu *menu;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindowClass)
    {
        if (MainWindowClass->objectName().isEmpty())
            MainWindowClass->setObjectName("MainWindowClass");
        MainWindowClass->resize(644, 413);
        actionLearning = new QAction(MainWindowClass);
        actionLearning->setObjectName("actionLearning");
        actionBrowse = new QAction(MainWindowClass);
        actionBrowse->setObjectName("actionBrowse");
        actionPath_2 = new QAction(MainWindowClass);
        actionPath_2->setObjectName("actionPath_2");
        actionSetting = new QAction(MainWindowClass);
        actionSetting->setObjectName("actionSetting");
        actionSave = new QAction(MainWindowClass);
        actionSave->setObjectName("actionSave");
        centralWidget = new QWidget(MainWindowClass);
        centralWidget->setObjectName("centralWidget");
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName("verticalLayout");
        widget = new WordsLearning(centralWidget);
        widget->setObjectName("widget");

        verticalLayout->addWidget(widget);

        MainWindowClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindowClass);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 644, 33));
        menu = new QMenu(menuBar);
        menu->setObjectName("menu");
        MainWindowClass->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindowClass);
        statusBar->setObjectName("statusBar");
        MainWindowClass->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());
        menu->addAction(actionSetting);
        menu->addAction(actionSave);

        retranslateUi(MainWindowClass);

        QMetaObject::connectSlotsByName(MainWindowClass);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindowClass)
    {
        MainWindowClass->setWindowTitle(QCoreApplication::translate("MainWindowClass", "MainWindow", nullptr));
        actionLearning->setText(QCoreApplication::translate("MainWindowClass", "Learning", nullptr));
        actionBrowse->setText(QCoreApplication::translate("MainWindowClass", "Browse", nullptr));
        actionPath_2->setText(QCoreApplication::translate("MainWindowClass", "Path", nullptr));
        actionSetting->setText(QCoreApplication::translate("MainWindowClass", "Setting", nullptr));
        actionSave->setText(QCoreApplication::translate("MainWindowClass", "Save", nullptr));
        menu->setTitle(QCoreApplication::translate("MainWindowClass", "File", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindowClass: public Ui_MainWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
