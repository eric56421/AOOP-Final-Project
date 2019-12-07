#ifndef DATA_H
#define DATA_H

#include <string>
#include <QtGlobal>

using namespace std;

class Data
{
    public:
        Data();
        qint64 spendtime;
        string testdata;
        string submit;
        bool correct;
        int score;
        int nowfloor;
};

#endif // DATA_H
