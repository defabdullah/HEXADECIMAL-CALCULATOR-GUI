#ifndef MYBUTTON_H
#define MYBUTTON_H

#include <QPushButton>
#include <QSize>

class MyButton: public QPushButton
{
    Q_OBJECT
public:
    MyButton(const QString& text, QWidget* parent=0);
    QSize btsize;
    QString text;
public slots:
    void addNumtoString();
    void clearResult();
    void plusSign();
    void minusSign();
    void equalSign();
};

#endif // MYBUTTON_H
