#ifndef JUDGEWINDOW_H
#define JUDGEWINDOW_H

#include <QWidget>

#include <QtGlobal>
#include <QElapsedTimer>
#include <QDebug>
#include <QSqlResult>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QLineEdit>

#include <string>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>

#include "people.h"

using namespace std;

namespace Ui {
class JudgeWindow;
}

class JudgeWindow : public QWidget
{
    Q_OBJECT

    public:
        explicit JudgeWindow(QWidget *parent = nullptr);
        ~JudgeWindow();

    private:
        Ui::JudgeWindow *ui;
        QLineEdit showline[27][4];

    public:
        string getData(int floor,int b);//input 0-26  --> 1-27
        bool submitData(string ans);
        void setSeed(int seed = time(NULL)){srand(seed); peopleInfoState = rand()%300+1;}
        qint64 getSpendTime(){return costtime[floor];}
        int getConditionNum();//return 1-300
        int getDistance(){return distance;}
        void scheduleEnd();
        void connectDB();
        void setupProblemDB();
        void setupPeopleDB();
        void setupPeopleInfo();
        void readPeopleInfo();
        vector<People> floorPeople;

    private:
        string ans;
        ifstream in;
        ofstream out;
        QElapsedTimer timer;
        qint64 costtime[28];
        int correctansnum[28];
        int questionnum[28];
        int distance;
        int floor;
        int peopleInfoState;
};

#endif // JUDGEWINDOW_H
