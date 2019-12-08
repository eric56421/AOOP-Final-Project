#ifndef FINDFACTORIAL_H
#define FINDFACTORIAL_H

#include "mymath.h"

using namespace std;

class FindFactorial : public MyMath
{
    vector<int> numberofprime;
    vector<int> primelist;
    vector<int> factoriallist;
    const int N=10000001;
    vector<int> in;
    int n,left,right,middle,pos;
    public:
        FindFactorial();
        virtual string solve(string s) override;
        void set();
};

#endif // FINDFACTORIAL_H
