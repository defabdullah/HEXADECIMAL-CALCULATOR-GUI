#include "myscreen.h"
#include <QDebug>
#include<iostream>
Screen::Screen(const char* text,QWidget *parent)
    :QLabel(parent)
{
    resSize = QSize(640, 100);
    setText(text);
    setFixedSize(resSize);
    myFont = this->font();
    myFont.setPointSize(75);
    setFont(myFont);
    setAlignment(Qt::AlignRight);
}
