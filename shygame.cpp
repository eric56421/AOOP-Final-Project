#include "shygame.h"

ShyGame::ShyGame()
{

}

string ShyGame::solve(string s)
{
    vector<int> in = stringToVectorInt(s), out;
    queue<int> peopleNum;

    qDebug()<<"enter"<<endl;
    for (int i=1; i<in.size(); i++) {
        // push n people into queue(peopleNum)
        for (int j=0; j<in.at(0); j++)
            peopleNum.push(j+1);

        int m = in.at(i), count = 0, tmp;
        while (peopleNum.size() > 1) {
            tmp = peopleNum.front();
            peopleNum.pop();
            count++;

            if (count == m)
                count = 0;
            else
                peopleNum.push(tmp);
        }

        out.push_back(peopleNum.front());
        peopleNum.pop();

        while (!peopleNum.empty()) {
            //cout<<"Not clean."<<endl;
            peopleNum.pop();
        }
    }
    for (int i=0; i<out.size(); i++) {
        qDebug()<<out.at(i)<<endl;
    }
    qDebug()<<QString::fromStdString(vectorIntToString(out))<<endl;

    return vectorIntToString(out);
}
