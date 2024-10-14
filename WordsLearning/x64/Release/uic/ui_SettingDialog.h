/********************************************************************************
** Form generated from reading UI file 'SettingDialog.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGDIALOG_H
#define UI_SETTINGDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SettingDialogClass
{
public:
    QHBoxLayout *horizontalLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QVBoxLayout *verticalLayout_3;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLineEdit *lineEdit;
    QToolButton *toolButton;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QLineEdit *fileName;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_3;
    QLineEdit *fileFullPath;
    QToolButton *fileReadBtn;
    QSpacerItem *verticalSpacer;

    void setupUi(QDialog *SettingDialogClass)
    {
        if (SettingDialogClass->objectName().isEmpty())
            SettingDialogClass->setObjectName("SettingDialogClass");
        SettingDialogClass->resize(600, 400);
        horizontalLayout = new QHBoxLayout(SettingDialogClass);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName("horizontalLayout");
        tabWidget = new QTabWidget(SettingDialogClass);
        tabWidget->setObjectName("tabWidget");
        tab = new QWidget();
        tab->setObjectName("tab");
        verticalLayout_3 = new QVBoxLayout(tab);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName("verticalLayout_3");
        groupBox = new QGroupBox(tab);
        groupBox->setObjectName("groupBox");
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label = new QLabel(groupBox);
        label->setObjectName("label");
        QFont font;
        font.setBold(true);
        label->setFont(font);

        horizontalLayout_2->addWidget(label);

        lineEdit = new QLineEdit(groupBox);
        lineEdit->setObjectName("lineEdit");

        horizontalLayout_2->addWidget(lineEdit);

        toolButton = new QToolButton(groupBox);
        toolButton->setObjectName("toolButton");

        horizontalLayout_2->addWidget(toolButton);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_2 = new QLabel(groupBox);
        label_2->setObjectName("label_2");
        label_2->setFont(font);

        horizontalLayout_3->addWidget(label_2);

        fileName = new QLineEdit(groupBox);
        fileName->setObjectName("fileName");

        horizontalLayout_3->addWidget(fileName);


        verticalLayout->addLayout(horizontalLayout_3);


        verticalLayout_3->addWidget(groupBox);

        groupBox_2 = new QGroupBox(tab);
        groupBox_2->setObjectName("groupBox_2");
        verticalLayout_2 = new QVBoxLayout(groupBox_2);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName("verticalLayout_2");
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName("label_3");
        label_3->setFont(font);

        horizontalLayout_4->addWidget(label_3);

        fileFullPath = new QLineEdit(groupBox_2);
        fileFullPath->setObjectName("fileFullPath");

        horizontalLayout_4->addWidget(fileFullPath);

        fileReadBtn = new QToolButton(groupBox_2);
        fileReadBtn->setObjectName("fileReadBtn");

        horizontalLayout_4->addWidget(fileReadBtn);


        verticalLayout_2->addLayout(horizontalLayout_4);


        verticalLayout_3->addWidget(groupBox_2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);

        tabWidget->addTab(tab, QString());

        horizontalLayout->addWidget(tabWidget);


        retranslateUi(SettingDialogClass);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(SettingDialogClass);
    } // setupUi

    void retranslateUi(QDialog *SettingDialogClass)
    {
        SettingDialogClass->setWindowTitle(QCoreApplication::translate("SettingDialogClass", "SettingDialog", nullptr));
        groupBox->setTitle(QCoreApplication::translate("SettingDialogClass", "Path Setting", nullptr));
        label->setText(QCoreApplication::translate("SettingDialogClass", "Path: ", nullptr));
        lineEdit->setPlaceholderText(QCoreApplication::translate("SettingDialogClass", "Please Enter File Path", nullptr));
        toolButton->setText(QCoreApplication::translate("SettingDialogClass", "...", nullptr));
        label_2->setText(QCoreApplication::translate("SettingDialogClass", "File Name:", nullptr));
        fileName->setPlaceholderText(QCoreApplication::translate("SettingDialogClass", "Please Enter File Name", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("SettingDialogClass", "File Read", nullptr));
        label_3->setText(QCoreApplication::translate("SettingDialogClass", "File: ", nullptr));
        fileFullPath->setPlaceholderText(QCoreApplication::translate("SettingDialogClass", "Please Enter File Path", nullptr));
        fileReadBtn->setText(QCoreApplication::translate("SettingDialogClass", "...", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("SettingDialogClass", "Path", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SettingDialogClass: public Ui_SettingDialogClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGDIALOG_H
