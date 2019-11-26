#ifndef FIBONACCIOFFIBONACCI_H
#define FIBONACCIOFFIBONACCI_H

#include<mymath.h>

class FibonacciOfFibonacci : public MyMath
{
    private:
        vector<int> fibmod60;
    public:
        FibonacciOfFibonacci();
        string solve(string s);
};

#endif // FIBONACCIOFFIBONACCI_H
