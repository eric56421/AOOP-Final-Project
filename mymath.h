#ifndef MYMATH_H
#define MYMATH_H

#include<problemset.h>
#include<vector>
#include<sstream>
#include<algorithm>
#include <iomanip>

using namespace std;

class MyMath : public ProblemSet
{
    public:
        MyMath();
        string solve(string)=0;
        vector<int>stringToVectorInt(string);
        string vectorIntToString(vector<int>);
        vector<double>stringToVectorDouble(string);
        string vectorDoubleToString(vector<double>);
        string vectorIntToStringOfFactorial(vector<int>);
};

#endif // MYMATH_H
