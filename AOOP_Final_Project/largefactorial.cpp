#include "largefactorial.h"

LargeFactorial::LargeFactorial()
{

}

string LargeFactorial::solve(string s)
{
    stringstream ss;
    n=stoi(s);
    ans.clear();
    ans.push_back(1);
    exp10=0;
    for(i=2;i<=n;i++){
        a=i;
        while(a%10==0){
            exp10++;
            a/=10;
        }
        for(j=0;j<ans.size();j++){
            if(j==0)
                ans[j]*=a;
            else{
                ans[j]=a*ans[j]+ans[j-1]/10;
                ans[j-1]%=10;
            }
        }
        while(ans[ans.size()-1]>=10){
            ans.push_back(ans[ans.size()-1]/10);
            ans[ans.size()-2]%=10;
        }
        while(ans[0]==0){
            exp10++;
            ans.erase(ans.begin());
        }
    }
    s="";
    for(int i=ans.size()-1;i>=0;i--)
        ss<<ans[i];
    for(int i=0;i<exp10;i++)
        ss<<"0";
    return ss.str();
}
