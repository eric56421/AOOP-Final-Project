#ifndef MYDATABASE_H
#define MYDATABASE_H

#include "problemset.h"

#include <vector>
#include <sstream>
#include <string>
#include <iomanip>

#include <QDebug>
#include <QSqlQuery>
#include <QSqlResult>
#include <QSqlDatabase>
#include <QSqlError>

using namespace std;

class MyDatabase : public ProblemSet
{
    public:
        MyDatabase();
        virtual string solve(string s) = 0;
        void connectMySQL();
        void setupCityDB();

};

#endif // MYDATABASE_H
