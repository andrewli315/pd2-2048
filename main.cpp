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
    mywidget->setStyleSheet("background-color: moccasin;");

    QLabel *mylabel = new QLabel("2048",mywidget);
    mylabel->setGeometry(10,50,100,40);
    mylabel->setText("<html><head/><body><p><span style=\" font: 24pt Adobe Arabic; color:#000000;\">2048!</span></p></body></html>");


    QPushButton *button = new QPushButton("reset",mywidget);
    button->setGeometry(250,50,40,40);
    QObject::connect(button,SIGNAL(clicked()),&a,SLOT(quit()));

    QLCDNumber *score = new QLCDNumber(10,mywidget);
    score->setSegmentStyle(QLCDNumber::Flat);
    score->setGeometry(150,50,100,40);
    score->display(0);

    Block *game = new Block(mywidget);
    game->setFocus();
    game->game();



    mywidget->show();

    return a.exec();
}
