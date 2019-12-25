#ifndef FINDTHEPERIODOFSTRING_H
#define FINDTHEPERIODOFSTRING_H

#include "mystring.h"

using namespace std;

class FindThePeriodOfString : public MyString
{
    int n,i;
    string tmp;
    public:
        FindThePeriodOfString();
        virtual string solve(string s) override;
};

#endif // FINDTHEPERIODOFSTRING_H
