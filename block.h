#ifndef BLOCK
#define BLOCK

#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<QObject>
#include<QLabel>
#include<Qwidget>

class Block: public QLabel{
    Q_OBJECT
public:
    Block(QWidget * parent =0);
    void reset();
    void keyPressEvent(QKeyEvent *event);
    void game();
    bool isgameover();
    int current[6][6];
    QLabel *b[16];
private:
    void hi();
    void movedata();
    void generateNewnumber();
    void rotate();
    int canmove;
    int score;

};

#endif // BLOCK

