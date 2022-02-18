/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QGridLayout *gridLayout;
    QLabel *label_2;
    QLCDNumber *lcdNumber_2;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLCDNumber *lcdNumber;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(462, 281);
        gridLayout = new QGridLayout(Dialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_2 = new QLabel(Dialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        label_2->setFont(font);

        gridLayout->addWidget(label_2, 0, 1, 1, 1);

        lcdNumber_2 = new QLCDNumber(Dialog);
        lcdNumber_2->setObjectName(QString::fromUtf8("lcdNumber_2"));

        gridLayout->addWidget(lcdNumber_2, 1, 1, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(Dialog);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(28);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setMaximumSize(QSize(16777215, 16777215));
        QFont font1;
        font1.setPointSize(20);
        font1.setBold(true);
        label->setFont(font1);

        verticalLayout->addWidget(label);

        lcdNumber = new QLCDNumber(Dialog);
        lcdNumber->setObjectName(QString::fromUtf8("lcdNumber"));

        verticalLayout->addWidget(lcdNumber);


        gridLayout->addLayout(verticalLayout, 2, 0, 1, 1);


        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "Dialog", nullptr));
        label_2->setText(QCoreApplication::translate("Dialog", "Digit Probabilities:", nullptr));
        label->setText(QCoreApplication::translate("Dialog", "Inferenced Digit:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
