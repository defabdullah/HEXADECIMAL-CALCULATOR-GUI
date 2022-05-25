#ifndef MAINWIDGET_H
#define MAINWIDGET_H
#include <QWidget>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QObject>
#include <QSignalMapper>
#include <iostream>
#include <string>

class MainWidget : public QWidget
{
    Q_OBJECT
public:
    MainWidget(QWidget *parent = nullptr);
};

#endif // MAINWIDGET_H
