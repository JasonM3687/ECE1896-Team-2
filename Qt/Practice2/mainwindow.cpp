#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include <QTextStream>
#include <QFile>
#include <QMessageBox>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix("C:/Users/deanw/Documents/04_Senior_Year/2nd_Semester/ECE_1896/Checkoff1/picture213.jpg");
    QPixmap pix2("C:/Users/deanw/Documents/04_Senior_Year/2nd_Semester/ECE_1896/Checkoff1/picture214.jpg");

    ui->label_pic->setPixmap(pix.scaled(350,250,Qt::KeepAspectRatio));

    ui->progressBar->setValue(86);
    ui->progressBar_2->setValue(9);
    ui->progressBar_3->setValue(5);
    ui->lcdNumber->display(7);
    ui->lcdNumber_2->display(94);
    ui->lcdNumber_3->display(91);
    ui->lcdNumber_4->display(96);
    ui->lcdNumber_5->display(93);
    ui->lcdNumber_6->display(94);
    ui->label_pic2->setPixmap(pix.scaled(350,250,Qt::KeepAspectRatio));
    ui->label_pic3->setPixmap(pix2.scaled(200,150,Qt::KeepAspectRatio));

//    QFile file("C:/Users/deanw/Documents/04_Senior_Year/2nd_Semester/ECE_1896/Checkoff1/practice.txt");
//    if (!file.open(QFile::ReadOnly | QFile::Text))
//    {
//        QMessageBox::warning(this,"title","file not open");
//    }
//    QTextStream in(&file);
//    QString text = in.readAll();
//    file.close();

}

MainWindow::~MainWindow()
{
    delete ui;
}

