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

    connectDB();
    setupProblemDB();
    setupPeopleDB();
    //setupPeopleInfo();

    for(int i=0;i<27;i++){
        for(int j=0;j<4;j++){
            ui->ShowInformation->addWidget(&showline[i][j],i,j);
        }
    }


}

void JudgeWindow::readPeopleInfo()
{
    for(int i=0; i<27; i++) {
        qDebug()<<i<<" "<<floorPeople.at(i).num;
        showline[i][0].setText(QString::number(floorPeople.at(i+1).num));
        int toNum = 0;
        for(int j=0; j<27; j++)
            if (i+1 == floorPeople.at(j+1).to)
                toNum += floorPeople.at(j+1).num;
        showline[i][1].setText(QString::number(toNum));
    }
}

JudgeWindow::~JudgeWindow()
{
    delete ui;
}

void JudgeWindow::connectDB()
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

void JudgeWindow::setupProblemDB()
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

void JudgeWindow::setupPeopleInfo()
{
    QSqlQuery query;

    string queryCmd;
    queryCmd = "select * from peoplelist where Id like '";
    int n=getConditionNum(),tmp=10000;
    for(int i=0;i<5;i++){
        queryCmd+=to_string(n/tmp);
        n%=tmp;
        tmp/=10;
    }
    queryCmd+="-%';";

    query.exec(queryCmd.c_str());

    floorPeople.clear();
    floorPeople.resize(28);
    while (query.next()) {
        int at, to, num;

        at = query.value(1).toInt();
        to = query.value(2).toInt();
        num = query.value(3).toInt();
        qDebug()<<at<<to<<num;

        floorPeople.at(at).to = to;
        floorPeople.at(at).num = num;
    }
}

void JudgeWindow::setupPeopleDB()
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


string JudgeWindow::getData(int floor,int b)
{
    // processing b

    //從mysql取出資料
    QSqlQuery query;
    string queryCmd;
    queryCmd = "select count(Floor) from problemlist where Floor =";
    queryCmd += to_string(floor) + ";";
    query.exec(queryCmd.c_str());
    int num = query.value(1).toInt();

    int n = rand() % num;
    queryCmd = "select * from problemlist where ID like ";
    if (1<=floor && floor<=9)
        queryCmd += "0" + to_string(floor);
    else {
        queryCmd += to_string(floor);
    }
    queryCmd += "-";
    int tmp = 10000;
    for (int i=0; i<5; i++) {
        queryCmd += to_string(n/tmp);
        n %= tmp;
        tmp /= 10;
    }
    queryCmd += ";";
    query.exec(queryCmd.c_str());

    string question = query.value(3).toString().toStdString();
    this->ans = query.value(4).toString().toStdString();
    qDebug()<<QString::fromStdString(query.value(3).toString().toStdString())<<endl;
    qDebug()<<QString::fromStdString(this->ans)<<endl;

    this->floor = floor;
    this->timer.restart();
    return question;
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
    return peopleInfoState;
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
