#ifndef SHORTESTSUMMATIONDISTANCE_H
#define SHORTESTSUMMATIONDISTANCE_H

#include "mymath.h"
#include <algorithm>
#include<math.h>

using namespace std;

class ShortestSummationDistance : public MyMath
{
    struct point{
        int x,y;
    };
    const int INF  =  0x3f3f3f3f;
    vector<int> in;
    int n,ind;
    point tmp;
    double *dp;
    double **dis;
    public:
        ShortestSummationDistance();
        virtual string solve(string s) override;
};

#endif // SHORTESTSUMMATIONDISTANCE_H
