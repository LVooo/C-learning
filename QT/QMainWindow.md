# QMainWindow

# 1. QMainWindow
1.1 菜单栏 最多有一个
```cpp
// 菜单栏 只能最多有一个
// 菜单栏创建
QMenuBar * bar = menuBar();
// 将菜单栏放入到窗口中
setMenuBar(bar);

// 创建菜单
QMenu *fileMenu = bar->addMenu("文件");
QMenu *editMenu = bar->addMenu("编辑");

// 创建菜单项
QAction *newAction = fileMenu->addAction("新建");
// 添加分隔符
fileMenu->addSeparator();
QAction *openAction = fileMenu->addAction("打开");
```

1.2 工具栏 可以有多个
```cpp
// 工具栏 可以有多个
QToolBar *toolBar = new QToolBar(this);
addToolBar(Qt::LeftToolBarArea, toolBar);

// 后期设置 只允许 左右停靠
toolBar->setAllowedAreas(Qt::LeftToolBarArea | Qt::RightToolBarArea);

// 设置浮动
toolBar->setFloatable(false);

// 设置移动 (总开关)
toolBar->setMovable(false);

// 工具栏中可以设置内容
toolBar->addAction(newAction);
toolBar->addSeparator();
toolBar->addAction(openAction);
// 工具栏中添加控件
QPushButton *btn = new QPushButton("aa", this);
toolBar->addWidget(btn);
```

1.3 状态栏 最多有一个
```cpp
// 状态栏 最多有一个
QStatusBar *stBar = statusBar();
// 设置到窗口中
setStatusBar(stBar);
// 放标签控件
QLabel *label = new QLabel("提示信息", this);
stBar->addWidget(label);

QLabel *label2 = new QLabel("右侧提示信息", this);
stBar->addPermanentWidget(label2);
```

1.4 铆接部件 浮动窗口 可以多个
```cpp
// 铆接部件（浮动窗口）可以有多个
QDockWidget *dockWidget = new QDockWidget("浮动", this);
addDockWidget(Qt::BottomDockWidgetArea, dockWidget);
// 设置后期停靠区域，只允许上下
dockWidget->setAllowedAreas(Qt::TopDockWidgetArea | Qt::BottomDockWidgetArea);
```

1.5 设置核心部件 只能一个
```cpp
// 设置中心部件
QTextEdit *edit = new QTextEdit(this);
setCentralWidget(edit);
```


# 2. 资源文件
2.1 将图片文件 拷贝到项目位置下

2.2 右键项目->添加新文件->Qt->Qt resource File->给资源文件起名

2.3 res 生成 res.qrc

2.4 open in editor 编辑资源

2.5 添加前缀 添加文件

2.6 使用 ": + 前缀名 + 文件名"


# 3. 对话框
3.1 分类
- 模态对话框 不可以对其他窗口进行操作
    - ```QDialog dlg(this)```
    - ```dlg.exec();```

- 非模态对话框 可以对其他窗口进行操作
    - 防止一闪而过 创建到堆区
    - ```QDialog *dlg = new QDialog(this)```
    - ```dlg->show()```
    - ```dlg->setAttribute(Qt::WA_DeleteOnClose); // 55号属性```

3.2 标准对话框 - 消息对话框
- QMessageBox **静态成员函数** 创建对话框
- 错误、信息、提问、警告
- 参数1：父亲 参数2：标题 参数3：显示内容 参数4：按键类型 参数5：默认关联回车按键
- 返回值 也是StandardButton类型，利用返回值判断用户输入

3.3 其他标准对话框
- 颜色对话框 QColorDialog::getColor
- 文件对话框 QFileDialog::getOpenFileName(父亲，标题，默认路径，过滤文件)
- 字体对话框 QFontDialog::getFont


# 4. 界面布局
4.1 实现登录窗口

4.2 利用布局方式 给窗口进行美化

4.3 选取widget进行布局，水平布局、垂直布局、栅格布局

4.4 给用户名、密码、登录、退出按钮进行布局

4.5 默认窗口和控件之间有间隙，可以调整layoutLeftMargin

4.6 利用弹簧进行布局

4.7 框架高度调整sizePolicy


# 5. 控件
5.1 按钮组
- QPushButton 常用按钮
- QToolButton 工具按钮 用于显示图片，若想显示文字，修改风格：toolButtonStyle，凸起风格：autoRaise
- radioButton 单选按钮，设置默认```ui->rBtnMan->setChecked(true);```
- checkbox 多选按钮，监听状态，2是选中 0是未选 1是半选

5.2 QListWidget 列表容器
- QListWidgetItem *item 一行内容
- ui->listWidget->addItem(item)
- 设置居中方式```item->setTextAlignment(Qt::AlignCenter);```
- 可以利用addItems一次性添加整首诗

5.3 QTreeWidget 树控件
- 设置头
    - ```ui->treeWidget->setHeaderLabels(QStringList() << "英雄" << "英雄介绍");```
- 创建根节点
    - ```QTreeWidgetItem *liItem = new QTreeWidgetItem(QStringList() << "力量");```
- 添加根节点 到 树控件上
    - ```ui->treeWidget->addTopLevelItem(liItem);```
- 添加子节点
    - ```liItem->addChild(l1);```

5.4 QTableWidget 表格控件
- 设置列数
    - ```ui->tableWidget->setColumnCount(3);```
- 设置水平表头
    - ```ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "姓名" << "性别" << "年龄");```
- 设置行数
    - ```ui->tableWidget->setRowCount(5);```
- 设置正文
    - ```ui->tableWidget->setItem(0, 0, new QTableWidgetItem("亚瑟"));```

5.5 其他控件介绍
- stackedWidget 栈控件
    - ```ui->stackedWidget->setCurrentIndex(0);```
- 下拉框
    - ```ui->comboBox->addItem("奔驰");```
- QLabel 显示图片
    - ```ui->lbl_Image->setPixmap(QPixmap(":/image/newIcon.png"));```
- QLabel 显示动图 gif图片
    - ```ui->lbl_movie->setMovie(movie);```
    - ```movie->start();```