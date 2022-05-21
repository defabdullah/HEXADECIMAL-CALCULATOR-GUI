#include "mybutton.h"

MyButton::MyButton(const QString& text,
                         QWidget* parent):
    QPushButton(text, parent)
{
    this->text=text;
    btsize = QSize(150, 100);
    setFixedSize(btsize);
    setText(QString(text));
}
