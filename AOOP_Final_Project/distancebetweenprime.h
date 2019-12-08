#ifndef DISTANCEBETWEENPRIME_H
#define DISTANCEBETWEENPRIME_H

#include "mymath.h"

using namespace std;

class DistanceBetweenPrime : public MyMath
{

    vector<int> ans;
    vector<int> in;
    const int maxk = 1299709;
    public:
        DistanceBetweenPrime();
        virtual string solve(string s) override;
};

#endif // DISTANCEBETWEENPRIME_H
