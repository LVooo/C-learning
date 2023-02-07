#include "widget.h"
#include "ui_widget.h"
#include <QPushButton>
#include <QDebug>

// Teacher 类 老师类
// Student 类 学生类
// 下课后，老师会触发一个信号，饿了，学生响应信号，请客吃饭

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 创建一个老师对象
    this->zt = new Teacher(this);

    // 创建一个学生对象
    this->st = new Student(this);

//    // 老师饿了，学生请客的连接
//    connect(zt, &Teacher::hungry, st, &Student::treat);

//    // 调用下课函数
//    classIsOver();


    // 连接带参数的 信号和槽
    // 指针 -> 地址
    // 函数指针 -> 函数地址

    void (Teacher:: *teacherSingal)(QString) = Teacher::hungry;
    void (Student:: *studentSlot)(QString) = Student::treat;

    // 连接带参数的 信号和槽
    connect(zt, teacherSingal, st, studentSlot);
//    classIsOver();


    // 点击一个 下课的按钮，再触发下课
//    QPushButton *btn = new QPushButton("下课", this);
    // 重置窗口大小
//    this->resize(600, 400);
    // 点击按钮 触发下课
//    connect(btn, &QPushButton::clicked, this, &Widget::classIsOver);

    // 无参的信号和槽
    void (Teacher:: *teacherSingal2)() = Teacher::hungry;
    void (Student:: *studentSlot2)() = Student::treat;
//    connect(zt, teacherSingal2, st, studentSlot2);

    // 信号连接信号
//    connect(btn, &QPushButton::clicked, zt, teacherSingal2);

    // 断开信号
//    disconnect(zt, teacherSingal2, st, studentSlot2);

    // 拓展
    // 1、信号是可以连接信号
    // 2、一个信号可以连接多个槽函数
    // 3、多个信号可以连接同一个槽函数
    // 4、信号和槽函数的参数必须类型一一对应
    // 5、信号和槽的参数个数 是不是要一致？信号的参数个数 可以多于槽函数的参数个数

    // QT4版本以前的信号和槽连接方式
    // 利用QT4信号槽 连接无参版本
    // QT4版本 底层SIGNAL("hungry") SLOT("treat") 内部转化成字符串所以没有参数 检测
//    connect(zt, SIGNAL(hungry()), st, SLOT(treat()));
    // QT4版本优点：参数直观，缺点：类型不做检测
    // QT5以上 支持QT4版本的写法，反之不支持


    // 利用lambada表达式 实现点击按钮 关闭窗口
//    [=](){
//        btn->setText("aaa");
//    }();
    //    QPushButton *btn2 = new QPushButton;
    //    btn2->setText("关闭");
    //    btn2->move(100, 0);
    //    btn2->setParent(this);
    //    connect(btn2, &QPushButton::clicked, [=](){
    //        this->close();
    //        emit zt->hungry("宫保鸡");
    //        btn2->setText("bbb");
    //    });

    QWidget *w1 = new QWidget;
    QPushButton *btn = new QPushButton("open", this);
    this->resize(500, 400);
    btn->move(200, 200);

    connect(btn, &QPushButton::clicked, w1, [=](){
        if (btn->text() == "open")
        {
            w1->show();
            btn->setText("close");
        }
        else
        {
            w1->close();
            btn->setText("open");
        }
    });
}

void Widget::classIsOver()
{
    // 下课函数，调用后触发老师饿了的信号
//    emit zt->hungry();
    emit zt->hungry("宫保鸡丁");
}

Widget::~Widget()
{
    delete ui;
}
