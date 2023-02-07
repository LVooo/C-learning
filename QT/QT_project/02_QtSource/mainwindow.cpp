#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

//    ui->actionNew->setIcon(QIcon("D:/image/newIcon.png"));

    // 使用添加Qt资源 ": + 前缀名 + 文件名"
    ui->actionNew->setIcon(QIcon(":/image/newIcon"));
    ui->actionOpen->setIcon(QIcon(":/image/openIcon"));
}

MainWindow::~MainWindow()
{
    delete ui;
}
