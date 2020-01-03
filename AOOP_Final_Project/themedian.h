#ifndef THEMEDIAN_H
#define THEMEDIAN_H

#include "mydatabase.h"

class TheMedian : public MyDatabase
{
    public:
        TheMedian();
        virtual string solve(string s);
};

#endif // THEMEDIAN_H
