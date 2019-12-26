#ifndef LONGESTCOMMONSUBSTRING_H
#define LONGESTCOMMONSUBSTRING_H

#include "mystring.h"

using namespace std;

class LongestCommonSubstring : public MyString
{
    public:
        LongestCommonSubstring();
        virtual string solve(string s) override;
};

#endif // LONGESTCOMMONSUBSTRING_H
