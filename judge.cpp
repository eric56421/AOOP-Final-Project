#include "judge.h"

Judge::Judge()
{
    timer.start();
    srand(time(NULL));
}

string Judge::getData(int question)
{
     in.open(to_string(question+1)+".txt");
     if(!in){
         qDebug()<<"open file failed"<<endl;
     }else{
         qDebug()<<"open file successful"<<endl;
     }

     string tmp;
     vector<string> dataV,ansV;
     while(getline(in,tmp)){
         dataV.push_back(tmp);
         getline(in,tmp);
         ansV.push_back(tmp);
     }

     in.close();

     int n = rand() %dataV.size();
     this->ans = ansV.at(n);
     qDebug()<<QString::fromStdString(dataV.at(n))<<endl;
     qDebug()<<QString::fromStdString(ans)<<endl;
     this->timer.restart();
     return dataV.at(n);
}

bool Judge::submitData(string ans)
{
    this->costtime = this->timer.nsecsElapsed();
    qDebug()<<QString::fromStdString(ans)<<endl;
    qDebug()<<QString::fromStdString(this->ans)<<endl;
    return ans == this->ans;
}
