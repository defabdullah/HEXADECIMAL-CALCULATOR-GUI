#include "mybutton.h"

MyButton::MyButton(const QString& text,
                         QWidget* parent):
    QPushButton(text, parent)
{
    setAutoFillBackground(true);
    QPalette palette = this->palette();
    palette.setColor(QPalette::Window, QColor(Qt::green));
    setPalette(palette);
    this->text=text;
    btsize = QSize(150, 100);
    setFixedSize(btsize);
    setText(QString(text));
}
