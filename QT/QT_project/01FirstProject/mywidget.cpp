#include "mywidget.h"
#include <QPushButton> //按钮控件的头文件
#include "mypushbutton.h"
#include <QDebug>

myWidget::myWidget(QWidget *parent)
    : QWidget(parent)
{
    //创建一个按钮
    QPushButton *btn = new QPushButton;
    btn->show(); //show以顶层方式弹出窗口控件

    //让btn对象 依赖在myWidget窗口中
    btn->setParent(this);

    //显示文本
    btn->setText("第一个按钮");
    btn->move(0, 0);

    // 创建第二个按钮 按照控件的大小创建窗口
    QPushButton *btn2 = new QPushButton("第二个按钮", this);

    // 移动btn2按钮
    btn2->move(100, 100);

    // btn也可以重新指定大小
    btn2->resize(100, 100);

    // 重置窗口大小
    resize(600, 400);

    // 设置固定窗口大小，不可以拉伸
    setFixedSize(600, 400);

    // 设置窗口标题
    setWindowTitle("第一个窗口");


    // 创建一个自己的按钮对象
    MyPushButton *myBtn = new MyPushButton;
    myBtn->setText("我自己的按钮");

    myBtn->move(100, 0);
    myBtn->setParent(this); // 设置到对象树中


    // 需求 点击我的按钮 关闭窗口
    // 参数1：信号的发送者 参数2：发送的信号(函数的地址) 参数3：信号的接收者 参数4：处理的槽函数
//    connect(myBtn, &QPushButton::clicked, this, &QWidget::close);
    connect(myBtn, &MyPushButton::clicked, this, &myWidget::close);
}

myWidget::~myWidget()
{
    qDebug() << "MyWidget析构调用";
}
