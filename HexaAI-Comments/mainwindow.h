#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "CustomTitleBar.h"
#include "CommentWidget.h"
#include "CustomWidget.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
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
    void showContextMenu(const QPoint &pos);

private:
    Ui::MainWindow *ui;
    CustomTitleBar *customTitleBar;
    CommentWidget *commentWidget;
    CustomWidget *customWidget;
};

#endif // MAINWINDOW_H
