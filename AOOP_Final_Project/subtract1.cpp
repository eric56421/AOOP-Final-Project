#include "subtract1.h"

Subtract1::Subtract1()
{

}

string Subtract1::solve(string s)
{
    stringstream ss,ans;
    ss<<s;
    while(ss>>n){
        ans<<n-1<<" ";
    }
    s=ans.str();
    s.erase(s.size()-1);
    return s;
}
