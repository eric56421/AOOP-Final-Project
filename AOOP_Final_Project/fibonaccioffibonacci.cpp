#include "fibonaccioffibonacci.h"

FibonacciOfFibonacci::FibonacciOfFibonacci()
{

}

string FibonacciOfFibonacci::solve(string s)
{
    int fibmod60[120];
    fibmod60[0]=0;
    fibmod60[1]=1;
    for(int i=2;i<120;i++){
        fibmod60[i]=(fibmod60[i-1]+fibmod60[i-2])%60;
    }
    stringstream ss,ans;
    ss<<s;
    while(ss>>n){
        ans<<fibmod60[fibmod60[n%120]]%10<<" ";
    }
    s=ans.str();
    s.resize(s.size()-1);
    return s;
}
