#include "mainwindow.h"

#include <QApplication>
#include "QBreakpadHandler.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    QBreakpadInstance.setUploadUrl(QUrl("http://www.baidu.com"));

    QBreakpadInstance.setDumpPath(QLatin1String("crashes"));






    return a.exec();
}
