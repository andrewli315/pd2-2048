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
#include<QToolBar>
#include<QMenuBar>
#include<QMenu>
#include<QtGui>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWidget *mywidget = new QWidget();
    mywidget->setGeometry(300,300,500,400);
    mywidget->setFixedSize(300,400);
    mywidget->setStyleSheet("background-color: linen;");

    QPushButton *quit_button= new QPushButton("quit",mywidget);
    quit_button->setGeometry(240,70,50,25);
    QObject::connect(quit_button,SIGNAL(clicked()),&a,SLOT(quit()));



    QLabel *mylabel = new QLabel("2048",mywidget);
    mylabel->setGeometry(30,50,100,50);
    mylabel->setText("<html><head/><body><p><span style=\" font: 27pt Adobe Arabic; color:#000000;\">2048!</span></p></body></html>");

    Block *game = new Block(mywidget);
    game->setFocus();


    game->setFocusPolicy(Qt::TabFocus);


    game->game();



    mywidget->show();

    return a.exec();
}
