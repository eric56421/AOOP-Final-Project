#ifndef SHYGAME_H
#define SHYGAME_H

#include "mymath.h"
#include <queue>

using namespace std;

class ShyGame : public MyMath
{
    public:
        ShyGame();
        string solve(string s);
};

#endif // SHYGAME_H
