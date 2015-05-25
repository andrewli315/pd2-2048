#include"block.h"
#include<QLabel>
#include<ctime>
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<QKeyEvent>
#include<QDebug>
Block::Block(QWidget *parent): QLabel(parent){

    for(int i=0;i<16;i++)
    {
        b[i] = new QLabel(parent);
    }
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            b[4*i+j]->setGeometry(30+50*j,120+50*i,40,40);
            b[4*i+j]->setText("<html><head/><body><p><span style=\" font-size:16pt; color:#000000;\">2</span></p></body></html>");
            b[4*i+j]->setStyleSheet("background-color: blue;");
            b[4*i+j]->show();
        }
    }

}

void Block::reset()
{
    int num[2]={2,4};
    int index,loc_x,loc_y;
    srand((int)time(NULL));
    index = rand()%2;
    loc_x = rand()%4+1;
    loc_y = rand()%4+1;
    for(int i =0;i<6;i++)
        for(int j=0;j<6;j++)
            current[i][j] = 0;
    for(int i =0;i<5;i++)
    {
        current[loc_y][loc_x] = num[index];
        index = rand()%2;
        loc_x = rand()%4+1;
        loc_y = rand()%4+1;
    }
}

void Block::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Up)
    {
            qDebug()<<"arrow key";
            rotate();
            rotate();
            movedata();
            rotate();
            rotate();
            hi();
    }
    else if(event->key() == Qt::Key_Down)
    {
          qDebug()<<"arrow key";
            movedata();
            hi();
    }
    else if(event->key()== Qt::Key_Left)
    {
            qDebug()<<"arrow key";
            rotate();
            movedata();
            rotate();
            rotate();
            rotate();
            hi();
    }
    else if(event->key() == Qt::Key_Right)
    {
            qDebug()<<"arrow key";
            rotate();
            rotate();
            rotate();
            movedata();
            rotate();
            hi();
    }

}

void Block::game()
{
    hi();
    reset();
}

void Block::hi()
{

    for(int i=1;i<5;i++)
    {
        for(int j=1;j<5;j++)
        {
            if(current[i][j] == 0)
            {
                b[4*(i-1)+j-1]->hide();
            }
            else
            {
                b[4*(i-1)+j-1]->show();
            }
        }
    }

}

void Block::movedata()
{
    canmove = 1;
    for(int i=1;i<5;i++)
    {
        for(int j=1;j<5;j++)
        {
            if(current[j][i] == 0 && current[j-1][i]!=0)
            {
                current[j][i] = current[j-1][i];
                current[j-1][i] =0;
                j=1;
                canmove = 1;
            }
        }
    }
    for(int i=1;i<5;i++)
    {
        for(int j=4;j>0;j--)
        {
            if(current[j][i] == current[j-1][i])
            {
                current[j][i] = current[j-1][i] + current[j][i];
                current[j-1][i] =0;
                canmove = 1;
            }
        }
    }

}

void Block::generateNewnumber()
{
    int num[2]={2,4};
    int index,loc_x,loc_y;
    srand((int)time(NULL));
    index = rand()%2;
    loc_x = 0;
    loc_y = 0;
    while(current[loc_y][loc_x] != 0)
    {
    loc_x = rand()%4;
    loc_y = rand()%4;
    }
    current[loc_y][loc_x] = num[index];
}

void Block::rotate()
{
    int temp[4][4];
    for(int i=1;i<5;i++)
    {
        int k=0;
        for(int j = 4;j>0;j--)
        {
            temp[i-1][k] = current[i][j];
            k++;
        }
    }
    for(int i=1;i<5;i++)
    {
        for(int j=1;j<5;j++)
        {
            current[j][i] = temp[i-1][j-1];
        }
    }
}

