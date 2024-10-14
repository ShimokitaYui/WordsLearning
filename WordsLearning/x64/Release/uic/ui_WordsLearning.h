/********************************************************************************
** Form generated from reading UI file 'WordsLearning.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WORDSLEARNING_H
#define UI_WORDSLEARNING_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WordsLearningClass
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *btnY;
    QPushButton *btnN;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *WordsLearningClass)
    {
        if (WordsLearningClass->objectName().isEmpty())
            WordsLearningClass->setObjectName("WordsLearningClass");
        WordsLearningClass->resize(626, 302);
        verticalLayout = new QVBoxLayout(WordsLearningClass);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName("horizontalLayout");
        label = new QLabel(WordsLearningClass);
        label->setObjectName("label");
        QFont font;
        font.setPointSize(25);
        label->setFont(font);

        horizontalLayout->addWidget(label);

        lineEdit = new QLineEdit(WordsLearningClass);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setMinimumSize(QSize(470, 0));
        QFont font1;
        font1.setPointSize(25);
        font1.setBold(true);
        lineEdit->setFont(font1);

        horizontalLayout->addWidget(lineEdit);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        btnY = new QPushButton(WordsLearningClass);
        btnY->setObjectName("btnY");
        btnY->setMinimumSize(QSize(100, 100));
        btnY->setFont(font);

        horizontalLayout_2->addWidget(btnY);

        btnN = new QPushButton(WordsLearningClass);
        btnN->setObjectName("btnN");
        btnN->setMinimumSize(QSize(100, 100));
        btnN->setFont(font);

        horizontalLayout_2->addWidget(btnN);


        horizontalLayout_3->addLayout(horizontalLayout_2);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_3);

        verticalSpacer = new QSpacerItem(20, 116, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        retranslateUi(WordsLearningClass);

        QMetaObject::connectSlotsByName(WordsLearningClass);
    } // setupUi

    void retranslateUi(QWidget *WordsLearningClass)
    {
        WordsLearningClass->setWindowTitle(QCoreApplication::translate("WordsLearningClass", "WordsLearning", nullptr));
        label->setText(QCoreApplication::translate("WordsLearningClass", "Words : ", nullptr));
        lineEdit->setText(QString());
        lineEdit->setPlaceholderText(QCoreApplication::translate("WordsLearningClass", "Please Enter New Words", nullptr));
        btnY->setText(QCoreApplication::translate("WordsLearningClass", "Yes", nullptr));
        btnN->setText(QCoreApplication::translate("WordsLearningClass", "No", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WordsLearningClass: public Ui_WordsLearningClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WORDSLEARNING_H
