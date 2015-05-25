#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QLabel>
#include<QDialog>
#include<QLineEdit>
#include<QLayout>
#include<QFont>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    QLabel *test = new QLabel();
    test->setGeometry(10,10,100,100);
    test->setText("test");
    test->setFont(QFont("times",16));

    ui->setupUi(this);
}

MainWindow::~MainWindow()
{

    delete ui;
}
