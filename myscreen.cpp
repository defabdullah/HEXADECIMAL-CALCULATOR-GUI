#include "myscreen.h"
Screen::Screen(QWidget *parent)
    :QLabel(parent)
{
    resSize = QSize(640, 100);
    setText("0");
    setFixedSize(resSize);
    myFont = this->font();
    myFont.setPointSize(75);
    setFont(myFont);
    setAlignment(Qt::AlignRight);
}
