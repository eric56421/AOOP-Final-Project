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
    

    // From : https://www.twblogs.net/a/5c178960bd9eee5e40bbc93d/zh-cn/
    /*
    狀壓dp，dp[S]表示狀態S裡面所有點互相配對的最小值，狀態轉移方程：
    dp[S] = min{dis[i][j] + dp[S^(1<<i)^ (1<<j)}，i表示狀態S裡面的最大點，j表示狀態S裡面小於i的點。
    解釋一下，因為i必須要一個小於它的匹配點，所以dp[S]就該等於取出i，j點的狀態dp[S']加上dis[i][j]，
    由此也可知道，當狀態S其中的點為奇數的時候，dp[S]就不存在。
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