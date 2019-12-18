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
    floor = 1;
    peopleinelevator=0;
    for(int i=0;i<27;i++){
        for(int j=0;j<4;j++){
            ui->InformationGridLayOut->addWidget(&showline[i][j],i,j);
        }
    }
//    arrival.resize(28);
//    for(int i=0;i<28;i++)
//        arrival.at(i)=0;
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

    query.first();
    int num = query.value(0).toInt();

    int n = rand() % num;
    //qDebug()<<n;
    queryCmd = "SELECT * FROM problemlist WHERE ID REGEXP ";
    queryCmd += "\'^0?" + to_string(floor) + "-0+" + to_string(n) + "$\';";
    query.exec(queryCmd.c_str());
    //qDebug()<<floor<<"  "<<QString::fromStdString(queryCmd);

    query.next();
    string question = query.value(2).toString().toStdString();
    this->ans = query.value(3).toString().toStdString();
    qDebug()<<QString::fromStdString(question)<<endl;
    qDebug()<<QString::fromStdString(this->ans)<<endl;

    if(b==0)
        peopleinelevator--;
    else if(b==1)
        peopleinelevator++;
    qDebug()<<b<<floor<<this->floor;
    distance+=abs(this->floor-floor);
    this->floor = floor;
    this->timer.restart();
    return question;
}

bool JudgeWindow::submitData(string ans)
{
    this->costtime[floor] += this->timer.nsecsElapsed();
    qDebug()<<QString::fromStdString(ans)<<endl;
    qDebug()<<QString::fromStdString(this->ans)<<endl;
    showPeopleInfo();
    if(ans == this->ans)
        correctansnum[floor]++;
    questionnum[floor]++;

    return ans == this->ans;
}

void JudgeWindow::scheduleEnd()
{
    out.open("time.txt");
    if(!out){
        qDebug()<<"open file failed"<<endl;
    }else{
        qDebug()<<"open file successful"<<endl;
    }
    for(int i=1;i<28;i++)
        out<<i<<","<<costtime[i]<<","<<correctansnum[i]<<","<<questionnum[i]<<endl;

    out.close();
}

void JudgeWindow::reset()
{
    for(int i=0;i<28;i++){
        costtime[i]=0;
        correctansnum[i]=0;
        questionnum[i]=0;
    }
    distance = 0;
    floor = 1;
//    arrival.resize(28);
//    for(int i=0;i<28;i++)
//        arrival.at(i)=0;
}

//void JudgeWindow::setupPeopleInfo(const vector<People> &in)
//{
//        floorPeople.clear();
//        floorPeople=in;
//}

void JudgeWindow::showPeopleInfo()
{
    for(int i=0; i<27; i++) {
        //qDebug()<<i<<" "<<floorPeople.at(i).num;
        //showline[i][0].setText(QString::number(floorPeople.at(i+1).num));
        //showline[i][1].setText(QString::number(arrival.at(i+1)));
        showline[i][2].setText(QString::number(costtime[i+1]));
    }
}
