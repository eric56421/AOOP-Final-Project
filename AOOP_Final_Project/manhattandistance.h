#ifndef MANHATTANDISTANCE_H
#define MANHATTANDISTANCE_H

#include "mydatabase.h"

class ManhattanDistance : public MyDatabase
{
    public:
        ManhattanDistance();
        string solve(string s);
};

#endif // MANHATTANDISTANCE_H
