#include "longestpeekpalindrome.h"

LongestPeekPalindrome::LongestPeekPalindrome()
{

}

string LongestPeekPalindrome::solve(string s)
{
    int pos=0,prev=0,i;
    string s1;

    while((pos=s.find_first_of("?!,.",pos))!=string::npos)
    {
        s1+=s.substr(prev,pos-prev);
        prev=++pos;
    }
    s1+=s.substr(prev);

    for(i=0;i<s1.length()-1;i++)
    {
        s1[i]=toupper(s1[i]);
    }

    return findLongestPalindromicString(s1);
}

string findLongestPalindromicString(string s)
{
    int N = s.length();//
    if(N == 0)
        return "\0";
    N = 2*N + 1; //Position count
    int L[N]; //LPS Length Array
    L[0] = 0;
    L[1] = 1;
    int C = 1; //centerPosition
    int R = 2; //centerRightPosition
    int i = 0; //currentRightPosition
    int iMirror; //currentLeftPosition
    int maxLPSLength = 0;
    int maxLPSCenterPosition = 0;
    int start = -1;
    int end = -1;
    int diff = -1;

    //Uncomment it to print LPS Length array
    //printf("%d %d ", L[0], L[1]);
    for (i = 2; i < N; i++)
    {
        //get currentLeftPosition iMirror for currentRightPosition i
        iMirror  = 2*C-i;
        L[i] = 0;
        diff = R - i;
        //If currentRightPosition i is within centerRightPosition R
        if(diff > 0)
            L[i] = min(L[iMirror], diff);

        //Attempt to expand palindrome centered at currentRightPosition i
        //Here for odd positions, we compare characters and
        //if match then increment LPS Length by ONE
        //If even position, we just increment LPS by ONE without
        //any character comparison
        while ( ((i + L[i]) < N && (i - L[i]) > 0) &&
            ( ((i + L[i] + 1) % 2 == 0) ||
            (s[(i + L[i] + 1)/2] == s[(i - L[i] - 1)/2] )))
        {
            L[i]++;
        }

        if(L[i] > maxLPSLength)  // Track maxLPSLength
        {
            maxLPSLength = L[i];
            maxLPSCenterPosition = i;
        }

        //If palindrome centered at currentRightPosition i
        //expand beyond centerRightPosition R,
        //adjust centerPosition C based on expanded palindrome.
        if (i + L[i] > R)
        {
            C = i;
            R = i + L[i];
        }
        //Uncomment it to print LPS Length array
        //printf("%d ", L[i]);
    }
    //printf("\n");
    start = (maxLPSCenterPosition - maxLPSLength)/2;
    end = start + maxLPSLength - 1;
    return s.substr(start,end-start+1);
}

int min(int a, int b)
{
    int res = a;
    if(b < a)
        res = b;
    return res;
}
