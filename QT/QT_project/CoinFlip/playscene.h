#ifndef PLAYSCENE_H
#define PLAYSCENE_H

#include <QMainWindow>
#include "mycoin.h"

class PlayScene : public QMainWindow
{
    Q_OBJECT
public:
//    explicit PlayScene(QWidget *parent = 0);

    PlayScene(int levelNum);

    int levelIndex; // 内部成员属性 记录所选的关卡

    // 重写paintEvent事件
    void paintEvent(QPaintEvent *);

    int gameArray[4][4]; // 二维数组 维护每个关卡的具体数据

    MyCoin *coinBtn[4][4]; // 维护金币数组

    // 是否胜利的标志
    bool isWin;

signals:
    void chooseSceneBack();

public slots:
};

#endif // PLAYSCENE_H
