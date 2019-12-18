#include "building.h"

Building::Building()  // 30 is the # of states in data.csv
{
    connectMySQL();
    setupPeopleTB();
    setupProblemTB();
    floor[1] = new Floor(new P1);//ShortestAndLongestPair
    floor[2] = new Floor(new P2);//Minesweeper
    floor[3] = new Floor(new P3);//GetSignature
    floor[4] = new Floor(new P4);//ShyGame
    floor[5] = new Floor(new P5);//FibonacciOfFibonacci
    floor[6] = new Floor(new P6);//LargesRoot
    floor[7] = new Floor(new P7);//FindStructuresOfTrees
    floor[8] = new Floor(new P8);//FindFactorial
    floor[9] = new Floor(new P9);//ShortestSummationDistance
    floor[10] = new Floor(new P10);//Add1
    floor[11] = new Floor(new P11);//DistanceBetweenPrime
    floor[12] = new Floor(new P12);//MarioOjisan
//    floor[13] = new Floor(new P13);
//    floor[14] = new Floor(new P14);
//    floor[15] = new Floor(new P15);
//    floor[16] = new Floor(new P16);
//    floor[17] = new Floor(new P17);
//    floor[18] = new Floor(new P18);
//    floor[19] = new Floor(new P19);
//    floor[20] = new Floor(new P20);

    timer = new QTimer;
    connect(timer,SIGNAL(timeout()),this,SLOT(update()));

    judge.show();
    judge.setSeed(0);
    int n=judge.getConditionNum();
    setupPeopleInfo(n);
}

void Building::connectMySQL()
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

    QSqlQuery query;
    query.exec("DROP DATABASE IF EXISTS FINAL;");
    query.exec("CREATE DATABASE FINAL;");
    query.exec("USE FINAL;");
}

void Building::setupPeopleTB()
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

void Building::setupProblemTB()
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

void Building::setupPeopleInfo(int peopleInfoState)
{
    QSqlQuery query;

    string selectQuery = "SELECT * FROM peoplelist WHERE Id LIKE '%-%';";
    if (peopleInfoState < 10)
        selectQuery.insert(selectQuery.size()-4, "0"+to_string(peopleInfoState));
    else
        selectQuery.insert(selectQuery.size()-4, to_string(peopleInfoState));

    //qDebug()<<QString::fromStdString(selectQuery);
    query.exec(selectQuery.c_str());

    floorPeople.resize(28);
    while (query.next()) {
        int at, to, num;

//        at = query.value(1).toInt();
//        to = query.value(2).toInt();
//        num = query.value(3).toInt();
//        qDebug()<<at<<to<<num;

        floorPeople.at(query.value(1).toInt()).to = query.value(2).toInt();
        floorPeople.at(query.value(1).toInt()).num = query.value(3).toInt();
    }
}

void Building::run(int floorNum, int b)
{
    data.testdata = judge.getData(floorNum, b);
    data.submit = floor[floorNum]->p->solve(data.testdata);
    data.correct = judge.submitData(data.submit);
    data.spendtime = judge.getSpendTime();
}

void Building::startSimulation()
{
    judge.reset();
    judge.setupPeopleInfo(floorPeople);
    judge.showPeopleInfo();
    timer->start(100);
    timer->setSingleShot(true);
}

void Building::update()
{

    data.nowfloor = scheduler.getNowFloor();
    qDebug()<<data.nowfloor;
    if(data.nowfloor!=0){
        this->run(data.nowfloor,0);
    }else{
        timer->stop();
    }
    timer->start(100);
    emit this->updateGUI();
}

void Building::reset()
{
    scheduler.reset();
}
