#include "judgewindow.h"
#include "ui_judgewindow.h"

JudgeWindow::JudgeWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::JudgeWindow)
{
    ui->setupUi(this);
    timer.start();
    score = 0;
    distance = 0;
}

JudgeWindow::~JudgeWindow()
{
    delete ui;
}

string JudgeWindow::getData(int floor,int b)
{
    //從mysql取出資料
    QSqlQuery query;
    string queryCmd;
    queryCmd = "select count(Floor) from problemlist where Floor =";
    queryCmd += to_string(floor) + ";";
    query.exec(queryCmd.c_str());
    this->floor = floor;



    int n = rand() %dataV.size();
    this->ans = ansV.at(n);
    qDebug()<<QString::fromStdString(dataV.at(n))<<endl;
    qDebug()<<QString::fromStdString(ans)<<endl;
    this->timer.restart();
    return dataV.at(n);

}

bool JudgeWindow::submitData(string ans)
{
    this->costtime = this->timer.nsecsElapsed();
    qDebug()<<QString::fromStdString(ans)<<endl;
    qDebug()<<QString::fromStdString(this->ans)<<endl;
    if(ans==this->ans)
        score+=100;
    return ans == this->ans;
}

int JudgeWindow::getConditionNum()
{
    return rand()%300+1;
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
