#include "maze.h"

Maze::Maze()
{

}

string Maze::solve(string s)
{
//    stringstream ss,so;
//    stack<point> path;
//    point tem;
//    char **given_maze;
//    int row,col,now_x,now_y,i,j,**visit;
//    bool need_pop;
//    ss<<s;
//    ss>>col>>row;
//    given_maze=new char *[row];
//    visit=new int *[row];
//    for(i=0;i<row;i++){
//        given_maze[i]=new char [col];
//        visit[i]=new int [col];
//    }
//    for(i=0;i<row;i++)
//        for(j=0;j<col;j++){
//            ss>>given_maze[i][j];
//            if(given_maze[i][j]=='S'){
//                now_x=j;
//                now_y=i;
//            }
//            visit[i][j]=0;
//        }
//    visit[now_y][now_x]=1;

//    tem.x=now_x;
//    tem.y=now_y;
//    path.push(tem);

//    while(1){
//        now_x=path.top().x;
//        now_y=path.top().y;
////        cout<<now_x<<" "<<now_y<<endl;
//        if(given_maze[now_y][now_x]=='E')
//            break;
//        else if(given_maze[now_y][now_x]=='S'){
//            visit[now_y][now_x]=1;
//        }
//        else if(given_maze[now_y][now_x]=='0'&&visit[now_y][now_x]==0){
//            visit[now_y][now_x]=1;
//            given_maze[now_y][now_x]='1';
//        }
//        need_pop=true;
//        if(now_y-1>=0&&visit[now_y-1][now_x]==0&&given_maze[now_y-1][now_x]!='2'){
//            tem.x=now_x;
//            tem.y=now_y-1;
//            path.push(tem);
//            need_pop=false;
//        }
//        if(now_x-1>=0&&visit[now_y][now_x-1]==0&&given_maze[now_y][now_x-1]!='2'){
//            tem.x=now_x-1;
//            tem.y=now_y;
//            path.push(tem);
//            need_pop=false;
//        }
//        if(now_y+1<row&&visit[now_y+1][now_x]==0&&given_maze[now_y+1][now_x]!='2'){
//            tem.x=now_x;
//            tem.y=now_y+1;
//            path.push(tem);
//            need_pop=false;
//        }
//        if(now_x+1<col&&visit[now_y][now_x+1]==0&&given_maze[now_y][now_x+1]!='2'){
//            tem.x=now_x+1;
//            tem.y=now_y;
//            path.push(tem);
//            need_pop=false;
//        }
//        if(need_pop){
//            given_maze[now_y][now_x]='0';
//            path.pop();
//        }
//    }
//    for(i=0;i<row;i++)
//        for(j=0;j<col;j++)
//            so<<given_maze[i][j]<<" ";
//    for(i=0;i<row;i++){
//        delete []given_maze[i];
//        delete []visit[i];
//    }
//    delete []visit;
//    delete []given_maze;
//    return so.str().substr(0,so.str().size()-1);
    stringstream ss(s);
    int row, col;
    ss >> row >> col;

    char maze[100][100];

    char tmp;
    pair<int, int> start, end;
    for (int i = 0; i < col; i++)
        for (int j = 0; j < row; j++)
        {
            ss >> tmp;
            maze[i][j] = tmp;
            if (tmp == 'S')
                start = make_pair(i, j);
            else if (tmp == 'E')
            {
                end = make_pair(i, j);
                maze[i][j] = '0';
            }
        }
    char route[100][100];
    memcpy(route,maze,sizeof(maze));

    pair<int, int>
        curr(start);
    stack<pair<int, int>> path;
    path.push(curr);

    while (curr != end)
    {
        if (maze[curr.first][curr.second + 1] == '0')
        {
            maze[curr.first][curr.second + 1] = '1';
            ++curr.second;
            path.push(curr);
        }
        else if (maze[curr.first + 1][curr.second] == '0')
        {
            maze[curr.first + 1][curr.second] = '1';
            ++curr.first;
            path.push(curr);
        }
        else if (maze[curr.first][curr.second - 1] == '0')
        {
            maze[curr.first][curr.second - 1] = '1';
            --curr.second;
            path.push(curr);
        }
        else if (maze[curr.first - 1][curr.second] == '0')
        {
            maze[curr.first - 1][curr.second] = '1';
            --curr.first;
            path.push(curr);
        }
        else
        {
            maze[curr.first][curr.second] = '3';
            path.pop();
            curr = path.top();
        }
    }

    while (!path.empty())
    {
        route[path.top().first][path.top().second] = '1';
        path.pop();
    }
    route[start.first][start.second] = 'S';
    route[end.first][end.second] = 'E';

    string ans;

    for (int i = 0; i < col; i++)
        for (int j = 0; j < row; j++)
        {
            ans += route[i][j];
            ans += ' ';
        }
    ans.erase(ans.end() - 1);

    return ans;
}
