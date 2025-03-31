#ifndef CUSTOMTITLEBAR_H
#define CUSTOMTITLEBAR_H

#include <QWidget>
#include <QLabel>

class CustomTitleBar : public QWidget {
    Q_OBJECT

public:
    CustomTitleBar(QWidget *parent = nullptr);

    void setTitleText(QString text);

private:
    QLabel *titleLabel;
};

#endif // CUSTOMTITLEBAR_H
