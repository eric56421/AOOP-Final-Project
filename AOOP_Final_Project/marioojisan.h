#ifndef MARIOOJISAN_H
#define MARIOOJISAN_H

#include "mymath.h"

using namespace std;

class MarioOjisan : public MyMath
{
    vector<int> in,ans;
    int numofcoin,n,c,index;
    public:
        MarioOjisan();
        virtual string solve(string s) override;
};

#endif // MARIOOJISAN_H
