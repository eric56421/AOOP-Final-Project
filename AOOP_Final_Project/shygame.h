#ifndef SHYGAME_H
#define SHYGAME_H

#include <queue>

#include "mymath.h"

using namespace std;

class ShyGame : public MyMath
{
    vector<int> in,people;
    int n,num,now;
    string ts;
    stringstream ss, t;
    int p, st[100000], i, j, M;
    public:
        ShyGame();
        virtual string solve(string s) override;
};

#endif // SHYGAME_H
