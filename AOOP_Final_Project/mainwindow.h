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

private slots:
    void on_RunButton_clicked();
    void on_StartSimulationButton_clicked();
    void on_PeopleInformationButton_clicked();

public slots:
    void slot_update_data();

private:
    Ui::MainWindow *ui;

    Building EE;
};

#endif // MAINWINDOW_H
