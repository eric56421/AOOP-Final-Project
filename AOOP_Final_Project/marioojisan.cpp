#include "marioojisan.h"

MarioOjisan::MarioOjisan()
{

}

string MarioOjisan::solve(string s)
{
  /*  ans.clear();
    in=stringToVectorInt(s);
    index=0,c=1;
    while(index<in.size()){
        numofcoin = in.at(index);
        n=in.at(index+numofcoin)-1;
        for(int i=numofcoin-1;i>0;i--){
            if(in.at(index+numofcoin)<n){
                n-=in.at(index+i);
                c++;
            }
        }
        ans.push_back(c);
        index+=numofcoin+1;
    }*/


    return vectorIntToString(ans);
}

//dp 去解
