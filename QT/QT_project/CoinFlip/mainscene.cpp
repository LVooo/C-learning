#include "mainscene.h"
#include "ui_mainscene.h"
#include <QPainter>
#include "mypushbutton.h"
#include <QDebug>
#include <QTimer>
#include <QLabel>
#include <QSound> // 多媒体模块下的音效头文件

MainScene::MainScene(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainScene)
{
    ui->setupUi(this);

    // 配置主场景

    // 设置固定大小
    setFixedSize(320, 588);

    // 设置图标
    setWindowIcon(QIcon(":/res/Coin0001.png"));

    // 设置标题
    setWindowTitle("翻金币主场景");

    // 退出按钮实现
    connect(ui->actionQuit, &QAction::triggered, [=](){
        this->close();
    });

    // 准备开始按钮的音效
    QSound *startSound = new QSound(":res/TapButtonSound.wav", this);

    // 开始按钮
    MyPushButton *startBtn = new MyPushButton(":/res/MenuSceneStartButton.png");
    startBtn->setParent(this);
    startBtn->move(this->width()*0.5 - startBtn->width()*0.5, this->height()*0.7);

    connect(startBtn, &MyPushButton::clicked, [=](){

        // 播放开始音效资源
        startSound->play();

        // 弹起动画特效
        startBtn->zoom1();
        startBtn->zoom2();

        // 实例化选择关卡场景
        chooseScene = new ChooseLevelScene;

        // 监听选择关卡的返回按钮的信号
        connect(chooseScene, &ChooseLevelScene::chooseSceneBack, [=](){
            this->setGeometry(chooseScene->geometry());
            this->show();
            chooseScene->hide();
        });

        // 延时进入到选择关卡场景
        QTimer::singleShot(500, this, [=](){
            // 自身隐藏
            this->hide();
            // 设置chooseScene场景的位置
            chooseScene->setGeometry(this->geometry());
            // 显示选择关卡场景
            chooseScene->show();
        });
    });
}

void MainScene::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/res/PlayLevelSceneBg.png");
    painter.drawPixmap(0, 0, this->width(), this->height(), pix);

    // 画背景上图标
    pix.load(":/res/Title.png");

    pix = pix.scaled(pix.width()*0.5, pix.height()*0.5);

    painter.drawPixmap(10, 30, pix);
}

MainScene::~MainScene()
{
    delete ui;
}
