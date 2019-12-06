#ifndef BUILDING_H
#define BUILDING_H

#include <QDebug>
#include <QSqlResult>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>

#include <string>
#include <cstdlib>

#include "judge.h"
#include "data.h"
#include "floor.h"
#include "people.h"
#include "problems.h"

using namespace std;

class Building
{
public:
    Building();
    void run(int floorNum);
    Data getData() {return data;}
    vector<People> floorPeople;

    void setupPeopleInfo();

private:
    const int peopleInfoState;
    Judge judge;
    Floor *floor[31];
    Data data;

};

#endif // BUILDING_H
