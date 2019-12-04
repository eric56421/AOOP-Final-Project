#include "building.h"

Building::Building() : peopleInfoState(rand()%30 + 1)  // 30 is the # of states in data.csv
{    
        // destructor
    floor[0] = new Floor(new Add1);
    floor[1] = new Floor(new Prime);
    floor[2] = new Floor(new LongestPair);
    floor[3] = new Floor(new ShyGame);
    floor[4] = new Floor(new FibonacciOfFibonacci);
    floor[8] = new Floor(new FindFactorial);
    floor[9] = new Floor(new ShortestSummationDistance);

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

        at = query.value(1).toInt();
        to = query.value(2).toInt();
        num = query.value(3).toInt();

        qDebug()<<at<<to<<num;

        floorPeople.at(at).to = to;
        floorPeople.at(at).num = num;
    }
//    qDebug()<<floorPeople.at(1).to;
//    qDebug()<<floorPeople.at(1).num;
}

void Building::run(int n)
{
    data.testdata = judge.getData(n);
    data.submit = floor[n]->p->solve(data.testdata);
    data.correct = judge.submitData(data.submit);
    data.spendtime = judge.getSpendTime();
}
