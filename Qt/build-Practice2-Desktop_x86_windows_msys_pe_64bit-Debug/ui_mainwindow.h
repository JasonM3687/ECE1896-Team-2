/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *label_pic;
    QLabel *label_2;
    QLCDNumber *lcdNumber;
    QFormLayout *formLayout;
    QLabel *label;
    QLabel *label_3;
    QProgressBar *progressBar;
    QProgressBar *progressBar_2;
    QLabel *label_4;
    QProgressBar *progressBar_3;
    QLabel *label_5;
    QWidget *tab_2;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_6;
    QLCDNumber *lcdNumber_2;
    QLabel *label_8;
    QFormLayout *formLayout_2;
    QLabel *label_9;
    QLCDNumber *lcdNumber_3;
    QLCDNumber *lcdNumber_4;
    QLabel *label_10;
    QLCDNumber *lcdNumber_5;
    QLabel *label_11;
    QLCDNumber *lcdNumber_6;
    QLabel *label_12;
    QWidget *tab_3;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_7;
    QLabel *label_pic2;
    QLabel *label_13;
    QLabel *label_pic3;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(503, 337);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setTabShape(QTabWidget::Rounded);
        tabWidget->setIconSize(QSize(20, 20));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        horizontalLayoutWidget = new QWidget(tab);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(-1, -1, 491, 261));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setSizeConstraint(QLayout::SetMinimumSize);
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetMinimumSize);
        label_pic = new QLabel(horizontalLayoutWidget);
        label_pic->setObjectName(QString::fromUtf8("label_pic"));

        verticalLayout->addWidget(label_pic);

        label_2 = new QLabel(horizontalLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy1);

        verticalLayout->addWidget(label_2);

        lcdNumber = new QLCDNumber(horizontalLayoutWidget);
        lcdNumber->setObjectName(QString::fromUtf8("lcdNumber"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(lcdNumber->sizePolicy().hasHeightForWidth());
        lcdNumber->setSizePolicy(sizePolicy2);
        lcdNumber->setSegmentStyle(QLCDNumber::Flat);

        verticalLayout->addWidget(lcdNumber);


        horizontalLayout_2->addLayout(verticalLayout);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setSizeConstraint(QLayout::SetMinimumSize);
        label = new QLabel(horizontalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::SpanningRole, label);

        label_3 = new QLabel(horizontalLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_3);

        progressBar = new QProgressBar(horizontalLayoutWidget);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setValue(24);

        formLayout->setWidget(1, QFormLayout::FieldRole, progressBar);

        progressBar_2 = new QProgressBar(horizontalLayoutWidget);
        progressBar_2->setObjectName(QString::fromUtf8("progressBar_2"));
        progressBar_2->setValue(24);

        formLayout->setWidget(2, QFormLayout::FieldRole, progressBar_2);

        label_4 = new QLabel(horizontalLayoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_4);

        progressBar_3 = new QProgressBar(horizontalLayoutWidget);
        progressBar_3->setObjectName(QString::fromUtf8("progressBar_3"));
        progressBar_3->setValue(24);

        formLayout->setWidget(3, QFormLayout::FieldRole, progressBar_3);

        label_5 = new QLabel(horizontalLayoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_5);


        horizontalLayout_2->addLayout(formLayout);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        verticalLayoutWidget = new QWidget(tab_2);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(-1, -1, 491, 261));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setSizeConstraint(QLayout::SetMinimumSize);
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_6 = new QLabel(verticalLayoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_3->addWidget(label_6);

        lcdNumber_2 = new QLCDNumber(verticalLayoutWidget);
        lcdNumber_2->setObjectName(QString::fromUtf8("lcdNumber_2"));

        horizontalLayout_3->addWidget(lcdNumber_2);


        verticalLayout_2->addLayout(horizontalLayout_3);

        label_8 = new QLabel(verticalLayoutWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        sizePolicy1.setHeightForWidth(label_8->sizePolicy().hasHeightForWidth());
        label_8->setSizePolicy(sizePolicy1);

        verticalLayout_2->addWidget(label_8);

        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        label_9 = new QLabel(verticalLayoutWidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_9);

        lcdNumber_3 = new QLCDNumber(verticalLayoutWidget);
        lcdNumber_3->setObjectName(QString::fromUtf8("lcdNumber_3"));
        lcdNumber_3->setFrameShadow(QFrame::Raised);
        lcdNumber_3->setSmallDecimalPoint(false);
        lcdNumber_3->setSegmentStyle(QLCDNumber::Flat);

        formLayout_2->setWidget(0, QFormLayout::FieldRole, lcdNumber_3);

        lcdNumber_4 = new QLCDNumber(verticalLayoutWidget);
        lcdNumber_4->setObjectName(QString::fromUtf8("lcdNumber_4"));
        lcdNumber_4->setSegmentStyle(QLCDNumber::Flat);

        formLayout_2->setWidget(1, QFormLayout::FieldRole, lcdNumber_4);

        label_10 = new QLabel(verticalLayoutWidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, label_10);

        lcdNumber_5 = new QLCDNumber(verticalLayoutWidget);
        lcdNumber_5->setObjectName(QString::fromUtf8("lcdNumber_5"));
        lcdNumber_5->setSegmentStyle(QLCDNumber::Flat);

        formLayout_2->setWidget(3, QFormLayout::FieldRole, lcdNumber_5);

        label_11 = new QLabel(verticalLayoutWidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        formLayout_2->setWidget(3, QFormLayout::LabelRole, label_11);

        lcdNumber_6 = new QLCDNumber(verticalLayoutWidget);
        lcdNumber_6->setObjectName(QString::fromUtf8("lcdNumber_6"));
        lcdNumber_6->setSegmentStyle(QLCDNumber::Flat);

        formLayout_2->setWidget(2, QFormLayout::FieldRole, lcdNumber_6);

        label_12 = new QLabel(verticalLayoutWidget);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        formLayout_2->setWidget(2, QFormLayout::LabelRole, label_12);


        verticalLayout_2->addLayout(formLayout_2);

        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        verticalLayoutWidget_2 = new QWidget(tab_3);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(-1, -1, 491, 261));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setSizeConstraint(QLayout::SetMinimumSize);
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_7 = new QLabel(verticalLayoutWidget_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        sizePolicy1.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy1);

        verticalLayout_3->addWidget(label_7);

        label_pic2 = new QLabel(verticalLayoutWidget_2);
        label_pic2->setObjectName(QString::fromUtf8("label_pic2"));

        verticalLayout_3->addWidget(label_pic2);

        label_13 = new QLabel(verticalLayoutWidget_2);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        sizePolicy1.setHeightForWidth(label_13->sizePolicy().hasHeightForWidth());
        label_13->setSizePolicy(sizePolicy1);

        verticalLayout_3->addWidget(label_13);

        label_pic3 = new QLabel(verticalLayoutWidget_2);
        label_pic3->setObjectName(QString::fromUtf8("label_pic3"));

        verticalLayout_3->addWidget(label_pic3);

        tabWidget->addTab(tab_3, QString());

        horizontalLayout->addWidget(tabWidget);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 503, 17));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label_pic->setText(QString());
        label_2->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:20pt; font-weight:700;\">Inferenced Digit:</span></p></body></html>", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:16pt; font-weight:700;\">Digit Probabilites:</span></p></body></html>", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Probability Digit = 7:", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Probability Digit = 2:", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Probability Digit = 1:", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MainWindow", "Real-Time Demo", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:16pt; font-weight:700; color:#55aa00;\">Overall Accuracy:</span></p></body></html>", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:700; color:#55aa00;\">Digit Accuracies:</span></p></body></html>", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "1:", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "2:", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "4:", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "3:", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MainWindow", "Test Set Database Inferencing", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:700;\">Machine Learning Algorithm Process:</span></p></body></html>", nullptr));
        label_pic2->setText(QString());
        label_13->setText(QCoreApplication::translate("MainWindow", "Computer Vision algorithms will then modify the image...", nullptr));
        label_pic3->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("MainWindow", "Algorithm Process", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
