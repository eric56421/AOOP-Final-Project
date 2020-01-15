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
    public:
        ShortestAndLongestPair();
        virtual string solve(string s) override;
        double sqrtOfDis(const Point &p1,const Point &p2)
        {
            return (p1.x-p2.x)*(p1.x-p2.x)+ (p1.y-p2.y)*(p1.y-p2.y)+ (p1.z-p2.z)*(p1.z-p2.z);
        }
};

#endif // SHORTESTANDLONGESTPAIR_H
