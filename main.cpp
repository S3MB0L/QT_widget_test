#include "mainwindow.h"
#include <QApplication>
#include "dir_file_operations.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    QDir my_dir;

    w.show();

    return a.exec();
}
