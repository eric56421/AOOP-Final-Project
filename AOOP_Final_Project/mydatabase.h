#ifndef MYDATABASE_H
#define MYDATABASE_H

#include "problemset.h"

#include <vector>
#include <sstream>
#include <string>

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

    private:
        void connectMySQL();
        void setupCityDB();
};

#endif // MYDATABASE_H
