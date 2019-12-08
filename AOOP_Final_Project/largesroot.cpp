#include "largesroot.h"

LargesRoot::LargesRoot()
{

}

string LargesRoot::solve(string s)
{
    in=stringToVectorDouble(s);
    maxnode=0;
    maxvalue=-DBL_MAX;
    for(int i=7;i>0;i--){
        in.at(i-1)+=(in.at(i*2-1)+in.at(i*2))/2;
        if(in.at(i*2-1)>maxvalue){
            maxvalue=in.at(i*2-1);
            maxnode=i*2;
        }
        if(in.at(i*2)>maxvalue){
            maxvalue=in.at(i*2);
            maxnode=i*2+1;
        }
    }
    if(in.at(0)>maxvalue){
        maxvalue=in.at(0);
        maxnode=1;
    }
    stringstream ss;
    ss<<maxnode<<":"<<fixed<<setprecision(3)<<maxvalue;

    return ss.str();
}
