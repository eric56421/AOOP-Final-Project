#include "building.h"

Building::Building() : peopleInfoState(rand()%30 + 1)  // 30 is the # of states in data.csv
{    
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
}

void Building::setupPeopleInfo()
{
    QSqlQuery query;

    string selectQuery = "SELECT * FROM peoplelist WHERE Id LIKE '%-%';";
    if (peopleInfoState < 10)
        selectQuery.insert(selectQuery.size()-4, "0"+to_string(peopleInfoState));
    else
        selectQuery.insert(selectQuery.size()-4, to_string(peopleInfoState));

    //qDebug()<<QString::fromStdString(selectQuery);
    query.exec(selectQuery.c_str());

    floorPeople.resize(11);
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

void Building::run(int floorNum)
{
    data.testdata = judge.getData(floorNum);
    data.submit = floor[floorNum]->p->solve(data.testdata);
    data.correct = judge.submitData(data.submit);
    data.spendtime = judge.getSpendTime();
    data.score = judge.getScore();
}

void Building::startSimulation()
{
    timer->start(1000);
}

void Building::update()
{
    data.nowfloor = scheduler.getNowFloor();
    qDebug()<<data.nowfloor;
    if(data.nowfloor!=0){
        this->run(data.nowfloor);
    }else{
        timer->stop();
    }
    emit this->updateGUI();

}

void Building::reset()
{
    scheduler.reset();
}
