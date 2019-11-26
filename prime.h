#ifndef PRIME_H
#define PRIME_H

#include<mymath.h>

using namespace std;

class Prime : public MyMath
{
    public:
        Prime();
        string solve(string s);
};

#endif // PRIME_H
