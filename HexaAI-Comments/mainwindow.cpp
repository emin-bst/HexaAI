#include <QApplication>
#include <QMainWindow>
#include <QPushButton>
#include <QTimer>
#include <QMenu>
#include <QAction>
#include <QMessageBox>

#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    //ui->setupUi(this);

    setWindowFlags(Qt::WindowStaysOnTopHint | Qt::FramelessWindowHint);
    setStyleSheet("background-color: rgba(128, 128, 255, 150); border-radius: 10px; padding: 10px;");

    this->setGeometry(1380, 500, 300, 400);
    //this->setFixedSize(300, 400);

    customTitleBar = new CustomTitleBar();
    setMenuWidget(customTitleBar); // 将标题栏设置为自定义控件

    // 创建主窗口的中心 Widget
    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    // 使用 QVBoxLayout 管理布局
    QVBoxLayout *layout = new QVBoxLayout(centralWidget);

    // 创建评论框（作为 MainWindow 内部控件）
    commentWidget = new CommentWidget(this);
    layout->setContentsMargins(0, 0, 0, 0);  // 设置四周间距（左右上下）
    layout->addWidget(commentWidget);

    commentWidget->setVisible(true);

    setContextMenuPolicy(Qt::CustomContextMenu);
    connect(this, &MainWindow::customContextMenuRequested, this, &MainWindow::showContextMenu);
}

void MainWindow::initLayout() {
    if (!isThirdApp) {
        customTitleBar->setTitleText("BS Global Channel");
    } else {
        if (packageName == "com.plarium.raidlegends") {
            appName = "Raid";
        } else {
            appName = "Game";
        }
        QString channel = appName + " Channel";
        customTitleBar->setTitleText(channel);
    }
}

void MainWindow::showContextMenu(const QPoint &pos) {
    QMenu menu(this);
    QAction *action1 = new QAction("Add friend", this);

    connect(action1, &QAction::triggered, this, []() {
        QMessageBox::information(nullptr, "Hint", "Send a request to add him as a nowgg friend");
    });

    menu.addAction(action1);
    menu.exec(mapToGlobal(pos));  // 显示菜单
}

MainWindow::~MainWindow()
{
    delete ui;
}
