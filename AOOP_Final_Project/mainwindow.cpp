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

    connect(&EE,SIGNAL(updateGUI()),this,SLOT(slot_update_data()));
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

    database.setPassword("nctuece");
    //database.setPassword("123456");

    bool ok = database.open();
    if (ok) {
        qDebug()<<"Successful connection.";
    } else {
        qDebug()<<"Error: Cannot connect!!!";
    }

    QSqlQuery query;

    query.exec("DROP DATABASE IF EXISTS FINAL;");
    query.exec("CREATE DATABASE FINAL;");
    query.exec("USE FINAL;");
}

void MainWindow::setupProblemDB()
{
    QSqlQuery query;

    query.exec("USE FINAL;");
    query.exec("DROP TABLE IF EXISTS problemlist;");
    query.exec("CREATE TABLE problemlist\
                (ID varchar(8), Floor int, Question text, Answer text,\
                PRIMARY KEY (ID));");

    if (!query.exec("LOAD DATA INFILE 'C:/ProgramData/MySQL/MySQL Server 8.0/Uploads/testdata.csv' \
                    INTO TABLE problemlist  \
                    FIELDS TERMINATED BY ','  \
                    ENCLOSED BY \"\"\"\" \
                    LINES TERMINATED BY '\r\n' \
                    IGNORE 1 ROWS;"))
        qDebug()<<query.lastError().text();

}

void MainWindow::setupPeopleDB()
{
    QSqlQuery query;

    query.exec("USE FINAL;");
    query.exec("DROP TABLE IF EXISTS peoplelist;");
    query.exec("CREATE TABLE peoplelist\
                (Id varchar(8), Nowfloor int, Destination int, Number int,\
                PRIMARY KEY (Id));");

    if (!query.exec("LOAD DATA INFILE 'C:/ProgramData/MySQL/MySQL Server 8.0/Uploads/initial_condition.csv' \
                    INTO TABLE peoplelist  \
                    FIELDS TERMINATED BY ','  \
                    ENCLOSED BY \"\"\"\" \
                    LINES TERMINATED BY '\n' \
                    IGNORE 1 ROWS;"))
        qDebug()<<query.lastError().text();
}

void MainWindow::on_RunButton_clicked()
{
    EE.run(ui->Slectfloorbox->currentIndex()+1);
    Data result;
    result = EE.getData();
    ui->TestdataLine->setText(QString::fromStdString(result.testdata));
    ui->SubmitdataLine->setText(QString::fromStdString(result.submit));
    ui->SpendtimeLine->setText(QString::number(result.spendtime));
    ui->CorrectLine->setText(QString::number(result.correct));
    ui->ScoreLine->setText(QString::number(result.score));
}

void MainWindow::on_StartSimulationButton_clicked()
{
    ui->FinishLabel->hide();
    EE.reset();
    EE.startSimulation();
}

void MainWindow::on_PeopleInformationButton_clicked()
{
    ui->PeopleNumLine->setText(QString::number(EE.floorPeople[ui->Slectfloorbox->currentIndex()+1].to));
    ui->DestinationLine->setText(QString::number(EE.floorPeople[ui->Slectfloorbox->currentIndex()+1].num));
}

void MainWindow::slot_update_data()
{
    Data result;
    result = EE.getData();
    if(result.nowfloor!=0){
        ui->TestdataLine->setText(QString::fromStdString(result.testdata));
        ui->SubmitdataLine->setText(QString::fromStdString(result.submit));
        ui->SpendtimeLine->setText(QString::number(result.spendtime));
        ui->CorrectLine->setText(QString::number(result.correct));
        ui->ScoreLine->setText(QString::number(result.score));
        ui->Slectfloorbox->setCurrentIndex(result.nowfloor-1);
    }else if (result.nowfloor==0){
        ui->FinishLabel->show();
    }
}
