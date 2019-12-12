#ifndef BUILDING_H
#define BUILDING_H

#include <QDebug>
#include <QSqlResult>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QTimer>

#include <string>
#include <cstdlib>

#include "scheduler.h"
#include "judge.h"
#include "judgewindow.h"
#include "data.h"
#include "floor.h"
#include "people.h"
#include "problems.h"

using namespace std;

class Building : public QObject
{
    Q_OBJECT
    public:
        Building();
        void run(int floorNum);
        Data getData() {return data;}
        void startSimulation();
        void reset();
        void setupPeopleInfo();
        vector<People> floorPeople;

    private:
        int peopleInfoState;
        //Judge judge;
        JudgeWindow judgeWindow;
        Floor *floor[28];
        Data data;
        QTimer *timer;
        Scheduler scheduler;

    public slots:
        void update();

    signals:
        void updateGUI();
};

#endif // BUILDING_H
