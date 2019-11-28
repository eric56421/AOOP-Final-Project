#include "building.h"
#include <string>
#include <QDebug>
#include <QSqlResult>
#include <QSqlDatabase>
#include <QSqlQuery>
using namespace std;

Building::Building()
{
    setUpDatabase();

    // DElete
    floor[0] = new Floor(new Add1);
    floor[1] = new Floor(new Prime);
    floor[2] = new Floor(new LongestPair);
    floor[3] = new Floor(new ShyGame);
    floor[4] = new Floor(new FibonacciOfFibonacci);
    floor[8] = new Floor(new FindFactorial);
    floor[9] = new Floor(new ShortestSummationDistance);

}

void Building::run(int n)
{
    data.testdata = judge.getData(n);
    data.submit = floor[n]->p->solve(data.testdata);
    data.correct = judge.submitData(data.submit);
    data.spendtime = judge.getSpendTime();
}

void Building::setUpDatabase()
{
    QSqlQuery query;

    query.exec("DROP DATABASE IF EXISTS Course6;");
    query.exec("CREATE DATABASE Course6;");
    query.exec("USE Course6;");
    query.exec("DROP TABLE IF EXISTS peoplelist;");
    query.exec("CREATE TABLE peoplelist\
                (Id varchar(8), Nowfloor int, Destination int, Num int,\
                PRIMARY KEY (Id));");
    query.exec("load data infile 'C:/ProgramData/MySQL/MySQL Server 8.0/Uploads/data.csv'\
               into table peoplelist\
               fields terminated by ','\
               enclosed by ""\
               lines terminated by '\n'\
               ignore 1 rows;");

    srand(time(NULL));
    int state = rand()%30 + 1;
    string condition = to_string(state);
    if (state < 10)
        condition.insert(0, 1, '0');
    condition.insert(0, "'%");
    condition.insert(condition.size(), "-%';");
    condition.insert(0, "select * from peoplelist where Id like ");
    qDebug()<<QString::fromStdString(condition);
    query.exec(condition.c_str());

    qDebug()<<"hi";

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
    qDebug()<<floorPeople.at(0).to;
}
