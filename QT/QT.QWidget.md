# QT Learning

# 1. Qt简介
1.1 **跨平台图形界面**引擎

1.2 奇趣科技创造

1.3 优点
- 跨平台
- 接口简单，易上手
- 一定程度上简化了内存回收

1.4 版本
- 商业版
- 开源版

1.5 成功案例
- Linux桌面环境 KDE
- 谷歌地图
- 多媒体播放器
- ...


# 2. 创建第一个QT程序
2.1 默认创建窗口类，myWidget，基类有三种选择：QWidget、QMainWindow、QDialog

2.2 main函数：  
- QApplication a    应用程序对象，有且仅有一个
- myWidget w;   实例化窗口对象
- w.show();     调用show函数 显示窗口
- return a.exec()   让应用程序对象进入消息循环机制中，代码阻塞到当前行


# 3. 常用API
```cpp
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
```


# 4. 对象树
4.1 当创建的对象在堆区时，如果指定的父亲时QObject派生下来的类或者QObject子类派生下来的类，可以不用管理释放的操作，对象会放入到对象树当中

4.2 一定程度上简化了**内存回收机制**


# 5. QT中的坐标系
5.1 左上角为0，0点

5.2 x往右为正方向

5.3 y往下为正方向


# 6. 信号和槽
6.1 连接函数：```connect```

6.2 参数
```cpp
    // 需求 点击我的按钮 关闭窗口
    // 参数1：信号的发送者 参数2：发送的信号(函数的地址) 参数3：信号的接收者 参数4：处理的槽函数
    // connect(myBtn, &QPushButton::clicked, this, &QWidget::close);
    connect(myBtn, &MyPushButton::clicked, this, &myWidget::close);
```

6.3 **松散耦合**的概念：发送端和接收端本无联系，通过一个链接将他们联系起来

6.4 ```connect(btn, &QPushButton::clicked, this, &QWidget::close);```


# 7. 自定义信号和槽
7.1 自定义信号
- 写到```signals```下
- 返回void
- 需要声明，不需要实现
- 可以有参数，可以重载

7.2 自定义槽函数
- 返回void
- 需要声明，也需要实现
- 可以有参数，可以重载
- 写到```public slot```下或```public```或**全局函数**

7.3 触发自定义的信号
- ```emit```自定义信号

7.4 案例
- 下课后，老师触发饿了信号，学生响应信号，请客吃饭  
```connect(zt, &Teacher::hungry, st, &Student::treat);```


# 8. 当自定义信号和槽出现重载
8.1 需要利用函数指针 明确指向函数的地址

8.2 ```void(Teacher::*teacherSignal)(QString) = Teacher::hungry;```

8.3 QString转成char*
- .ToUtf8()转为QByteArray
- .data()转为char*


# 9. 扩展
9.1 信号可以连接信号

9.2 一个信号可以连接多个槽函数

9.3 多个信号可以连接同一个槽

9.4 信号和槽函数的参数必须类型一一对应

9.5 信号和槽的参数个数 是不是要一致？信号的参数个数 可以多于槽函数的参数个数

9.6 信号槽可以断开连接 disconnect


# 10. Qt4版本写法
10.1 ```connect(信号的发送者，发送的信号SIGNAL(信号)，信号接收者，槽函数SLOT(槽函数))```

10.2 优点：参数直观

10.3 缺点：编译器不会检测参数类型


# 11. Lambada表达式
11.1 []标识符 匿名函数
- = 值传递
- & 引用传递

11.2 () 参数

11.3 {} 实现体

11.4 mutable 修饰 值传递变量，可以修改拷贝出的数据，改变不了本体

11.5 返回值 []() -> int{}

11.6 小案例：使用一个按钮控制另一个窗口的打开关闭，按钮文字随之变化开关
```cpp
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
```


