#include "marioojisan.h"

MarioOjisan::MarioOjisan()
{

}

string MarioOjisan::solve(string s)
{
//    stringstream ss;
//    ss<<s;
//    ss>>n;
//    int a[n];
//    for(i=0;i<n;i++)
//        ss>>a[i];
//    money = a[0];
//    coin = 2;
//    for(i=1;i<n-1;i++)
//        if(money<a[i]&&money+a[i]<a[i+1]){
//            money+=a[i];
//            coin++;
//        }
//    return to_string(coin);
    string ans;
    ss.clear();
    ss << s;
    ss >> n;
    ss >> max;
    for (int i = 1; i < n; i++)
        ss >> coin[i];
    result = 1;
    for (int i = 1; i < n - 1; i++)
    {
        if(max + coin[i] < coin[i + 1])
        {
            max += coin[i];
            result++;
        }
    }
    ans = to_string(result + 1);
    while (ss >> n)
    {
        int *coin = new int[n];
        for (int i = 0; i < n; i++)
            ss >> coin[i];
        max = coin[0];
        result = 1;
        for (int i = 1; i < n - 1; i++)
        {
            if(max + coin[i] < coin[i + 1])
            {
                max += coin[i];
                result++;
            }
        }
        ans += " " + to_string(max);
    }
    return ans;
}

//dp 去解
