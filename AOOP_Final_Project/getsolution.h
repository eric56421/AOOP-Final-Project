#ifndef GETSOLUTION_H
#define GETSOLUTION_H

#include "mymath.h"

using namespace std;

class GetSolution : public MyMath
{
    int n,row,col,i,j,mul;
    public:
        GetSolution();
        virtual string solve(string s) override;
};

#endif // GETSOLUTION_H
