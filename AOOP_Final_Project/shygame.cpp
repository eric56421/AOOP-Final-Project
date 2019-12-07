#include "shygame.h"

ShyGame::ShyGame()
{

}

string ShyGame::solve(string s)
{
    vector<int> in = stringToVectorInt(s),people,out;
    int n = in.at(0);
    for(int i=1;i<in.size();i++){

        for(int j=0;j<n;j++)
            people.push_back(j+1);

        int now=((in.at(i)-1)%n);
        for(int j=0;j<n-1;j++){
            people.erase(people.begin()+now);
            now=((now+in.at(i)-1)%(n-1-j));
        }
        out.push_back(people.at(0));
        people.clear();
    }
    return vectorIntToString(out);
}
