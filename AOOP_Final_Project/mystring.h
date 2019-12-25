#ifndef MYSTRING_H
#define MYSTRING_H

#include "problemset.h"

using namespace std;

class MyString : public ProblemSet
{
    public:
        MyString();
        virtual string solve(string s) = 0;
};

#endif // MYSTRING_H
