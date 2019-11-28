#ifndef SHORTESTSUMMATIONDISTANCE_H
#define SHORTESTSUMMATIONDISTANCE_H

#include<mymath.h>
#include<math.h>
#include <algorithm>
#include <QDebug>

using namespace std;

class ShortestSummationDistance : public MyMath
{
    struct point{
        int x,y;
    };
    const int INF  =  0x3f3f3f3f;
    public:
        ShortestSummationDistance();
        string solve(string s);
};

#endif // SHORTESTSUMMATIONDISTANCE_H
