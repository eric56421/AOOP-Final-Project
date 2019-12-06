#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlQuery>
#include <QSqlResult>
#include <QSqlDatabase>
#include <QSqlError>

#include <cstdlib>
#include <ctime>

#include "building.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void connectDB();
    void setupDB();

private slots:
    void on_buttonRun_clicked();
    void on_buttonPeopleInfo_clicked();

private:
    Ui::MainWindow *ui;

    Building EE;
};

#endif // MAINWINDOW_H
