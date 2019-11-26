#include "judge.h"
#include <QElapsedTimer>
#include <QtGlobal>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <QDebug>

using namespace std;

Judge::Judge()
{
    timer.start();
    srand(time(NULL));
}

string Judge::getData(int question)
{
    string tmp;
    vector<string> dataV, ansV;    

    in.open(to_string(question)+".txt");  // to_string(question)+".txt"
    if (!in)
        qDebug()<<"open fail"<<endl;
    else {
        qDebug()<<"open"<<endl;
    }

    while (getline(in, tmp)) {
        dataV.push_back(tmp);
        getline(in, tmp);
        ansV.push_back(tmp);
    }
    in.close();

    int n = rand() % dataV.size();
    ans = ansV.at(n);

    timer.restart();

    return dataV.at(n);
}

bool Judge::submitData(string ans)
{
    this->costtime = this->timer.nsecsElapsed();
    qDebug()<<QString::fromStdString(ans)<<endl;
    qDebug()<<QString::fromStdString(this->ans)<<endl;

    return ans == this->ans;
}
