#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMouseEvent>

#include "CustomTitleBar.h"

CustomTitleBar::CustomTitleBar(QWidget *parent)
    : QWidget(parent)
{
    setAttribute(Qt::WA_TranslucentBackground);
    setStyleSheet("color: rgba(170, 0, 0, 200); font: bold 16px;");

    QHBoxLayout *layout = new QHBoxLayout();

    // 创建标题文本
    titleLabel = new QLabel("", this);
    layout->addWidget(titleLabel);

    layout->setContentsMargins(5, 5, 5, 5);
    setLayout(layout);
}


void CustomTitleBar::setTitleText(QString text) {
    titleLabel->setText(text);
}
