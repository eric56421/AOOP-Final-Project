#ifndef ADD1_H
#define ADD1_H

#include "mymath.h"

using namespace std;

class Add1 : public MyMath
{
    vector<int> in;
    public:
        Add1();
        virtual string solve(string s) override;
};

#endif // ADD1_H
