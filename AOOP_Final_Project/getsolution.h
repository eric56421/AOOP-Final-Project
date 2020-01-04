#ifndef GETSOLUTION_H
#define GETSOLUTION_H

#include "mymath.h"

using namespace std;

class GetSolution : public MyMath
{
    int n,i,j,k,r;
    double p;
    double *ans;
    double **matrix;
    int min;
    public:
        GetSolution();
        virtual string solve(string s) override;
};

#endif // GETSOLUTION_H
