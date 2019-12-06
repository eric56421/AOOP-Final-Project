#include "minesweeper.h"

Minesweeper::Minesweeper()
{
    dir[0][0]=0;dir[0][1]=-1;
    dir[1][0]=-1;dir[1][1]=-1;
    dir[2][0]=-1;dir[2][1]=0;
    dir[3][0]=-1;dir[3][1]=1;
    dir[4][0]=0;dir[4][1]=1;
    dir[5][0]=1;dir[5][1]=1;
    dir[6][0]=1;dir[6][1]=0;
    dir[7][0]=1;dir[7][1]=-1;
}

string Minesweeper::solve(string s)
{
    stringstream ss,ans;
    ss<<s;

    int row,col;
    ss>>row>>col;

    vector<string> map;
    string tmp;
    while(ss>>tmp){
        map.push_back(tmp);
    }

    int c=0,gox,goy;
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
