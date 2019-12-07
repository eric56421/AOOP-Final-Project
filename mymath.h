#ifndef MYMATH_H
#define MYMATH_H

#include <vector>
#include <sstream>
#include <algorithm>
#include <iomanip>

#include "problemset.h"

using namespace std;

class MyMath : public ProblemSet
{
    protected:
        struct Point3D{
            double x;
            double y;
            double z;
        };
    public:
        MyMath();
        virtual string solve(string s) = 0;
        vector<int> stringToVectorInt(string s);
        string vectorIntToString(vector<int> v);
        vector<double> stringToVectorDouble(string s);
        string vectorDoubleToString(vector<double> v);
        vector<Point3D> stringToVectorPoint3D(string s);
};

#endif // MYMATH_H
