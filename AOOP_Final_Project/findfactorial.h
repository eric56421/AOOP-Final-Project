#ifndef FINDFACTORIAL_H
#define FINDFACTORIAL_H

#include <fstream>

#include "mymath.h"

using namespace std;

class FindFactorial : public MyMath
{
     vector<int> factoriallist;
     vector<int> in;
     int n,left,right,middle,pos;
     public:
         FindFactorial();
         virtual string solve(string s) override;
         void set();
};

#endif // FINDFACTORIAL_H
