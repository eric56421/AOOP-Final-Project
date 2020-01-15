#include "minesweeper.h"

Minesweeper::Minesweeper()
{

}

string Minesweeper::solve(string s)
{
    stringstream ss;
    ss << s;
    int col, row;
    ss >> col >> row;
    vector<mi> mines;
    vector<string> mine(col + 2);
    int count = 0;
    mine[count++] = string(row + 2, '0');
    string tmp;
    mi tmppoint;
    while (ss >> tmp)
    {
        for (int i = 0; i < row; i++)
            if (tmp[i] == '.')
                tmp[i] = '0';
            else{
                tmppoint.x=count;
                tmppoint.y=i+1;
                mines.push_back(tmppoint);
            }
        tmp = '0' + tmp + '0';
        mine[count++] = tmp;
    }
    mine[count] = string(row + 2, '0');

    for(int i=0;i<mines.size();i++){
        if (mine[mines[i].x - 1][mines[i].y - 1] != '*')
            mine[mines[i].x - 1][mines[i].y - 1]++;
        if (mine[mines[i].x - 1][mines[i].y] != '*')
            mine[mines[i].x - 1][mines[i].y]++;
        if (mine[mines[i].x - 1][mines[i].y + 1] != '*')
            mine[mines[i].x - 1][mines[i].y + 1]++;
        if (mine[mines[i].x][mines[i].y - 1] != '*')
            mine[mines[i].x][mines[i].y - 1]++;
        if (mine[mines[i].x][mines[i].y + 1] != '*')
            mine[mines[i].x][mines[i].y + 1]++;
        if (mine[mines[i].x + 1][mines[i].y - 1] != '*')
            mine[mines[i].x + 1][mines[i].y - 1]++;
        if (mine[mines[i].x + 1][mines[i].y] != '*')
            mine[mines[i].x + 1][mines[i].y]++;
        if (mine[mines[i].x + 1][mines[i].y + 1] != '*')
            mine[mines[i].x + 1][mines[i].y + 1]++;
    }
    string ans;
    for (int c = 1; c <= col; c++)
        ans += mine[c].substr(1, row) + ' ';
    ans.erase(ans.end() - 1);
    return ans;
}
