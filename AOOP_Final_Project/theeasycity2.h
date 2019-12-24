#ifndef THEEASYCITY2_H
#define THEEASYCITY2_H

#include "mydatabase.h"

class TheEasyCity2 : public MyDatabase
{
    public:
        TheEasyCity2();
        virtual string solve(string s);
};

#endif // THEEASYCITY2_H
