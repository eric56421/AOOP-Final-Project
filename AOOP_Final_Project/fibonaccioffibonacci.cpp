#include "fibonaccioffibonacci.h"

FibonacciOfFibonacci::FibonacciOfFibonacci()
{
    fibmod60.push_back(0);
    fibmod60.push_back(1);
    for(int i=2;i<120;i++){
        fibmod60.push_back((fibmod60[i-1]+fibmod60[i-2])%60);
    }
    fibmod10.push_back(0);
    fibmod10.push_back(1);
    for(int i=2;i<60;i++){
        fibmod10.push_back(fibmod60.at(i)%10);
    }
}

string FibonacciOfFibonacci::solve(string s)
{
    in=stringToVectorInt(s);
    for(int i=0;i<in.size();i++){
        in[i]=fibmod10[(fibmod60[in[i]%120])];
    }
    return vectorIntToString(in);
}
