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
    ??¶å??dpï¼?dp[S]è¡¨ç¤º??¶æ??S?????¢æ???????¹ä????¸é??å¯¹ç?????å°???¼ï??
    ??¶æ??è½¬ç§»??¹ç??ï¼?dp[S] = min{dis[i][j] + dp[S^(1<<i)^(1<<j)}ï¼?
    iè¡¨ç¤º??¶æ??S?????¢ç?????å¤§ç?¹ï??jè¡¨ç¤º??¶æ??S?????¢å??äº?i?????¹ã??
    è§????ä¸?ä¸?ï¼????ä¸ºiå¿?é¡»è??ä¸?ä¸ªå??äº?å®??????¹é????¹ï?????ä»¥dp[S]å°±è¯¥ç­?äº??????ºiï¼?j??¹ç????¶æ??dp[S']???ä¸?dis[i][j]ï¼?
    ??±æ­¤ä¹???¯ç?¥é??ï¼?å½???¶æ??S??¶ä¸­?????¹ä¸ºå¥???°ç????¶å??ï¼?dp[S]å°±ä??å­???¨ã??
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