#ifndef JUDGEWINDOW_H
#define JUDGEWINDOW_H

#include <QWidget>

#include <QtGlobal>
#include <QElapsedTimer>
#include <QDebug>
#include <QLineEdit>

#include <string>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>

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
        string getData(int floor,int b);//input 0-26
        bool submitData(string ans);
        void setSeed(int seed){srand(seed);}
        qint64 getSpendTime(){return costtime[floor];}
        int getConditionNum();//return 1-300
        int getDistance(){return distance;}
        void scheduleEnd();
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
};

#endif // JUDGEWINDOW_H
