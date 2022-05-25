#include "mainwidget.h"
#include "mybutton.h"
#include "myscreen.h"
#include "convertFunctions.h"
#include <QVBoxLayout>
#include <QGridLayout>
#include <QObject>
#include <QSignalMapper>
#include <iostream>

QString curr="";
QString prev="";
int sign=0;
bool cleared=true;
bool isEqual=true;
bool clr_nums=true;
bool last_button_operator=false;

MainWidget::MainWidget(QWidget *parent)
    : QWidget{parent}
{
    QVBoxLayout *vb = new QVBoxLayout(this); // timer, grid and spaceritem
    QGridLayout *gl = new QGridLayout();
    Screen *screen = new Screen();

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
    setWindowTitle("CALCULATOR");
    resize(640, 480);
}

void Screen::displayResult(){
    if(isEqual && cleared){
        setText("0");
    }
    else{
        setText(curr);
        cleared=false;
    }
}

void Screen::clearScreen(){
    setText(QString("0"));
    curr="";
    prev="";
    sign=0;
    cleared=true;
    last_button_operator=false;
}

void MyButton::clearResult(){
    if(cleared && sign==2){
        curr="-";
    }
    else{
        curr="";
    }
    cleared=false;
    clr_nums=false;
}

void MyButton::plusSign(){
    isEqual=false;
    if(last_button_operator){
        sign=1;
    }else{
        equalSign();
        prev=curr;
        sign=1;
    }
    last_button_operator=true;
}

void MyButton::minusSign(){
    isEqual=false;
    if(last_button_operator){
        sign=2;
    }else{
        equalSign();
        prev=curr;
        sign=2;
    }
    last_button_operator=true;

}

void MyButton::equalSign(){
    if(curr.toStdString()==""){
        return;
    }
    int prev_decimal = convert_integer(prev.toStdString());
    int curr_decimal = convert_integer(curr.toStdString());
    int result_decimal;

    if(sign==1){
        result_decimal =  prev_decimal + curr_decimal;
        std :: string str=convert_string(result_decimal);
        prev=curr;
        curr=QString::fromStdString(str);
        sign=0;

    }

    else if(sign==2){
        if(prev.toStdString()==""){
            result_decimal=curr_decimal;
        }
        else{
            result_decimal =  prev_decimal - curr_decimal;
        }
        std :: string str=convert_string(result_decimal);
        curr=QString::fromStdString(str);
        sign=0;
    }
    if(isEqual){
        clr_nums=true;
    }
    isEqual=true;
    last_button_operator=false;
}

void MyButton::addNumtoString(){
    isEqual=false;
    if(clr_nums){
        curr="";
        prev="";
        sign=0;
        cleared=true;
        clr_nums=false;
    }
    last_button_operator=false;
    curr= curr + this->text;
}
