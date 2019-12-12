#ifndef JUDGEWINDOW_H
#define JUDGEWINDOW_H

#include <QWidget>

#include <QtGlobal>
#include <QElapsedTimer>
#include <QDebug>

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

    public:
        string getData(int floor,int b);//input 0-26
        bool submitData(string ans);
        void setSeed(int seed){srand(seed);}
        qint64 getSpendTime(){return costtime;}
        int getConditionNum();//return 1-300
        int getDistance(){return distance;}
        void scheduleEnd();
    private:
        string ans;
        ifstream in;
        ofstream out;
        QElapsedTimer timer;
        qint64 costtime[27];
        int correctansnum[27];
        int questionnum[27];
        int distance;
};

#endif // JUDGEWINDOW_H
