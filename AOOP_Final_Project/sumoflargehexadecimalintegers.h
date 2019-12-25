#ifndef SUMOFLARGEHEXADECIMALINTEGERS_H
#define SUMOFLARGEHEXADECIMALINTEGERS_H

#include "mymath.h"

using namespace std;

class SumOfLargeHexadecimalIntegers : public MyMath
{
    vector<long long int> ans;
    int i,n;
    public:
        SumOfLargeHexadecimalIntegers();
        virtual string solve(string s) override;
};

#endif // SUMOFLARGEHEXADECIMALINTEGERS_H
