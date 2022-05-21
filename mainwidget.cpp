#include "mainwidget.h"
#include "mybutton.h"
#include "myscreen.h"
#include <QVBoxLayout>
#include <QGridLayout>
#include <QObject>
#include <QSignalMapper>

QString res="";

MainWidget::MainWidget(QWidget *parent)
    : QWidget{parent}
{
    QVBoxLayout *vb = new QVBoxLayout(this); // timer, grid and spaceritem
    QGridLayout *gl = new QGridLayout();
    Screen *result = new Screen("88");

    char* buttonNames[20]={"+","-","=","Clr",
                              "0","1","2","3",
                              "4","5","6","7",
                              "8","9","A","B",
                              "C","D","E","F"
                             };
    for(int row=0; row<5; row++){
        for(int col=0; col<4; col++){
            int num=(row*4+col);
            char *buttonText=buttonNames[num];
            MyButton *button = new MyButton(QString(buttonText));
            if(row!=0){
                QObject::connect(button,SIGNAL(clicked()),button,SLOT(addStr()));
                QObject::connect(button,SIGNAL(clicked()),result, SLOT(displayResult()));
            }
            else if(col==3){
                QObject::connect(button,SIGNAL(clicked()),result, SLOT(clearResult()));
            }
            gl->addWidget(button, row, col, 1,1);
        }
    }



    vb->addWidget(result);
    vb->addLayout(gl);
    setWindowTitle("Color Game");
    resize(640, 480);
}

void Screen::displayResult(){
    setText(res);
}

void Screen::clearResult(){
    setText(QString("0"));
}

void MyButton::addStr(){
    res= res + this->text;
}

