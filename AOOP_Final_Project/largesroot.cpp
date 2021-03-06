#include "largesroot.h"

LargesRoot::LargesRoot()
{

}

string LargesRoot::solve(string s)
{
/*
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
*/

    stringstream ss;
    ss << s;
    int c = 0;
    double n;
    while (ss >> n)
        node[c++] = n;

    value[7] = node[7];
    value[8] = node[8];
    value[9] = node[9];
    value[10] = node[10];
    value[11] = node[11];
    value[12] = node[12];
    value[13] = node[13];
    value[14] = node[14];

    value[3] = node[3] + (value[7] + value[8]) / 2;
    value[4] = node[4] + (value[9] + value[10]) / 2;
    value[5] = node[5] + (value[11] + value[12]) / 2;
    value[6] = node[6] + (value[13] + value[14]) / 2;

    value[1] = node[1] + (value[3] + value[4]) / 2;
    value[2] = node[2] + (value[5] + value[6]) / 2;

    value[0] = node[0] + (value[1] + value[2]) / 2;

    int maxn = 0;
    for (int i = 1; i < 15; i++)
        maxn = (value[maxn] < value[i]) ? i : maxn;

    string ans;
    ss.clear();
    ss << fixed << setprecision(3) << value[maxn];
    ss >> ans;
    ans = to_string(maxn+1) + ':' + ans;

    return ans;

}
