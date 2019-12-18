#ifndef SUBTRACT1_H
#define SUBTRACT1_H

#include "mymath.h"

using namespace std;

class Subtract1 : public MyMath
{
        int n;
    public:
        Subtract1();
        virtual string solve(string s) override;
};

#endif // SUBTRACT1_H
