/********************************************************************************
** Form generated from reading UI file 'TranslateDialog.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRANSLATEDIALOG_H
#define UI_TRANSLATEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_TranslateDialogClass
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *en_t;
    QLabel *zh_t;
    QHBoxLayout *horizontalLayout;
    QPushButton *yBtn;
    QPushButton *nBtn;

    void setupUi(QDialog *TranslateDialogClass)
    {
        if (TranslateDialogClass->objectName().isEmpty())
            TranslateDialogClass->setObjectName("TranslateDialogClass");
        TranslateDialogClass->resize(323, 304);
        verticalLayout = new QVBoxLayout(TranslateDialogClass);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName("verticalLayout");
        en_t = new QLabel(TranslateDialogClass);
        en_t->setObjectName("en_t");
        QFont font;
        font.setPointSize(50);
        font.setBold(true);
        en_t->setFont(font);
        en_t->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(en_t);

        zh_t = new QLabel(TranslateDialogClass);
        zh_t->setObjectName("zh_t");
        zh_t->setFont(font);
        zh_t->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(zh_t);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName("horizontalLayout");
        yBtn = new QPushButton(TranslateDialogClass);
        yBtn->setObjectName("yBtn");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(yBtn->sizePolicy().hasHeightForWidth());
        yBtn->setSizePolicy(sizePolicy);
        yBtn->setMinimumSize(QSize(100, 100));
        yBtn->setMaximumSize(QSize(100, 100));
        QFont font1;
        font1.setPointSize(20);
        yBtn->setFont(font1);

        horizontalLayout->addWidget(yBtn);

        nBtn = new QPushButton(TranslateDialogClass);
        nBtn->setObjectName("nBtn");
        sizePolicy.setHeightForWidth(nBtn->sizePolicy().hasHeightForWidth());
        nBtn->setSizePolicy(sizePolicy);
        nBtn->setMinimumSize(QSize(100, 100));
        nBtn->setMaximumSize(QSize(100, 100));
        nBtn->setFont(font1);

        horizontalLayout->addWidget(nBtn);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(TranslateDialogClass);

        QMetaObject::connectSlotsByName(TranslateDialogClass);
    } // setupUi

    void retranslateUi(QDialog *TranslateDialogClass)
    {
        TranslateDialogClass->setWindowTitle(QCoreApplication::translate("TranslateDialogClass", "TranslateDialog", nullptr));
        en_t->setText(QCoreApplication::translate("TranslateDialogClass", "Happy", nullptr));
        zh_t->setText(QCoreApplication::translate("TranslateDialogClass", "Happy", nullptr));
        yBtn->setText(QCoreApplication::translate("TranslateDialogClass", "Yes", nullptr));
        nBtn->setText(QCoreApplication::translate("TranslateDialogClass", "No", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TranslateDialogClass: public Ui_TranslateDialogClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRANSLATEDIALOG_H
