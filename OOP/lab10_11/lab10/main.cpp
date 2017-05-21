#include "mainwindow.h"
#include <QApplication>
#include <QHBoxLayout>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    Activity_list ls1 = new Activity_list{}
    w.show();

    return a.exec();
}
