#ifndef COMMENTWIDGET_H
#define COMMENTWIDGET_H

#include <QWidget>
#include <QVBoxLayout>
#include <QListWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>



class CommentWidget : public QWidget {
    Q_OBJECT

public:
    CommentWidget(QWidget *parent = nullptr);

public slots:
    void sendComment();

    void addComment(const QString &user, const QString &comment);

private:
    QListWidget *commentList;
    QLineEdit *inputField;
    QPushButton *sendButton;
};

#endif // COMMENTWIDGET_H
