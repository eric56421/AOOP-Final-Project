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
    }
    for(int i=0;i<28;i++){
        floordatatimes[i] = 10;
        floornextdata[i]= 0;
        score[i]=0;
    }
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
    if(giveout[floor-1].isChecked())
        return "GIVENUP";
    datatimes = floordatatimes[floor];
    //從mysql取出資料
    QSqlQuery query;
    string queryCmd;


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
    string question = query.value(2).toString().toStdString();
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
    this->timer.restart();
    return question;
}

bool JudgeWindow::submitData(string ans)
{
    runtime=this->timer.nsecsElapsed();
    //qDebug()<<QString::fromStdString(ans)<<endl;
    //qDebug()<<QString::fromStdString(this->ans)<<endl;
    showPeopleInfo();
    if(ans == this->ans){
        this->costtime[floor] += runtime/floordatatimes[this->floor];
        correctansnum[floor]++;
        score[floor]+=(10000000000+pow(2,floornextdata[floor]));
    }
    floornextdata[floor]++;
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
    database.setHostName("140.113.146.120");
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
//    string id1 = "123", id2="456", name1="ji", name2="jiji";
//    string studInfo = "'"+id1+"','"\
//                        +name1+"','"\
//                        +id2+"','"\
//                        +name2+"', ";

//    string queryCmd = "INSERT INTO floorscore (stud_id1, stud_name1, stud_id2, stud_name2, floor, timespent, pass, totalques, totalscore) VALUES (";

//    int a=2222, b=3333, c=4444, d=5555;
//    query.exec("USE aoopstudentuse;");
//    for (int i=1; i<=2; i++) {
//        string floorInfo = to_string(i)+", "+to_string(a)+", "+to_string(b)\
//                            +", "+to_string(c)+", "+to_string(d)+");";
//        qDebug()<<QString::fromStdString(queryCmd+studInfo+floorInfo);
//        query.exec((queryCmd+studInfo+floorInfo).c_str());
//    }

    string studInfo = "'"+ui->StudId1LineEdit->text().toStdString()+"','"\
                        +ui->StudName1LineEdit->text().toStdString()+"','"\
                        +ui->StudId2LineEdit->text().toStdString()+"','"\
                        +ui->StudName2LineEdit->text().toStdString()+"', ";

    string queryCmd = "INSERT INTO floorscore (stud_id1, stud_name1, stud_id2, stud_name2, floor, timespent, pass, totalques, totalscore) VALUES (";

    query.exec("USE aoopstudentuse;");
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