#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void initLayout();

    bool isThirdApp = false;
    QString packageName;
    QString appName;

private slots:
    void sendDanmu();      // 生成随机弹幕
    void sendUserDanmu();  // 发送用户输入的弹幕
    void createDanmu(const QString &text, bool user);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
