#include"block.h"
#include<QLabel>
#include<QPushButton>
#include <QApplication>
#include <QFont>
#include <QLCDNumber>
#include<QGraphicsRectItem>
#include<QGraphicsScene>
#include<QGraphicsRectItem>
#include<QGraphicsView>




int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWidget *mywidget = new QWidget();
    mywidget->setGeometry(300,300,500,400);
    mywidget->setFixedSize(300,400);
    mywidget->setStyleSheet("background-color: linen;");

    QLabel *mylabel = new QLabel("2048",mywidget);
    mylabel->setGeometry(10,50,100,40);
    mylabel->setText("<html><head/><body><p><span style=\" font: 24pt Adobe Arabic; color:#000000;\">2048!</span></p></body></html>");

    Block *game = new Block(mywidget);

    QPushButton *reset_button = new QPushButton("reset",mywidget);
    reset_button->setGeometry(250,50,40,20);
    QObject::connect(reset_button,SIGNAL(clicked()),&a,SLOT(game()));

    QPushButton *quit_button = new QPushButton("quit",mywidget);
    quit_button->setGeometry(250,70,40,20);
    QObject::connect(quit_button,SIGNAL(clicked()),&a,SLOT(quit()));


    game->setFocus();

    game->game();



    mywidget->show();

    return a.exec();
}
