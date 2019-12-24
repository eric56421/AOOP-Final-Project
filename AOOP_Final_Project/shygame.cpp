#include "shygame.h"

ShyGame::ShyGame()
{

}

string ShyGame::solve(string s)
{
    stringstream ss,ans;
    ss<<s;
    ss>>n;
    while(ss>>num){
        people.resize(n);
        for(int i=0;i<n;i++)
            people[i]=i+1;
        now = (num-1)%n;
        for(int j=0;j<n-1;j++){
            people.erase(people.begin()+now);
            now = (now+num-1)%(n-j-1);
        }
        ans<<people[0]<<" ";
    }
    s=ans.str();
    s.erase(s.end()-1);
    return s;
}
