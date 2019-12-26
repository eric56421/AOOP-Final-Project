#ifndef LONGESTPEEKPALINDROME_H
#define LONGESTPEEKPALINDROME_H

#include "mystring.h"

using namespace std;

class LongestPeekPalindrome : public MyString
{
    public:
        LongestPeekPalindrome();
        virtual string solve(string s) override;
};

int min(int a, int b);
string findLongestPalindromicString(string s);

#endif // LONGESTPEEKPALINDROME_H
