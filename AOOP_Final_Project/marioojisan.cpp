#include "marioojisan.h"

MarioOjisan::MarioOjisan()
{

}

string MarioOjisan::solve(string s)
{
    stringstream ss;
    ss<<s;
    ss>>n;
    int a[n];
    for(i=0;i<n;i++)
        ss>>a[i];
    money = a[0];
    coin = 2;
    for(i=1;i<n-1;i++)
        if(money<a[i]&&money+a[i]<a[i+1]){
            money+=a[i];
            coin++;
        }
    return to_string(coin);
}

//dp 去解
