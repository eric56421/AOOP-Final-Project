#include "shygame.h"

ShyGame::ShyGame()
{

}

string ShyGame::solve(string s)
{

//    stringstream ss,ans;
//    ss<<s;
//    ss>>n;
//    while(ss>>num){
//        people.resize(n);
//        for(int i=0;i<n;i++)
//            people[i]=i+1;
//        now = (num-1)%n;
//        for(int j=0;j<n-1;j++){
//            people.erase(people.begin()+now);
//            now = (now+num-1)%(n-j-1);
//        }
//        ans<<people[0]<<" ";
//    }
//    s=ans.str();
//    s.erase(s.end()-1);
//    return s;


    string ans;
    ss.clear();
    ss << s;
    ss >> n;
    for (M = 1; M < n + 1; M <<= 1)
        ;
    while (ss >> p)
    {
        for (i = 2 * M - 1; i > 0; i--)
        {
            if (i >= M)
                st[i] = 1;
            else
                st[i] = st[i << 1] + st[i << 1 | 1];
        }
        int m, last, prev = 0, s;
        for (i = 1; i <= n; i++)
        {
            m = (p + prev) % (n - i + 1);
            if (m == 0)
                m = n - i + 1;
            prev = m - 1;
            for (s = 1; s < M;)
            {
                if (st[s << 1] < m)
                {
                    m -= st[s << 1];
                    s = s << 1 | 1;
                }
                else
                    s = s << 1;
            }
            last = s - M + 1;
            while (s)
            {
                st[s]--;
                s >>= 1;
            }
        }
        t.clear();
        t << last;
        t >> ts;
        ans += ts;
        ans += " ";
    }
    ans.erase(ans.end() - 1);
    return ans;

}
