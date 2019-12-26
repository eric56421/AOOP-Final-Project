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
#include <QCheckBox>
#include <QLabel>

#include <string>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <math.h>

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
        QLineEdit showline[27][4];
        QCheckBox giveout[27];
        QLabel floorLabel[27];

    private:
        Ui::JudgeWindow *ui;

    public:
        string getData(int floor,int b,int &datatimes);//input 0-26  --> 1-27
        void setSeed(int seed = time(NULL)){srand(seed); peopleInfoState = 1;}  //= rand()%300+1;}
        bool submitData(string ans);
        qint64 getSpendTime(){return costtime[floor];}
        int getConditionNum(){return peopleInfoState;}//return 1-300
        int getDistance(){return distance;}
        int getFloor(){return floor;}
        int getPeopleInElevator(){return peopleinelevator;}
        void scheduleEnd();
        void reset();
        //void setupPeopleInfo(const vector<People> &);
        void showPeopleInfo();

    private slots:
        void on_ExportButton_clicked();

    private:
        string ans;
        ofstream out;
        QElapsedTimer timer;
        qint64 costtime[28];
        int correctansnum[28];
        int questionnum[28];
        int distance;
        int floor;
        int peopleInfoState;
        int peopleinelevator;
        int floordatatimes[28];
        int runtime;
        int floornextdata[28];
        long long score[28];
        //vector<People> floorPeople;
        //vector<int> arrival;

        void uploadToTAMySQL();
};

#endif // JUDGEWINDOW_H
