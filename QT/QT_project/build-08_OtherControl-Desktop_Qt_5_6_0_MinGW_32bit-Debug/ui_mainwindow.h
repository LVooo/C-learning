/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QScrollBar>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QStackedWidget *stackedWidget;
    QWidget *page_4;
    QVBoxLayout *verticalLayout_2;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_3;
    QPushButton *pushButton_2;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QPushButton *pushButton_12;
    QPushButton *pushButton_11;
    QPushButton *pushButton_10;
    QPushButton *pushButton_9;
    QWidget *page_5;
    QToolBox *toolBox;
    QWidget *page;
    QPushButton *pushButton_13;
    QWidget *page_2;
    QToolButton *toolButton;
    QWidget *page_3;
    QToolButton *toolButton_2;
    QWidget *page_6;
    QTabWidget *tabWidget;
    QWidget *tab_3;
    QWidget *tab_4;
    QWidget *tab_5;
    QPushButton *btn_scrollArea;
    QPushButton *btn_ToolBox;
    QPushButton *btn_TabWidget;
    QComboBox *comboBox;
    QPushButton *btn_select;
    QLineEdit *lineEdit;
    QTimeEdit *timeEdit;
    QDateEdit *dateEdit;
    QScrollBar *horizontalScrollBar;
    QScrollBar *verticalScrollBar;
    QSlider *horizontalSlider;
    QSpinBox *spinBox;
    QLabel *lbl_Image;
    QLabel *lbl_movie;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(930, 656);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        stackedWidget = new QStackedWidget(centralWidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(50, 20, 231, 251));
        page_4 = new QWidget();
        page_4->setObjectName(QStringLiteral("page_4"));
        verticalLayout_2 = new QVBoxLayout(page_4);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        scrollArea = new QScrollArea(page_4);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, -78, 216, 435));
        verticalLayout = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        pushButton = new QPushButton(scrollAreaWidgetContents);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout->addWidget(pushButton);

        pushButton_3 = new QPushButton(scrollAreaWidgetContents);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        verticalLayout->addWidget(pushButton_3);

        pushButton_2 = new QPushButton(scrollAreaWidgetContents);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        verticalLayout->addWidget(pushButton_2);

        pushButton_4 = new QPushButton(scrollAreaWidgetContents);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));

        verticalLayout->addWidget(pushButton_4);

        pushButton_5 = new QPushButton(scrollAreaWidgetContents);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));

        verticalLayout->addWidget(pushButton_5);

        pushButton_6 = new QPushButton(scrollAreaWidgetContents);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));

        verticalLayout->addWidget(pushButton_6);

        pushButton_7 = new QPushButton(scrollAreaWidgetContents);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));

        verticalLayout->addWidget(pushButton_7);

        pushButton_8 = new QPushButton(scrollAreaWidgetContents);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));

        verticalLayout->addWidget(pushButton_8);

        pushButton_12 = new QPushButton(scrollAreaWidgetContents);
        pushButton_12->setObjectName(QStringLiteral("pushButton_12"));

        verticalLayout->addWidget(pushButton_12);

        pushButton_11 = new QPushButton(scrollAreaWidgetContents);
        pushButton_11->setObjectName(QStringLiteral("pushButton_11"));

        verticalLayout->addWidget(pushButton_11);

        pushButton_10 = new QPushButton(scrollAreaWidgetContents);
        pushButton_10->setObjectName(QStringLiteral("pushButton_10"));

        verticalLayout->addWidget(pushButton_10);

        pushButton_9 = new QPushButton(scrollAreaWidgetContents);
        pushButton_9->setObjectName(QStringLiteral("pushButton_9"));

        verticalLayout->addWidget(pushButton_9);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout_2->addWidget(scrollArea);

        stackedWidget->addWidget(page_4);
        page_5 = new QWidget();
        page_5->setObjectName(QStringLiteral("page_5"));
        toolBox = new QToolBox(page_5);
        toolBox->setObjectName(QStringLiteral("toolBox"));
        toolBox->setGeometry(QRect(70, 60, 131, 221));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        page->setGeometry(QRect(0, 0, 131, 131));
        pushButton_13 = new QPushButton(page);
        pushButton_13->setObjectName(QStringLiteral("pushButton_13"));
        pushButton_13->setGeometry(QRect(0, 20, 93, 28));
        toolBox->addItem(page, QString::fromUtf8("\345\256\266\344\272\272"));
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        page_2->setGeometry(QRect(0, 0, 131, 131));
        toolButton = new QToolButton(page_2);
        toolButton->setObjectName(QStringLiteral("toolButton"));
        toolButton->setGeometry(QRect(30, 50, 47, 21));
        toolBox->addItem(page_2, QString::fromUtf8("\346\234\213\345\217\213"));
        page_3 = new QWidget();
        page_3->setObjectName(QStringLiteral("page_3"));
        toolButton_2 = new QToolButton(page_3);
        toolButton_2->setObjectName(QStringLiteral("toolButton_2"));
        toolButton_2->setGeometry(QRect(40, 60, 47, 21));
        toolBox->addItem(page_3, QString::fromUtf8("\351\273\221\345\220\215\345\215\225"));
        stackedWidget->addWidget(page_5);
        page_6 = new QWidget();
        page_6->setObjectName(QStringLiteral("page_6"));
        tabWidget = new QTabWidget(page_6);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(30, 60, 211, 151));
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        tabWidget->addTab(tab_4, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QStringLiteral("tab_5"));
        tabWidget->addTab(tab_5, QString());
        stackedWidget->addWidget(page_6);
        btn_scrollArea = new QPushButton(centralWidget);
        btn_scrollArea->setObjectName(QStringLiteral("btn_scrollArea"));
        btn_scrollArea->setGeometry(QRect(340, 20, 93, 28));
        btn_ToolBox = new QPushButton(centralWidget);
        btn_ToolBox->setObjectName(QStringLiteral("btn_ToolBox"));
        btn_ToolBox->setGeometry(QRect(340, 110, 93, 28));
        btn_TabWidget = new QPushButton(centralWidget);
        btn_TabWidget->setObjectName(QStringLiteral("btn_TabWidget"));
        btn_TabWidget->setGeometry(QRect(340, 200, 93, 28));
        comboBox = new QComboBox(centralWidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(130, 350, 87, 22));
        btn_select = new QPushButton(centralWidget);
        btn_select->setObjectName(QStringLiteral("btn_select"));
        btn_select->setGeometry(QRect(130, 420, 93, 28));
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(350, 340, 113, 21));
        timeEdit = new QTimeEdit(centralWidget);
        timeEdit->setObjectName(QStringLiteral("timeEdit"));
        timeEdit->setGeometry(QRect(320, 430, 118, 22));
        dateEdit = new QDateEdit(centralWidget);
        dateEdit->setObjectName(QStringLiteral("dateEdit"));
        dateEdit->setGeometry(QRect(300, 500, 110, 22));
        horizontalScrollBar = new QScrollBar(centralWidget);
        horizontalScrollBar->setObjectName(QStringLiteral("horizontalScrollBar"));
        horizontalScrollBar->setGeometry(QRect(550, 430, 160, 16));
        horizontalScrollBar->setOrientation(Qt::Horizontal);
        verticalScrollBar = new QScrollBar(centralWidget);
        verticalScrollBar->setObjectName(QStringLiteral("verticalScrollBar"));
        verticalScrollBar->setGeometry(QRect(490, 430, 16, 160));
        verticalScrollBar->setOrientation(Qt::Vertical);
        horizontalSlider = new QSlider(centralWidget);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(600, 500, 160, 22));
        horizontalSlider->setOrientation(Qt::Horizontal);
        spinBox = new QSpinBox(centralWidget);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setGeometry(QRect(550, 500, 46, 22));
        lbl_Image = new QLabel(centralWidget);
        lbl_Image->setObjectName(QStringLiteral("lbl_Image"));
        lbl_Image->setGeometry(QRect(580, 230, 211, 161));
        lbl_movie = new QLabel(centralWidget);
        lbl_movie->setObjectName(QStringLiteral("lbl_movie"));
        lbl_movie->setGeometry(QRect(510, 10, 311, 221));
        lbl_movie->setScaledContents(true);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 930, 26));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(2);
        toolBox->setCurrentIndex(0);
        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        pushButton->setText(QApplication::translate("MainWindow", "PushButton", 0));
        pushButton_3->setText(QApplication::translate("MainWindow", "PushButton", 0));
        pushButton_2->setText(QApplication::translate("MainWindow", "PushButton", 0));
        pushButton_4->setText(QApplication::translate("MainWindow", "PushButton", 0));
        pushButton_5->setText(QApplication::translate("MainWindow", "PushButton", 0));
        pushButton_6->setText(QApplication::translate("MainWindow", "PushButton", 0));
        pushButton_7->setText(QApplication::translate("MainWindow", "PushButton", 0));
        pushButton_8->setText(QApplication::translate("MainWindow", "PushButton", 0));
        pushButton_12->setText(QApplication::translate("MainWindow", "PushButton", 0));
        pushButton_11->setText(QApplication::translate("MainWindow", "PushButton", 0));
        pushButton_10->setText(QApplication::translate("MainWindow", "PushButton", 0));
        pushButton_9->setText(QApplication::translate("MainWindow", "PushButton", 0));
        pushButton_13->setText(QApplication::translate("MainWindow", "PushButton", 0));
        toolBox->setItemText(toolBox->indexOf(page), QApplication::translate("MainWindow", "\345\256\266\344\272\272", 0));
        toolButton->setText(QApplication::translate("MainWindow", "...", 0));
        toolBox->setItemText(toolBox->indexOf(page_2), QApplication::translate("MainWindow", "\346\234\213\345\217\213", 0));
        toolButton_2->setText(QApplication::translate("MainWindow", "...", 0));
        toolBox->setItemText(toolBox->indexOf(page_3), QApplication::translate("MainWindow", "\351\273\221\345\220\215\345\215\225", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("MainWindow", "\347\231\276\345\272\246", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("MainWindow", "\350\260\267\346\255\214", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QApplication::translate("MainWindow", "\350\210\271\345\217\252", 0));
        btn_scrollArea->setText(QApplication::translate("MainWindow", "scollArea", 0));
        btn_ToolBox->setText(QApplication::translate("MainWindow", "ToolBox", 0));
        btn_TabWidget->setText(QApplication::translate("MainWindow", "Tab Widget", 0));
        btn_select->setText(QApplication::translate("MainWindow", "\351\200\211\344\270\255\346\213\226\346\213\211\346\234\272\345\255\220", 0));
        lbl_Image->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        lbl_movie->setText(QApplication::translate("MainWindow", "TextLabel", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
