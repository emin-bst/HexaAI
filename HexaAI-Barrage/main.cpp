#include "mainwindow.h"

#include <QApplication>
#include <QCommandLineParser>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QCommandLineParser parser;

    parser.addHelpOption();
    parser.addOption({ "thirdApp", "is thrid app", "isThirdApp" });
    parser.addOption({ "packageName", "current package on Android", "currentPackage" });

    parser.process(a);

    MainWindow w;
    if (parser.isSet("thirdApp")) {
        if (QString::compare(parser.value("thirdApp"), "true", Qt::CaseInsensitive) == 0) {
            w.isThirdApp = true;
        }
    }
    if (parser.isSet("packageName")) {
        w.packageName = parser.value("packageName");
    }
    w.initLayout();
    w.show();
    return a.exec();
}
