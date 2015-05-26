#include"block.h"
#include<QLabel>
#include<ctime>
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<QKeyEvent>
#include<QDebug>
#include<QTimer>
#include<QPushButton>
#include<QLCDNumber>


Block::Block(QWidget *parent): QLabel(parent){

    score= 0;

    s = new QLCDNumber(10,parent);
    s->setSegmentStyle(QLCDNumber::Flat);
    s->setGeometry(150,50,100,40);
    s->display(score);




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
            b[4*i+j]->setStyleSheet("background-color: moccasin;");
            b[4*i+j]->show();
        }
    }

    color[0] = "background-color: moccasin;";
    color[1] = "background-color: bisque;";
    color[2] = "background-color: orange;";
    color[3] = "background-color: darkorange;";
    color[4] = "background-color: goldenrod;";
    color[5] = "background-color: cyan;";
    color[6] = "background-color: deeppink;";
    color[7] = "background-color: tomato;";
    color[8] = "background-color: red;";
    color[9] = "background-color: crimson;";
    color[10] = "background-color: wheat;";
    color[11] = "background-color: navy;";
    color[12] = "background-color: blue;";
    color[13] = "background-color: indigo;";
    color[14] = "background-color: purple;";
    color[15] = "background-color: mediumslateblue;";
    color[16] = "background-color: lightseagreen;";
    color[17] = "background-color: darkslategrey;";
    color[18] = "background-color: green;";
    color[19] = "background-color: darkgreen;";

    value[0] = "<html><head/><body><p><span style=\" font-size:16pt; color:#000000;\">2</span></p></body></html>";
    value[1] = "<html><head/><body><p><span style=\" font-size:16pt; color:#000000;\">4</span></p></body></html>";
    value[2] = "<html><head/><body><p><span style=\" font-size:16pt; color:#000000;\">8</span></p></body></html>";
    value[3] = "<html><head/><body><p><span style=\" font-size:16pt; color:#000000;\">16</span></p></body></html>";
    value[4] = "<html><head/><body><p><span style=\" font-size:16pt; color:#000000;\">32</span></p></body></html>";
    value[5] = "<html><head/><body><p><span style=\" font-size:16pt; color:#000000;\">64</span></p></body></html>";
    value[6] = "<html><head/><body><p><span style=\" font-size:16pt; color:#000000;\">128</span></p></body></html>";
    value[7] = "<html><head/><body><p><span style=\" font-size:16pt; color:#000000;\">256</span></p></body></html>";
    value[8] = "<html><head/><body><p><span style=\" font-size:16pt; color:#000000;\">512</span></p></body></html>";
    value[9] = "<html><head/><body><p><span style=\" font-size:16pt; color:#000000;\">1024</span></p></body></html>";
    value[10] = "<html><head/><body><p><span style=\" font-size:16pt; color:#000000;\">2048</span></p></body></html>";
    value[11] = "<html><head/><body><p><span style=\" font-size:16pt; color:#000000;\">4096</span></p></body></html>";
    value[12] = "<html><head/><body><p><span style=\" font-size:16pt; color:#000000;\">8192</span></p></body></html>";
    value[13] = "<html><head/><body><p><span style=\" font-size:16pt; color:#000000;\">16384</span></p></body></html>";
    value[14] = "<html><head/><body><p><span style=\" font-size:16pt; color:#000000;\">32768</span></p></body></html>";
    value[15] = "<html><head/><body><p><span style=\" font-size:16pt; color:#000000;\">65536</span></p></body></html>";
    value[16] = "<html><head/><body><p><span style=\" font-size:16pt; color:#000000;\">131072</span></p></body></html>";
    value[17] = "<html><head/><body><p><span style=\" font-size:16pt; color:#000000;\">262114</span></p></body></html>";
    value[18] = "<html><head/><body><p><span style=\" font-size:16pt; color:#000000;\">524228</span></p></body></html>";
    value[19] = "<html><head/><body><p><span style=\" font-size:16pt; color:#000000;\">1048456</span></p></body></html>";
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
            rotate();
            rotate();
            movedata();
            rotate();
            rotate();
            generateNewnumber();
            judge();
            hi();
    }
    else if(event->key() == Qt::Key_Down)
    {
            movedata();
            generateNewnumber();
            judge();
            hi();
    }
    else if(event->key()== Qt::Key_Left)
    {
            rotate();
            movedata();
            rotate();
            rotate();
            rotate();
            generateNewnumber();
            judge();
            hi();
    }
    else if(event->key() == Qt::Key_Right)
    {
            rotate();
            rotate();
            rotate();
            movedata();
            rotate();
            generateNewnumber();
            judge();
            hi();
    }
    s->display(score);
}

void Block::game()
{
    score = 0;
    hi();
    reset();
    judge();
    hi();
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
    move();
    merge();
    move();

}

void Block::move()
{

    for(int i=1;i<5;i++)
    {
        for(int j=1;j<5;j++)
        {
            if(current[j][i] == 0 && current[j-1][i]!=0)
            {
                current[j][i] = current[j-1][i];
                current[j-1][i] =0;
                j=1;
            }
        }
    }
}

void Block::merge()
{
    for(int i=1;i<5;i++)
    {
        for(int j=4;j>0;j--)
        {
            if(current[j][i] == current[j-1][i])
            {
                current[j][i] = current[j-1][i] + current[j][i];
                current[j-1][i] =0;
                canmove = 1;
                score = score+current[j][i];
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
    loc_x = 1;
    loc_y = 1;
    while(current[loc_y][loc_x] != 0)
    {
    loc_x = rand()%4+1;
    loc_y = rand()%4+1;
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

void Block::judge()
{
    for(int i=1;i<5;i++)
    {
        for(int j=1;j<5;j++)
        {
           switch(current[i][j]){
            case 2:
               b[4*(i-1)+j-1]->setText(value[0]);
               b[4*(i-1)+j-1]->setStyleSheet(color[0]);
               break;
           case 4:
               b[4*(i-1)+j-1]->setText(value[1]);
               b[4*(i-1)+j-1]->setStyleSheet(color[1]);
               break;
           case 8:
               b[4*(i-1)+j-1]->setText(value[2]);
               b[4*(i-1)+j-1]->setStyleSheet(color[2]);
               break;
           case 16:
               b[4*(i-1)+j-1]->setText(value[3]);
               b[4*(i-1)+j-1]->setStyleSheet(color[3]);
               break;
           case 32:
               b[4*(i-1)+j-1]->setText(value[4]);
               b[4*(i-1)+j-1]->setStyleSheet(color[4]);
               break;
           case 64:
               b[4*(i-1)+j-1]->setText(value[5]);
               b[4*(i-1)+j-1]->setStyleSheet(color[5]);
               break;
           case 128:
               b[4*(i-1)+j-1]->setText(value[6]);
               b[4*(i-1)+j-1]->setStyleSheet(color[6]);
               break;
           case 256:
               b[4*(i-1)+j-1]->setText(value[7]);
               b[4*(i-1)+j-1]->setStyleSheet(color[7]);
               break;
           case 512:
               b[4*(i-1)+j-1]->setText(value[8]);
               b[4*(i-1)+j-1]->setStyleSheet(color[8]);
               break;
           case 1024:
               b[4*(i-1)+j-1]->setText(value[9]);
               b[4*(i-1)+j-1]->setStyleSheet(color[9]);
               break;
           case 2048:
               b[4*(i-1)+j-1]->setText(value[10]);
               b[4*(i-1)+j-1]->setStyleSheet(color[10]);
               break;
           case 4096:
               b[4*(i-1)+j-1]->setText(value[11]);
               b[4*(i-1)+j-1]->setStyleSheet(color[11]);
               break;
           case 8192:
               b[4*(i-1)+j-1]->setText(value[12]);
               b[4*(i-1)+j-1]->setStyleSheet(color[12]);
               break;
           case 16384:
               b[4*(i-1)+j-1]->setText(value[13]);
               b[4*(i-1)+j-1]->setStyleSheet(color[13]);
               break;
           case 32768:
               b[4*(i-1)+j-1]->setText(value[14]);
               b[4*(i-1)+j-1]->setStyleSheet(color[14]);
               break;
           case 65536:
               b[4*(i-1)+j-1]->setText(value[15]);
               b[4*(i-1)+j-1]->setStyleSheet(color[15]);
               break;
           case 131072:
               b[4*(i-1)+j-1]->setText(value[16]);
               b[4*(i-1)+j-1]->setStyleSheet(color[16]);
               break;
           case 262114:
               b[4*(i-1)+j-1]->setText(value[17]);
               b[4*(i-1)+j-1]->setStyleSheet(color[17]);
               break;
           case 524228:
               b[4*(i-1)+j-1]->setText(value[18]);
               b[4*(i-1)+j-1]->setStyleSheet(color[18]);
               break;
           case 1048456:
               b[4*(i-1)+j-1]->setText(value[19]);
               b[4*(i-1)+j-1]->setStyleSheet(color[19]);
               break;

           }

        }
    }
}


