#ifndef MINESWEEPER_H
#define MINESWEEPER_H

#include <vector>
#include <sstream>

#include "myother.h"

using namespace std;

struct mi{
    int x;
    int y;
};

class Minesweeper : public MyOther
{
    public:
        Minesweeper();
        virtual string solve(string s) override;
};

#endif // MINESWEEPER_H
