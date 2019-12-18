#ifndef DATA_H
#define DATA_H

#include <string>
#include <QtGlobal>
#include <people.h>

using namespace std;

class Data
{
    public:
        Data();
        qint64 spendtime;
        string testdata;
        string submit;
        bool correct;
        int distance;
        int nowfloor;
        int peopleinelevator;
};

#endif // DATA_H
