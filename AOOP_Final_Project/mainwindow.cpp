#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(&EE,SIGNAL(updateGUI()),this,SLOT(slot_update_data()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_RunButton_clicked()
{
    EE.run(ui->Slectfloorbox->currentIndex()+1,0);
    Data result;
    result = EE.getData();
    ui->TestdataLine->setText(QString::fromStdString(result.testdata));
    ui->SubmitdataLine->setText(QString::fromStdString(result.submit));
    ui->SpendtimeLine->setText(QString::number(result.spendtime));
    ui->CorrectLine->setText(QString::number(result.correct));
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
        ui->Slectfloorbox->setCurrentIndex(result.nowfloor-1);
        ui->DistanceLCD->display(result.distance);
        ui->PeopleInElevatorLCD->display(result.peopleinelevator);
        ui->NowElevatorLCD->display(result.nowfloor);
    }else if (result.nowfloor==0){
        ui->FinishLabel->show();
    }
}
