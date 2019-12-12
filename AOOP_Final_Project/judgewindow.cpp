#include "judgewindow.h"
#include "ui_judgewindow.h"

JudgeWindow::JudgeWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::JudgeWindow)
{
    ui->setupUi(this);
    timer.start();
    for(int i=0;i<28;i++){
        costtime[i]=0;
        correctansnum[i]=0;
        questionnum[i]=0;
    }
    distance = 0;
    for(int i=0;i<27;i++){
        for(int j=0;j<4;j++){
            ui->ShowInformation->addWidget(&showline[i][j],i,j);
        }
    }
}

JudgeWindow::~JudgeWindow()
{
    delete ui;
}

string JudgeWindow::getData(int floor,int b)
{
    //從mysql取出資料
}

bool JudgeWindow::submitData(string ans)
{
    this->costtime[floor] += this->timer.nsecsElapsed();
    qDebug()<<QString::fromStdString(ans)<<endl;
    qDebug()<<QString::fromStdString(this->ans)<<endl;
    if(ans == this->ans)
        correctansnum[floor]++;
    questionnum[floor]++;
    return ans == this->ans;
}

int JudgeWindow::getConditionNum()
{

}

void JudgeWindow::scheduleEnd()
{
    out.open("time.txt");
    if(!out){
        qDebug()<<"open file failed"<<endl;
    }else{
        qDebug()<<"open file successful"<<endl;
    }
    for(int i=0;i<27;i++)
        out<<i<<","<<costtime[i]<<","<<correctansnum[i]<<","<<questionnum[i]<<endl;

    out.close();
}
