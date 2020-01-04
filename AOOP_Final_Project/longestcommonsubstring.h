#ifndef LONGESTCOMMONSUBSTRING_H
#define LONGESTCOMMONSUBSTRING_H

#include "mystring.h"

using namespace std;

class LongestCommonSubstring : public MyString
{
    public:
        LongestCommonSubstring();
        virtual string solve(string s);
        string lcs(string X, string Y);
        string preProcess(const string &s);
};

#endif // LONGESTCOMMONSUBSTRING_H
