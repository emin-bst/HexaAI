#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLabel>
#include <QLineEdit>
#include <QTimer>
#include <QPushButton>
#include <QRandomGenerator>
//#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 去掉窗口标题栏（无边框窗口）
    setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);

    // 设置窗口透明
    setAttribute(Qt::WA_TranslucentBackground);

    this->setFixedSize(1200, 900); // 固定窗口大小
}

void MainWindow::initLayout()
{
    //QMessageBox::information(nullptr, "Debug", packageName);

    // 创建标题专栏
    if (!isThirdApp) {
        ui->label->setText("BS Global Channel");
        appName = "AI";
    } else {
        if (packageName == "com.plarium.raidlegends") {
            appName = "Raid";
        } else {
            appName = "Game";
        }
        QString channel = appName + " Channel";
        ui->label->setText(channel);
    }
    ui->label->setAlignment(Qt::AlignCenter);
    ui->label->setGeometry(450, 50, 300, 50);
    ui->label->setStyleSheet("background: rgba(200, 200, 200, 200); color: rgba(0,0,255,200); font-weight: bold; border-radius: 5px; padding: 5px; font-size: 23px;");

    // 创建输入框
    ui->lineEdit->setPlaceholderText("Please enter text ...");
    ui->lineEdit->setGeometry(500, 600, 200, 30);
    ui->lineEdit->setStyleSheet("background: rgba(100, 100, 100, 150); placeholder-text-color: rgba(255, 255, 255, 100); color: rgba(255,0,0,150); font-weight: bold; border-radius: 5px; padding: 5px;");
    connect(ui->lineEdit, &QLineEdit::returnPressed, this, &MainWindow::sendUserDanmu);

    // 定时自动发送随机弹幕
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::sendDanmu);
    MainWindow::sendDanmu();
    timer->start(1000 * 5); // 每5秒发送一条随机弹幕
}

// 发送一条随机弹幕
void MainWindow::sendDanmu()
{
    QString text = appName + " Random " + QString::number(QRandomGenerator::global()->bounded(10));
    createDanmu(text, false);
}

// 发送用户输入的弹幕
void MainWindow::sendUserDanmu()
{
    QString text = ui->lineEdit->text();
    if (!text.isEmpty()) {
        createDanmu(text, true);
        ui->lineEdit->clear(); // 发送后清空输入框
    }
}

// 创建弹幕
void MainWindow::createDanmu(const QString &text, bool user)
{
    QLabel *danmu = new QLabel(this);
    danmu->setText(text);
    if (user) {
        danmu->setStyleSheet("color: rgba(255,0,0,150); font-weight: bold; background-color: rgba(0,0,0,100); font-size: 20px;");
    } else {
        danmu->setStyleSheet("color: white; background-color: rgba(0,0,0,100); font-size: 18px;");
    }

    danmu->adjustSize();

    int yPos = QRandomGenerator::global()->bounded(100, this->height() / 3);
    danmu->move(this->width(), yPos);
    danmu->show();

    QTimer *moveTimer = new QTimer(danmu);
    connect(moveTimer, &QTimer::timeout, [=]() mutable {
        if (danmu->x() < -danmu->width()) {
            danmu->deleteLater();
            moveTimer->stop();
        } else {
            danmu->move(danmu->x() - 3, danmu->y());
        }
    });
    moveTimer->start(30);
}

MainWindow::~MainWindow()
{
    delete ui;
}
