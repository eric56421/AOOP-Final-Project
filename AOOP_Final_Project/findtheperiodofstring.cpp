#include "findtheperiodofstring.h"

FindThePeriodOfString::FindThePeriodOfString()
{

}

string FindThePeriodOfString::solve(string s)
{
    n=0;
    for(int i=1;i<s.size()&&!n;i++){
        if(s.size()%i==0){
            tmp=s.substr(0,i);
            for(int j=1;j<s.size()/i;j++){
                if(tmp!=s.substr(j*tmp.size(),i)){
                    n=0;
                    break;
                }
                n=i;
            }
        }
    }
    if(n==0)
        n=s.size();
    return to_string(n);
}
