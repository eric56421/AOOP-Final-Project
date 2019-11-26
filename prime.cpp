#include "prime.h"

Prime::Prime()
{

}

string Prime::solve(string s){
    vector<int> in=stringToVectorInt(s);
    int max=0;
    for(int i=0;i<in.size();i++){
        if(max<in[i])
            max=in[i];
    }
    vector<bool> list(max+1,1);
    list[0]=list[1]=0;
    for(int i=2;i*i<=max;i++){
        for(int j=2;j*i<=max;j++)
            list[j*i]=0;
    }
    for(int i=0;i<in.size();i++){
        for(int j=in[i];j>1;j--)
            if(list[j]==1){
                in[i]=j;
                break;
            }
    }
    return vectorIntToString(in);
}
