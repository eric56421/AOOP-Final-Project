#ifndef SHORTESTSUMMATIONDISTANCE_H
#define SHORTESTSUMMATIONDISTANCE_H

#include<mymath.h>
#include<math.h>

class ShortestSummationDistance : public MyMath
{
    struct point{
        int x,y;
    };
    public:
        ShortestSummationDistance();
        string solve(string s);
};

#endif // SHORTESTSUMMATIONDISTANCE_H
