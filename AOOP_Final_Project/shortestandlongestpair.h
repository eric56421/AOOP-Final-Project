#ifndef SHORTESTANDLONGESTPAIR_H
#define SHORTESTANDLONGESTPAIR_H

#include <float.h>
#include <cmath>

#include "mymath.h"

using namespace std;

class ShortestAndLongestPair : public MyMath
{
    vector<Point3D> data;
    double dx,dy,dz;
    public:
        ShortestAndLongestPair();
        virtual string solve(string s) override;
};

#endif // SHORTESTANDLONGESTPAIR_H
