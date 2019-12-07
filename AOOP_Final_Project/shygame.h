#ifndef SHYGAME_H
#define SHYGAME_H

#include <queue>

#include "mymath.h"

using namespace std;

class ShyGame : public MyMath
{
    public:
        ShyGame();
        virtual string solve(string s) override;
};

#endif // SHYGAME_H
