#ifndef LARGEFACTORIAL_H
#define LARGEFACTORIAL_H

#include "mymath.h"

using namespace std;

class LargeFactorial : public MyMath
{
    int n,i,j,a,exp10;
    vector<long long int> ans;
    public:
        LargeFactorial();
        virtual string solve(string s) override;
};

#endif // LARGEFACTORIAL_H
