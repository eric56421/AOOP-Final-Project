#ifndef FIBONACCIOFFIBONACCI_H
#define FIBONACCIOFFIBONACCI_H

#include "mymath.h"

using namespace std;

class FibonacciOfFibonacci : public MyMath
{
    int n;
    public:
        FibonacciOfFibonacci();
        virtual string solve(string s) override;
};

#endif // FIBONACCIOFFIBONACCI_H
