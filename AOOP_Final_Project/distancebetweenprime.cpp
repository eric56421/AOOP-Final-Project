#include "distancebetweenprime.h"

DistanceBetweenPrime::DistanceBetweenPrime()
{

}

string DistanceBetweenPrime::solve(string s)
{
    if(ans.empty()){
        vector<bool> isprime;
        vector<int> primelist;
        isprime.resize(maxk+1,true);
        isprime.at(0)=isprime.at(1)=false;
        for(int i=2;i<=maxk;i++){
            if(isprime.at(i)==true){
                for(int j=2;i*j<=maxk;j++){
                    isprime.at(i*j)=false;
                }
                primelist.push_back(i);
            }
        }
        isprime.clear();
        ans.push_back(0);
        ans.push_back(0);
        int index=0;
        for(int i=2;i<=maxk;i++){
            if(i==primelist.at(index)){
                ans.push_back(0);
                index++;
            }else{
                ans.push_back(primelist.at(index)-primelist.at(index-1));
            }
        }
    }
    in = stringToVectorInt(s);
    for(int i=in.size()-1;i>=0;i--){
        in.at(i)=ans.at(in.at(i));
    }
    return vectorIntToString(in);
}
