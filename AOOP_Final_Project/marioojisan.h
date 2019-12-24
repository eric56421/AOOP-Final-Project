#ifndef MARIOOJISAN_H
#define MARIOOJISAN_H

#include "mymath.h"

using namespace std;

class MarioOjisan : public MyMath
{
    int n,money,coin,i;
    public:
        MarioOjisan();
        virtual string solve(string s) override;
};

#endif // MARIOOJISAN_H
