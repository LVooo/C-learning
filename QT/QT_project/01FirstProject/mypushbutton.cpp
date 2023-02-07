#include "mypushbutton.h"
#include <QDebug>

MyPushButton::MyPushButton(QWidget *parent) : QPushButton(parent)
{
    qDebug("我的按钮构造类调用");
}

MyPushButton::~MyPushButton()
{
    qDebug("我的按钮析构调用");
}
