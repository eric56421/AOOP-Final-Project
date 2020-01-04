#ifndef MARIOOJISAN_H
#define MARIOOJISAN_H

#include "mymath.h"

using namespace std;

class MarioOjisan : public MyMath
{
    //int n,money,coin,i;
    stringstream ss;
    int n, result, pre_sum, max;
    int *coin = new int[100000000];
    public:
        MarioOjisan();
        virtual string solve(string s) override;
};

#endif // MARIOOJISAN_H
