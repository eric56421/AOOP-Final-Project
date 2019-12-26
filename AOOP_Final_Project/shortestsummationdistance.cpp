#include "shortestsummationdistance.h"

ShortestSummationDistance::ShortestSummationDistance()
{

}

string ShortestSummationDistance::solve(string s)
{

    in=stringToVectorInt(s);
    vector<double> ans;
    ind=0;

    while (ind < in.size()) {
        n = in.at(ind);
        n *= 2;
        ind++;

        vector<point> data;
        for (int i=0; i<2*n; i+=2) {
            tmp.x = in.at(ind + i);
            tmp.y = in.at(ind + i + 1);
            data.push_back(tmp);
        }
        ind += n * 2;

        dis=new double *[n];
        for(int i=0;i<n;i++){
            dis[i]=new double [n];
            for(int j=0;j<n;j++){
                dis[i][j]=sqrt((data[i].x-data[j].x)*(data[i].x-data[j].x) \
                               + (data[i].y-data[j].y) * (data[i].y-data[j].y));
            }
        }

        dp = new double [(1<<n)+1];

        dp[0] = 0;
        for(int S=1; S<(1<<n); S++){
            dp[S] = INF;
            int i =0, cnt = 0;
            for(int j=0; j<n; j++){
                if(S & (1<<j)) {
                    i = j;
                    cnt ++;
                }
            }
            if(cnt & 1)
                continue;
            for(int j=0; j<i; j++)
                if(S & (1<<j))
                    dp[S] = min(dp[S], dis[i][j] + dp[S^(1<<i)^(1<<j)]);

        }

        ans.push_back(dp[(1<<n)-1]);

        delete [] dp;
        //qDebug()<<"Returning memory";
        for(int i=0;i<n;i++)
            delete [] dis[i];
        delete [] dis;
        //qDebug()<<"Success leaving";
    }

    return vectorDoubleToString(ans);
}

/*
 *  Reference : https://www.twblogs.net/a/5c178960bd9eee5e40bbc93d/zh-cn/
 *
 *  狀壓dp，dp[S]表示狀態S裡面所有點互相配對的最小值，狀態轉移方程：
 *  dp[S] = min{dis[i][j] + dp[S^(1<<i)^ (1<<j)}，i表示狀態S裡面的最大點，j表示狀態S裡面小於i的點。
 *  解釋一下，因為i必須要一個小於它的匹配點，所以dp[S]就該等於取出i，j點的狀態dp[S']加上dis[i][j]，
 *  由此也可知道，當狀態S其中的點為奇數的時候，dp[S]就不存在。
 *
 *  S 的 binary (state compresssion)就是表示選定哪幾個點k
 */
