#include "getsignature.h"

GetSignature::GetSignature()
{

}

string GetSignature::solve(string s)
{
    stringstream ss;
    ss<<s;
    int n,max=0,start=0;
    ss>>n;
    vector<link> list(n);
    for(int i=0;i<n;i++){
        ss>>list.at(i).from>>list.at(i).to;
    }

    sort(list.begin(),list.end(),order);

    for(int i=0;i<n;i++){
        vector<bool> check(n+1,0);
        int now=i+1,c=1;
        check.at(now)=true;
        while(!check.at(list.at(now-1).to)){
            now=list.at(now-1).to;
            check.at(now)=true;
            c++;
        }
        if(c>max){
            max=c;
            start=i+1;
        }
    }

    return to_string(start);
}

bool order(GetSignature::link& n1,GetSignature::link& n2)
{
    if(n1.from<n2.from)
        return true;
    return false;
}
