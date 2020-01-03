#ifndef SHORTESTANDLONGESTPAIR_H
#define SHORTESTANDLONGESTPAIR_H

#include <float.h>
#include <cmath>

#include "mymath.h"

using namespace std;

struct Point{
    double x,y,z;
};

class ShortestAndLongestPair : public MyMath
{
    vector<Point3D> data;
    double dx,dy,dz;
    double x,y,z;
    double max_dis,min_dis;
    public:
        ShortestAndLongestPair();
        virtual string solve(string s) override;
};

#endif // SHORTESTANDLONGESTPAIR_H
