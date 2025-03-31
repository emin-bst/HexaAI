#ifndef CUSTOMWIDGET_H
#define CUSTOMWIDGET_H

#include <QApplication>
#include <QWidget>
#include <QMenu>
#include <QAction>
#include <QMessageBox>
#include <QContextMenuEvent>

class CustomWidget : public QWidget {
    Q_OBJECT
public:
    CustomWidget(QWidget *parent = nullptr) : QWidget(parent) {}

protected:
    void contextMenuEvent(QContextMenuEvent *event) override {
        QMenu menu(this);

        QAction *action1 = new QAction("选项 1", this);
        QAction *action2 = new QAction("选项 2", this);

        connect(action1, &QAction::triggered, this, []() {
            QMessageBox::information(nullptr, "提示", "你点击了选项 1");
        });

        connect(action2, &QAction::triggered, this, []() {
            QMessageBox::information(nullptr, "提示", "你点击了选项 2");
        });

        menu.addAction(action1);
        menu.addAction(action2);

        menu.exec(event->globalPos());  // 在鼠标位置显示菜单
    }
};

#endif // CUSTOMWIDGET_H
