#include "CommentWidget.h"

#include <QRandomGenerator>

CommentWidget::CommentWidget(QWidget *parent)
    : QWidget(parent)
{
    setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint); // 悬浮无边框
    setStyleSheet("color: white; background-color: rgba(0, 0, 180, 150); border-radius: 5px; padding: 5px;");

    QVBoxLayout *layout = new QVBoxLayout(this);

    // 评论列表
    commentList = new QListWidget(this);
    commentList->setStyleSheet("QListWidget { border: none; }");
    layout->addWidget(commentList);

    // 输入框 + 发送按钮
    QHBoxLayout *inputLayout = new QHBoxLayout();
    inputField = new QLineEdit(this);
    inputField->setPlaceholderText("Please enter comment ...");
    sendButton = new QPushButton("Send", this);

    inputLayout->addWidget(inputField);
    inputLayout->addWidget(sendButton);
    layout->addLayout(inputLayout);

    // 连接信号槽
    connect(sendButton, &QPushButton::clicked, this, &CommentWidget::sendComment);
    connect(inputField, &QLineEdit::returnPressed, this, &CommentWidget::sendComment);
}

void CommentWidget::sendComment()
{
    QString text = inputField->text().trimmed();
    if (!text.isEmpty()) {
        QString user = "User" + QString::number(QRandomGenerator::global()->bounded(10));
        addComment(user, text);  // 假设用户名为 "用户1"
        inputField->clear();
    }
}

void CommentWidget::addComment(const QString &user, const QString &comment)
{
    QListWidgetItem *item = new QListWidgetItem(commentList);
    item->setText(user + "：" + comment);
    commentList->addItem(item);
}

