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