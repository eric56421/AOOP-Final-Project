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
        ui->InformationGridLayOut->addWidget(&giveout[i],i,5);
        floorLabel[i].setNum(i+1);
        ui->InformationGridLayOut->addWidget(&floorLabel[i], i, 6);
    }
    
    for(int i=0;i<28;i++){
        floordatatimes[i] = 10;
        floornextdata[i]= 0;
        score[i]=0;
    }
    for(int i=22;i<28;i++){
        floordatatimes[i] = 1;
    }

    ui->StudId1LineEdit->setText("0710730");
    ui->StudName1LineEdit->setText("郭昱辰");
    ui->StudId2LineEdit->setText("0710758");
    ui->StudName2LineEdit->setText("黃宇裼");
//    arrival.resize(28);
//    for(int i=0;i<28;i++)
//        arrival.at(i)=0;
}

JudgeWindow::~JudgeWindow()
{
    delete ui;
}

string JudgeWindow::getData(int floor,int b,int &datatimes)
{
    datatimes = floordatatimes[floor];
    //從mysql取出資料
    QSqlQuery query;
    string queryCmd;

    query.exec("USE FINAL;");
    queryCmd = "select count(Floor) from problemlist where Floor =";
    queryCmd += to_string(floor) + ";";
    query.exec(queryCmd.c_str());

    query.first();
    int num = query.value(0).toInt();

    int n = floornextdata[floor]%num;
    //qDebug()<<n;
    queryCmd = "SELECT * FROM problemlist WHERE ID REGEXP ";
    queryCmd += "\'^0?" + to_string(floor) + "-0+" + to_string(n) + "$\';";
    query.exec(queryCmd.c_str());
    //qDebug()<<floor<<"  "<<QString::fromStdString(queryCmd);

    query.next();
    question = query.value(2).toString().toStdString();
    this->ans = query.value(3).toString().toStdString();
    //qDebug()<<QString::fromStdString(question)<<endl;
    //qDebug()<<QString::fromStdString(this->ans)<<endl;

    if(b==0)
        peopleinelevator--;
    else if(b==1)
        peopleinelevator++;
    //qDebug()<<b<<floor<<this->floor;
    distance+=abs(this->floor-floor);
    this->floor = floor;
    if(giveout[floor-1].isChecked())
        return "GIVENUP";
    this->timer.restart();
    return question;
}

bool JudgeWindow::submitData(string ans)
{
    runtime=timer.nsecsElapsed();
    //qDebug()<<QString::fromStdString(ans)<<endl;
    //qDebug()<<QString::fromStdString(this->ans)<<endl;
    showPeopleInfo();
    if(ans == this->ans){
        if(floor==19)
            qDebug()<<floornextdata[floor]<<"correct";
        this->costtime[floor] += runtime/floordatatimes[this->floor];
        correctansnum[floor]++;
        score[floor]+=(10000000000+pow(2,floornextdata[floor]));
    }else if(floor==19){
        qDebug()<<floornextdata[floor]<<"error";
        qDebug()<<QString::fromStdString(question)<<endl;
        qDebug()<<QString::fromStdString(this->ans)<<endl;
        qDebug()<<QString::fromStdString(ans)<<endl;
    }
    floornextdata[floor]++;
    questionnum[floor]++;
    runtime=0;
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
    for(int i=0;i<28;i++){
        floordatatimes[i] = 10;
        floornextdata[i]= 0;
        score[i]=0;
    }
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
        showline[i][3].setText(QString::number(score[i+1]));
       // qDebug()<<"score : "<<score[i+1];
    }
}

void JudgeWindow::on_ExportButton_clicked()
{
    uploadToTAMySQL();
}

void JudgeWindow::uploadToTAMySQL()
{
    // Connect
    QSqlDatabase database;
    database = QSqlDatabase::addDatabase("QMYSQL");
    database.setHostName("140.113.146.126");
    database.setPort(3306);
    database.setUserName("aoopstudent");
    database.setPassword("tsaimother");

    bool ok = database.open();
    if (ok) {
        qDebug()<<"Successful connection to TA server.";
    } else {
        qDebug()<<"Error: Cannot connect to TA server!!!";
    }

    // Upload
    QSqlQuery query;
    query.exec("USE aoopstudentuse;");

    string studInfo = "'"+ui->StudId1LineEdit->text().toStdString()+"','"\
                        +ui->StudName1LineEdit->text().toStdString()+"','"\
                        +ui->StudId2LineEdit->text().toStdString()+"','"\
                        +ui->StudName2LineEdit->text().toStdString()+"', ";
    string queryCmd = "INSERT INTO floorscore (stud_id1, stud_name1, stud_id2, stud_name2, floor, timespent, pass, totalques, totalscore) VALUES (";

    for (int i=1; i<=27; i++) {
        string floorInfo = to_string(i)+", "+to_string(costtime[i])+", "+to_string(correctansnum[i])\
                            +", "+to_string(questionnum[i])+", "+to_string(score[i])+");";
        qDebug()<<QString::fromStdString(queryCmd+studInfo+floorInfo);
        query.exec((queryCmd+studInfo+floorInfo).c_str());
    }

    queryCmd = "INSERT INTO totalpath (stud_id1, stud_name1, stud_id2, stud_name2, pathlen) VALUES (";
    string pathInfo = to_string(distance)+");";
    qDebug()<<QString::fromStdString(queryCmd+studInfo+pathInfo);
    query.exec((queryCmd+studInfo+pathInfo).c_str());


    qDebug()<<query.lastError().text();
}
