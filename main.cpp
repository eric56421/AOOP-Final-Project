#include "mainwindow.h"
#include <QApplication>

#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
    srand(time(NULL));

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
