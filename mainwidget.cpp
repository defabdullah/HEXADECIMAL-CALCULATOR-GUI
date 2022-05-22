#include "mainwidget.h"
#include "mybutton.h"
#include "myscreen.h"
#include <QVBoxLayout>
#include <QGridLayout>
#include <QObject>
#include <QSignalMapper>
#include <iostream>

QString curr="";
QString prev="";
int sign=0;
int last_sign_equal=0;
int last_element=0;
int power(int a,int b){
        int result=1;
        for(int i=0;i<b;i++){
                result*=a;
        }
        return result;
}

int convert_integer(std::string number) {
    int size = number.length();
    int result=0;
    for(int i=0;i<size;i++){
            if(number[size-i-1]=='1'){
                    result= power(16,i) * 1 + result;
            }else if(number[size-i-1]=='2'){
                    result= power(16,i) * 2 + result;
            }else if(number[size-i-1]=='3'){
                    result= power(16,i) * 3 + result;
            }else if(number[size-i-1]=='4'){
                    result= power(16,i) * 4 + result;
            }else if(number[size-i-1]=='5'){
                    result= power(16,i) * 5 + result;
            }else if(number[size-i-1]=='6'){
                    result= power(16,i) * 6 + result;
            }else if(number[size-i-1]=='7'){
                    result= power(16,i) * 7 + result;
            }else if(number[size-i-1]=='8'){
                    result= power(16,i) * 8 + result;
            }else if(number[size-i-1]=='9'){
                    result= power(16,i) * 9 + result;
            }else if(number[size-i-1]=='A'){
                    result= power(16,i) * 10 + result;
            }else if(number[size-i-1]=='B'){
                    result= power(16,i) * 11 + result;
            }else if(number[size-i-1]=='C'){
                    result= power(16,i) * 12 + result;
            }else if(number[size-i-1]=='D'){
                    result= power(16,i) * 13 + result;
            }else if(number[size-i-1]=='E'){
                    result= power(16,i) * 14 + result;
            }else if(number[size-i-1]=='F'){
                    result= power(16,i) * 15 + result;
           }
    }
   if(number[0]=='-'){
            result*=-1;
    }
    return result;
}

std::string convert_string(int number) {
        char hexaDeciNum[100];
        char result[100];
        std::string result_str;
        int i =0;
        int  is_negative=0;
        if(number==0){
                return "0";
        }else if(number<0){
                number *=-1;
                is_negative=1;
        }
        while (number != 0) {
        // temporary variable to store remainder
        int temp = 0;
        // storing remainder in temp variable.
        temp = number % 16;
        // check if temp < 10
        if (temp < 10) {
            hexaDeciNum[i] = temp + 48;
            i++;
        }
        else {
            hexaDeciNum[i] = temp + 55;
            i++;
        }
        number = number / 16;
    }
    if(is_negative){
            hexaDeciNum[i]='-';
            hexaDeciNum[i+1]='\0';
            int j=1;
            i=i+1;
            for(;j<i+1;j++){
                result[j-1]=hexaDeciNum[i-j];
            }
            result[j-1]='\0';
    }else{
            hexaDeciNum[i]='\0';
            int j=1;
            for(;j<i+1;j++){
                result[j-1]=hexaDeciNum[i-j];
            }
            result[j-1]='\0';
    }
    result_str =result;
    return result_str;
}

MainWidget::MainWidget(QWidget *parent)
    : QWidget{parent}
{
    QVBoxLayout *vb = new QVBoxLayout(this); // timer, grid and spaceritem
    QGridLayout *gl = new QGridLayout();
    Screen *screen = new Screen("0");

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
    setWindowTitle("BATUHAN ILHAN");
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
    last_sign_equal=0;

}

void MyButton::clearResult(){
    curr="";
    last_sign_equal=0;
}

void MyButton::plusSign(){
    sign=1;
    prev=curr;
    last_sign_equal=0;
}

void MyButton::minusSign(){
        sign=2;
        prev=curr;
        last_sign_equal=0;

}

void MyButton::equalSign(){
    int prev_decimal = convert_integer(prev.toStdString());
    int curr_decimal = convert_integer(curr.toStdString());
    if(sign==1){
        int result_decimal =  prev_decimal + curr_decimal;
        std :: string str=convert_string(result_decimal);
        if(last_sign_equal){
            curr=QString::fromStdString(str);
        }else{
            prev=curr;
            curr=QString::fromStdString(str);
        }

    }
    else if(sign==2){
        if(last_sign_equal){
            int result_decimal =  curr_decimal - last_element;
            std :: string str=convert_string(result_decimal);
            curr=QString::fromStdString(str);

        }else{
            int result_decimal =  prev_decimal - curr_decimal;
            std :: string str=convert_string(result_decimal);
            curr=QString::fromStdString(str);
            last_element=curr_decimal;
        }
    }else if(sign==0){
        curr=QString::fromStdString("0");
    }
    last_sign_equal=1;
}

void MyButton::addNumtoString(){
    last_sign_equal=0;
    curr= curr + this->text;
}


//void MyButton::
