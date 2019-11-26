#include "mainwindow.h"
#include "ui_mainwindow.h"

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
