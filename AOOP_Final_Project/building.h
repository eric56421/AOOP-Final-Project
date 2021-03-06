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
        int arrival[28];
        vector<People> floorPeople;
        
        Building();
        void setupPeopleInfo(int);
        void reset();
        void run(int floorNum,int b);
        void startSimulation();
        Data getData() {return data;}

    private:
        JudgeWindow judge;
        Floor *floor[28];
        Data data;
        QTimer *timer;
        Scheduler scheduler;        

        void connectMySQL();
        void setupProblemTB();
        void setupPeopleTB();

    public slots:
        void update();

    signals:
        void updateGUI();
};

#endif // BUILDING_H
