#ifndef MINESWEEPER_H
#define MINESWEEPER_H

#include <vector>
#include <sstream>

#include "myother.h"

using namespace std;

class Minesweeper : public MyOther
{
    struct Point2D{
        int x;
        int y;
    };
    int dir[8][2];
    public:
        Minesweeper();
        virtual string solve(string s) override;
};

#endif // MINESWEEPER_H
