#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMovie>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 栈控件使用
    // 设置默认为0
    ui->stackedWidget->setCurrentIndex(0);

    // scrollArea按钮
    connect(ui->btn_scrollArea, &QPushButton::clicked, [=](){
        ui->stackedWidget->setCurrentIndex(0);
    });

    // toolBox按钮
    connect(ui->btn_ToolBox, &QPushButton::clicked, [=](){
        ui->stackedWidget->setCurrentIndex(1);
    });

    // TabWidget按钮
    connect(ui->btn_TabWidget, &QPushButton::clicked, [=](){
        ui->stackedWidget->setCurrentIndex(2);
    });

    // 下拉框
    ui->comboBox->addItem("奔驰");
    ui->comboBox->addItem("宝马");
    ui->comboBox->addItem("拖拉机");

    // 点击按钮 选中拖拉机
    connect(ui->btn_select, &QPushButton::clicked, [=](){
//        ui->comboBox->setCurrentIndex(2);
        ui->comboBox->setCurrentText("拖拉机");
    });

    // 利用QLabel显示图片
    ui->lbl_Image->setPixmap(QPixmap(":/image/newIcon.png"));

    // 利用QLabel显示gif动态图片
    QMovie *movie = new QMovie(":/image/movie.gif");
    ui->lbl_movie->setMovie(movie);
    // 播放动图
    movie->start();
}

MainWindow::~MainWindow()
{
    delete ui;
}
