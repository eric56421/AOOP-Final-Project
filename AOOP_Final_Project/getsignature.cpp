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

/*
    stringstream ss(s);
    int n;
    ss >> n;
    vector<int> cele(n + 1), sign(n + 1, 0);
    vector<bool> traversal(n + 1, 0);

    int index = 0;
    while (ss >> index && ss >> cele[index])
        ;
    int now;
    for (int i = n; i >= 1; i--){
        now = i;
        traversal[now] = 1;
        while (!traversal[cele[now]])
        {
            now = cele[now];
            traversal[now] = 1;
            sign[i]++;
        }
        std::fill(traversal.begin(), traversal.end(), 0);
    }
    return to_string(max_element(sign.begin(), sign.end()) - sign.begin());
*/
}

bool order(GetSignature::link& n1,GetSignature::link& n2)
{
    if(n1.from<n2.from)
        return true;
    return false;
}
