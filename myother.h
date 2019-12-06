#ifndef MYOTHER_H
#define MYOTHER_H

#include <vector>
#include <sstream>
#include <algorithm>
#include <iomanip>

#include "problemset.h"

using namespace std;

class MyOther : public ProblemSet
{
    public:
        MyOther();
        virtual string solve(string s) = 0;
        vector<int> stringToVectorInt(string s);
};

#endif // MYOTHER_H
