#include "mainwindow.h"
#include <QApplication>
#include <QSqlDatabase> // ?
#include <QSqlQuery>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    w.connectDB();
    

    return a.exec();
}
