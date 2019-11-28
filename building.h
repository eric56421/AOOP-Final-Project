#ifndef BUILDING_H
#define BUILDING_H

#include <QSqlResult>
#include <QSqlDatabase>
#include "judge.h"
#include "data.h"
#include "floor.h"
#include "people.h"
#include "add1.h"
#include "prime.h"
#include "longestpair.h"
#include "shygame.h"
#include "fibonaccioffibonacci.h"
#include "findfactorial.h"
#include "shortestsummationdistance.h"

class Building
{
public:
    Building();
    void run(int n);
    Data getData() {return data;}
    vector<People> floorPeople;

private:
    Judge judge;
    Floor *floor[15];
    Data data;

    void setUpDatabase();
    //Add1 add1;
    //Prime prime;
};

#endif // BUILDING_H
