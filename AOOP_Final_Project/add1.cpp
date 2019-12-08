#include "add1.h"

Add1::Add1()
{

}

string Add1::solve(string s)
{
    stringstream ss,ans;
    ss<<s;
    while(ss>>n){
        ans<<n+1<<" ";
    }
    s=ans.str();
    s.erase(s.size()-1);
    return s;
}
