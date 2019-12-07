#ifndef MYTREE_H
#define MYTREE_H

#include <vector>
#include <sstream>
#include <algorithm>
#include <iomanip>

#include "problemset.h"

using namespace std;

class MyTree : public ProblemSet
{
    public:
        MyTree();
        virtual string solve(string s) = 0;
        vector<double> stringToVectorDouble(string s);
};

#endif // MYTREE_H
