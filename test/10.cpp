#include <bits/stdc++.h>

using namespace std;

struct Point
{
    int x;
    int y;
};



const int INF  =  0x3f3f3f3f;

double dp[1<<21];
int main(){
    int n, l = 0;

    while (cin>>n && n) {
        n *= 2;

        double x[100], y[100];
        for(int i=0; i<n; i++)
            cin>>x[i]>>y[i];

        double dis[100][100];
        for(int i=0; i<n; i++) 
            for(int j=0; j<n; j++)
                dis[i][j] = sqrt((x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]));
        
        dp[0] = 0;
        for(int S=1; S<(1<<n); S++){
            dp[S] = INF;
            int i =0, cnt = 0;
            for(int j=0; j<n; j++) 
                if(S & (1<<j)) { 
                    i = j; 
                    cnt ++; 
                }

            if(cnt & 1) 
                continue;

            for(int j=0; j<i; j++) 
                if(S & (1<<j))
                    dp[S] = min(dp[S], dis[i][j] + dp[S^(1<<i)^(1<<j)]);
        }
        double ans = dp[(1<<n)-1];
        cout<<fixed<<setprecision(2)<<ans<<endl;
    }
    
    /*
    ??��??dp�?dp[S]表示??��??S?????��???????��????��??对�?????�???��??
    ??��??转移??��??�?dp[S] = min{dis[i][j] + dp[S^(1<<i)^(1<<j)}�?
    i表示??��??S?????��?????大�?��??j表示??��??S?????��??�?i?????��??
    �????�?�?�????为i�?须�??�?个�??�?�??????��????��?????以dp[S]就该�?�??????�i�?j??��????��??dp[S']???�?dis[i][j]�?
    ??�此�???��?��??�?�???��??S??�中?????�为�???��????��??�?dp[S]就�??�???��??
    */

    // while(~scanf("%d", &n) && n){
    //     n *= 2;
    //     double x[100], y[100];
    //     for(int i=0; i<n; i++) {
    //         char s[100]; scanf("%s %lf%lf", s, &x[i], &y[i]);
    //     }
        
    //     double dis[100][100];
    //     for(int i=0; i<n; i++) 
    //         for(int j=0; j<n; j++)
    //             dis[i][j] = sqrt((x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]));
        
    //     dp[0] = 0;
    //     for(int S=1; S<(1<<n); S++){
    //         dp[S] = INF;
    //         int i =0, cnt = 0;
    //         for(int j=0; j<n; j++) 
    //             if(S & (1<<j)) { 
    //                 i = j; 
    //                 cnt ++; 
    //             }

    //         if(cnt & 1) 
    //             continue;

    //         for(int j=0; j<i; j++) 
    //             if(S & (1<<j))
    //                 dp[S] = min(dp[S], dis[i][j] + dp[S^(1<<i)^(1<<j)]);
    //     }
    //     double ans = dp[(1<<n)-1];
    //     printf("Case %d: %.2f\n", ++l, ans);
    // }


    return 0;
}