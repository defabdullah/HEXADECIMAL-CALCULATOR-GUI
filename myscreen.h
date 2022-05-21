#ifndef MYSCREEN_H
#define MYSCREEN_H

#include <QLabel>
#include <QSize>
#include <QFont>
#include <iostream>

class Screen : public QLabel
{
    Q_OBJECT
public:
    Screen(const char* text,QWidget *parent = 0);
    QFont myFont;
    QSize resSize;
public slots:
    void displayResult();
    void clearScreen();
};


#endif // MYSCREEN_H
