#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSqlError>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_RunButton_clicked()
{
    Building test;
    Data result;

    test.run(ui->comboBox->currentIndex());
    result = test.getData();

    ui->lineTestdata->setText(QString::fromStdString(result.testdata));
    ui->lineSubmitdata->setText(QString::fromStdString(result.submit));
    ui->lineSpendtime->setText(QString::number(result.spendtime));
    ui->lineCorrect->setText(QString::number(result.correct));

}

void MainWindow::connectDB()
{
    QSqlDatabase database;
    database = QSqlDatabase::addDatabase("QMYSQL");
    database.setHostName("localhost");
    database.setPort(3306);
    database.setUserName("root");
    database.setPassword("nctuece");

    //database.setDatabaseName("test");

    bool ok = database.open();
    if (ok) {
        qDebug()<<"Successful connection.";
    } else {
        qDebug()<<"Error: Cannot connect!!!";
    }
}

void MainWindow::on_pushButton_clicked()
{
    Building test;
    ui->lineEdit->setText(QString::number(test.floorPeople[ui->comboBox->currentIndex()].to));
    ui->lineEdit->setText(QString::number(test.floorPeople[ui->comboBox->currentIndex()].num));
}
