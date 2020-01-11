#include "building.h"

Building::Building()  // 30 is the # of states in data.csv
{
//    connectMySQL();

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
    floor[13] = new Floor(new P13);//EscapeIfYouWantToSurvive
    floor[14] = new Floor(new P14);//Subtract1
    floor[15] = new Floor(new P15);//FindThePeriodOfString
    floor[16] = new Floor(new P16);//LargeFactorial
    floor[17] = new Floor(new P17);//SumOfLargeHexadecimalIntegers
    floor[18] = new Floor(new P18);//LongestCommonSubstring
    floor[19] = new Floor(new P19);//GetSolution
    floor[20] = new Floor(new P20);//LongestPeekPalindrome
    floor[21] = new Floor(new P21);//Maze
    floor[22] = new Floor(new P22);//TheEasyCity1
    floor[23] = new Floor(new P23);//ManhattanDistance
    floor[24] = new Floor(new P24);//TheMedian
    floor[25] = new Floor(new P25);//TheEasyCity2
    floor[26] = new Floor(new P26);//LongestAndShortestDistance
    floor[27] = new Floor(new P27);//SymmetricPairs

    timer = new QTimer;
    connect(timer,SIGNAL(timeout()),this,SLOT(update()));

    judge.show();
    int n=judge.getConditionNum();
    setupPeopleInfo(n);
}

void Building::setupPeopleInfo(int peopleInfoState)
{
    QSqlQuery query;
    string queryCmd;

    query.exec("USE FINAL;");
    queryCmd = "SELECT * FROM peoplelist WHERE ID REGEXP ";
    queryCmd += "\'^0+" + to_string(peopleInfoState) + "-\';";
    query.exec(queryCmd.c_str());
    //qDebug()<<"Success"<<QString::fromStdString(queryCmd);

    //qDebug()<<query.lastError().text();
    //qDebug()<<"in setupPeople";
    floorPeople.clear();
    floorPeople.resize(28);
    while (query.next()) {
        int at, to, num;
        at = query.value(1).toInt();
        to = query.value(2).toInt();
        num = query.value(3).toInt();
//        qDebug()<<at<<to<<num;

        floorPeople.at(at).to = to;
        floorPeople.at(at).num = num;
    }
}

void Building::run(int floorNum, int b)
{
    int times;
    qDebug()<<floorNum;
    data.testdata = judge.getData(floorNum-1, b, times);
    if(data.testdata!="GIVENUP"){
        for(int i=0;i<times;i++){
            data.submit = floor[floorNum]->p->solve(data.testdata);
        }
    }else {
        data.submit="";
    }
    data.correct = judge.submitData(data.submit);
    data.spendtime = judge.getSpendTime();
    data.distance = judge.getDistance();
}

void Building::startSimulation()
{
    scheduler.solve(floorPeople);
    timer->start(100);
    timer->setSingleShot(true);
}

void Building::update()
{
    RunInformation nowstate=scheduler.getSchedular();
    qDebug()<<nowstate.floor<<nowstate.num<<nowstate.inorout;
    if(nowstate.num==0&&nowstate.inorout=='E'&&nowstate.floor==0){
        timer->stop();
        judge.scheduleEnd();
    }else{
        if(nowstate.inorout=='I'){
            floorPeople.at(nowstate.floor).num-=nowstate.num;
        }else if(nowstate.inorout=='O'){
            arrival[nowstate.floor]+=nowstate.num;
        }
        for(int i=0;i<nowstate.num;i++){
            this->run(nowstate.floor,nowstate.inorout=='I'?1:0);
            emit this->updateGUI();
        }
        timer->start(100);
    }
    emit this->updateGUI();
}

void Building::reset()
{
    scheduler.reset();
    for(int i=0;i<28;i++)
        arrival[i]=0;
}
