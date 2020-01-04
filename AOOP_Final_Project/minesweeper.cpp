#include "minesweeper.h"

Minesweeper::Minesweeper()
{

}

string Minesweeper::solve(string s)
{
//    stringstream ss,ans;
//    ss<<s;

//    ss>>row>>col;

//    vector<string> map;
//    while(ss>>tmp){
//        map.push_back(tmp);
//    }

//    for(int i=0;i<row;i++){
//        for(int j=0;j<col;j++){
//            if(map[i][j]=='.'){
//                c=0;
//                for(int k=0;k<8;k++){
//                   gox=i+dir[k][0];
//                   goy=j+dir[k][1];
//                   if(0<=gox&&gox<row&&0<=goy&&goy<col&&map[gox][goy]=='*'){
//                       c++;
//                   }
//                }
//                map[i][j]='0'+c;
//            }
//        }
//    }

//    for(int i=0;i<map.size();i++){
//        ans<<map.at(i)<<" ";
//    }
//    tmp=ans.str();
//    tmp.erase(tmp.size()-1);
//    return tmp;

    stringstream ss;
    ss << s;
    int col, row;
    ss >> col >> row;
    vector<string> mine(col + 2);
    int count = 0;
    mine[0] = string(row + 2, '0');
    string tmp;
    while (ss >> tmp)
    {
        for (int i = 0; i < row; i++)
            if (tmp[i] == '.')
                tmp[i] = '0';
        tmp = '0' + tmp + '0';
        mine[++count] = tmp;
    }
    mine[++count] = string(row + 2, '0');

    for (int c = 1; c <= col; c++)
        for (int r = 1; r <= row; r++)
        {
            if (mine[c][r] == '*')
            {
                if (mine[c - 1][r - 1] != '*')
                    mine[c - 1][r - 1]++;
                if (mine[c - 1][r] != '*')
                    mine[c - 1][r]++;
                if (mine[c - 1][r + 1] != '*')
                    mine[c - 1][r + 1]++;
                if (mine[c][r - 1] != '*')
                    mine[c][r - 1]++;
                if (mine[c][r + 1] != '*')
                    mine[c][r + 1]++;
                if (mine[c + 1][r - 1] != '*')
                    mine[c + 1][r - 1]++;
                if (mine[c + 1][r] != '*')
                    mine[c + 1][r]++;
                if (mine[c + 1][r + 1] != '*')
                    mine[c + 1][r + 1]++;
            }
        }

    string ans;
    for (int c = 1; c <= col; c++)
        ans += mine[c].substr(1, row) + ' ';
    ans.erase(ans.end() - 1);
    return ans;
}
