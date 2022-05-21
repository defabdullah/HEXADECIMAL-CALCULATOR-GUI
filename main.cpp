#include "mainwidget.h"
#include <QApplication>

int main(int argc, char *argv[]){
    QApplication app(argc, argv);
    MainWidget *cw=new MainWidget();
    cw->show();
    return app.exec();
}


