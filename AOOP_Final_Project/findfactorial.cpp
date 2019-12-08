#include "findfactorial.h"

FindFactorial::FindFactorial()
{
    set();
}

string FindFactorial::solve(string s)
{
    stringstream ss;
    in = stringToVectorInt(s);
    for(int i=0;i<in.size();i++){
        n = in.at(i);
        pos = -1;
        left = 0;
        right = factoriallist.size();
        while(left<=right){
            middle = (left+right)/2;
            if(factoriallist.at(middle) == n){
                pos = middle;
                break;
            }else if(factoriallist.at(middle)>n){
                right = middle-1;
            }else{
                left = middle+1;
            }
        }
        if(pos!=-1)
            ss<<pos<<"! ";
        else
            ss<<"N ";
    }
    s=ss.str();
    s.erase(s.size()-1);
    return s;
}
