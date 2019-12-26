#ifndef MAZE_H
#define MAZE_H

#include <stack>
#include "myother.h"

using namespace std;

class Maze : public MyOther
{
    struct point{
        int x,y;
    };
    public:
        Maze();
        virtual string solve(string s) override;
};



#endif // MAZE_H
