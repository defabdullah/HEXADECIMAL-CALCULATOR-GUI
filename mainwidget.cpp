#include "mainwidget.h"
#include "mybutton.h"
#include "myscreen.h"
#include <QVBoxLayout>
#include <QGridLayout>
#include <QObject>
#include <QSignalMapper>

QString curr="";
QString prev="";
int sign=0;

MainWidget::MainWidget(QWidget *parent)
    : QWidget{parent}
{
    QVBoxLayout *vb = new QVBoxLayout(this); // timer, grid and spaceritem
    QGridLayout *gl = new QGridLayout();
    Screen *screen = new Screen("88");

    const char* buttonNames[20]={"+","-","=","Clr",
                              "0","1","2","3",
                              "4","5","6","7",
                              "8","9","A","B",
                              "C","D","E","F"
                             };
    for(int row=0; row<5; row++){
        for(int col=0; col<4; col++){
            int num=(row*4+col);
            const char *buttonText=buttonNames[num];
            MyButton *button = new MyButton(QString(buttonText));
            if(row!=0){
                QObject::connect(button,SIGNAL(clicked()),button,SLOT(addNumtoString()));
                QObject::connect(button,SIGNAL(clicked()),screen, SLOT(displayResult()));
            }
            else if(col==0){
                QObject::connect(button,SIGNAL(clicked()),button, SLOT(plusSign()));
                QObject::connect(button,SIGNAL(clicked()),button, SLOT(clearResult()));
            }
            else if(col==1){
                QObject::connect(button,SIGNAL(clicked()),button, SLOT(minusSign()));
                QObject::connect(button,SIGNAL(clicked()),button, SLOT(clearResult()));
            }
            else if(col==2){
                QObject::connect(button,SIGNAL(clicked()),button, SLOT(equalSign()));
                QObject::connect(button,SIGNAL(clicked()),screen, SLOT(displayResult()));
            }
            else if(col==3){
                QObject::connect(button,SIGNAL(clicked()),screen, SLOT(clearScreen()));
            }
            gl->addWidget(button, row, col, 1,1);
        }
    }



    vb->addWidget(screen);
    vb->addLayout(gl);
    setWindowTitle("Color Game");
    resize(640, 480);
}

void Screen::displayResult(){
    setText(curr);
}

void Screen::clearScreen(){
    setText(QString("0"));
    curr="";
    prev="";
    sign=0;
}

void MyButton::clearResult(){
    curr="";
}

void MyButton::plusSign(){
    sign=1;
    prev=curr;
}

void MyButton::minusSign(){
    sign=2;
    prev=curr;
}

void MyButton::equalSign(){
    if(sign==1){
        std::string str=std::to_string(std::stoi(prev.toStdString())+std::stoi(curr.toStdString()));
        curr=QString::fromStdString(str);
    }
    if(sign==2){
        std::string str=std::to_string(std::stoi(prev.toStdString())-std::stoi(curr.toStdString()));
        curr=QString::fromStdString(str);
    }
}

void MyButton::addNumtoString(){
    curr= curr + this->text;
}


//void MyButton::
