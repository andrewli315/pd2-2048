#ifndef BLOCK
#define BLOCK

#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<fstream>
#include<QFile>
#include<QObject>
#include<QLabel>
#include<QWidget>
#include<QString>
#include<QPushButton>
#include<QLCDNumber>
class Block: public QLabel{
    Q_OBJECT
public:
    Block(QWidget * parent =0);
    void reset();
    void keyPressEvent(QKeyEvent *event);
    bool isgameover();
    int current[6][6];
    int score;
    QLabel *b[16];
public slots:
    void game();
private:
    void savefile();
    void readfile();
    void hi();
    void movedata();
    void move();
    void merge();
    void generateNewnumber();
    void rotate();
    void judge();
    bool endofgame();
    int temp[6][6];
    int rot[4][4];
    bool gameover;
    int canmove;
    QFile save;
    QFile fread;
    int newgame;
    QPushButton *reset_button;
    QPushButton *endreset;
    QLabel *endscene;
    QString color[20];
    QString value[20];
    QLCDNumber *s;
};

#endif // BLOCK

