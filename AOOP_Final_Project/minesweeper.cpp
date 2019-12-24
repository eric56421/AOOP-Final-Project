#include "minesweeper.h"

Minesweeper::Minesweeper()
{

}

string Minesweeper::solve(string s)
{
    stringstream ss,ans;
    ss<<s;

    ss>>row>>col;

    vector<string> map;
    while(ss>>tmp){
        map.push_back(tmp);
    }

    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(map[i][j]=='.'){
                c=0;
                for(int k=0;k<8;k++){
                   gox=i+dir[k][0];
                   goy=j+dir[k][1];
                   if(0<=gox&&gox<row&&0<=goy&&goy<col&&map[gox][goy]=='*'){
                       c++;
                   }
                }
                map[i][j]='0'+c;
            }
        }
    }

    for(int i=0;i<map.size();i++){
        ans<<map.at(i)<<" ";
    }
    tmp=ans.str();
    tmp.erase(tmp.size()-1);
    return tmp;
}
