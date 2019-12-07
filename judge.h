#ifndef JUDGE_H
#define JUDGE_H

#include <QtGlobal>
#include <QElapsedTimer>
#include <QDebug>

#include <string>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

class Judge
{
    public:
        Judge();
        string getData(int floorNum);
        bool submitData(string ans);
        qint64 getSpendTime() {return costtime;}
        int getScore(){return score;}

    private:
        string ans;
        ifstream in;
        QElapsedTimer timer;
        qint64 costtime;
        int score;
};

#endif // JUDGE_H
