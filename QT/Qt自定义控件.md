# 自定义控件

# 1. 自定义控件封装
- 添加新文件 - Qt - 设计师界面类（.h .cpp. ui）
- .ui中 设计 QSpinBox 和 QSlider 两个控件
- Widget中使用自定义控件，拖拽一个Widget，点击提升为，点击添加，点击提升
- 实现功能，改变数字，滑动条跟着移动，信号槽监听
- 提供getNum和setNum对外接口
- 测试接口


# 2. Qt中的事件
2.1 鼠标事件

2.2 鼠标进入事件 ```enterEvent```

2.3 鼠标离开事件 ```leaveEvent```

2.4 鼠标按下 ```mousePressEvent(QMouseEvent *ev)```

2.5 鼠标释放 ```mouseReleaseEvent```

2.6 鼠标移动 ```mouseMoveEvent```

2.7 ```ev->x()``` x坐标 ```ev->y()``` y坐标

2.8 ```ev->button()``` 可以判断所有按键 ```Qt::LeftButton Qt::RightButton```

2.9 ```ev->buttons()``` 判断组合按键 判断move时候的左右键 可以结合&操作符

2.10 格式化字符串 ```QString("%1 %2").arg(111).arg(222)```