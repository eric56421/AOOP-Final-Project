#include "longestpair.h"

LongestPair::LongestPair()
{

}

string LongestPair::solve(string s){
    vector<double> in=stringToVectorDouble(s);
    double dx,dy,dz;
    double maxLen=pow(in[0]-in[3],2)+pow(in[1]-in[4],2)+pow(in[2]-in[5],2);
    for(int i=0;i<(in.size()+1)/3-1;i++){
        for(int j=i+1;j<(in.size()+1)/3;j++){
            dx=pow(in[i*3]-in[j*3],2),dy=pow(in[i*3+1]-in[j*3+1],2),dz=pow(in[i*3+2]-in[j*3+2],2);
            if(dx+dy+dz>maxLen)
                maxLen=dx+dy+dz;
        }
    }
    maxLen=sqrt(maxLen);
    return to_string((int)(maxLen))+"."+to_string(((int)(maxLen*100))%100);
}
