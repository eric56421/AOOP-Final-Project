#include "fibonaccioffibonacci.h"

FibonacciOfFibonacci::FibonacciOfFibonacci(){
    fibmod60.push_back(0);
    fibmod60.push_back(1);
    for(int i=2;i<120;i++){
        fibmod60.push_back((fibmod60[i-1]+fibmod60[i-2])%60);
    }
}

string FibonacciOfFibonacci::solve(string s){
    vector<int> in=stringToVectorInt(s);
    for(int i=0;i<in.size();i++){
        in[i]=fibmod60[(fibmod60[in[i]%120])]%10;
    }
    return vectorIntToString(in);
}
