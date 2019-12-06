#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connectDB();
    setupDB();

    EE.setupPeopleInfo();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::connectDB()
{
    QSqlDatabase database;
    database = QSqlDatabase::addDatabase("QMYSQL");
    database.setHostName("localhost");
    database.setPort(3306);
    database.setUserName("root");

    //database.setPassword("nctuece");
    database.setPassword("123456");

    bool ok = database.open();
    if (ok) {
        qDebug()<<"Successful connection.";
    } else {
        qDebug()<<"Error: Cannot connect!!!";
    }
}

void MainWindow::setupDB()
{
    QSqlQuery query;

    query.exec("DROP DATABASE IF EXISTS Course6;");
    query.exec("CREATE DATABASE Course6;");
    query.exec("USE Course6;");
    query.exec("DROP TABLE IF EXISTS peoplelist;");
    query.exec("CREATE TABLE peoplelist\
                (Id varchar(8), Nowfloor int, Destination int, Num int,\
                PRIMARY KEY (Id));");

    if (!query.exec("LOAD DATA INFILE 'C:/ProgramData/MySQL/MySQL Server 8.0/Uploads/data.csv' \
                    INTO TABLE peoplelist  \
                    FIELDS TERMINATED BY ','  \
                    ENCLOSED BY \"\" \
                    LINES TERMINATED BY '\n' \
                    IGNORE 1 ROWS;"))
        qDebug()<<query.lastError().text();

}

void MainWindow::on_buttonRun_clicked()
{
    Data result;

    EE.run(ui->comboBox->currentIndex());
    result = EE.getData();

    ui->lineTestdata->setText(QString::fromStdString(result.testdata));
    ui->lineSubmitdata->setText(QString::fromStdString(result.submit));
    ui->lineSpendtime->setText(QString::number(result.spendtime));
    ui->lineCorrect->setText(QString::number(result.correct));

}

void MainWindow::on_buttonPeopleInfo_clicked()
{
    ui->linePeopleDes->setText(QString::number(EE.floorPeople[ui->comboBox->currentIndex()+1].to));
    ui->linePeopleNum->setText(QString::number(EE.floorPeople[ui->comboBox->currentIndex()+1].num));
}
