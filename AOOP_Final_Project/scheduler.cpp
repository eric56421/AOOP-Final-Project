#include "scheduler.h"

Scheduler::Scheduler()
{
    index = 0;
}

RunInformation Scheduler::getSchedular()
{
    return runschedular.at(index++);
}

void Scheduler::reset()
{
    index = 0;
}

void Scheduler::solve(vector<People> in)
{
    runschedular.clear();
    qDebug()<<"hi";
    for(int i=0;i<in.size();i++)
        qDebug()<<in.at(i).num<<in.at(i).to;
    RunInformation tmp;
    for(int i=1;i<in.size();i++){
        while(in.at(i).num>0){
            tmp.floor=i;
            tmp.inorout='I';
            if(in.at(i).num>10)
                tmp.num=10;
            else
                tmp.num=in.at(i).num;
            runschedular.push_back(tmp);
            tmp.floor=in.at(i).to;
            tmp.inorout='O';
            runschedular.push_back(tmp);
            in.at(i).num-=tmp.num;
        }
    }
    tmp.num=0;
    tmp.inorout='E';
    tmp.floor=0;
    runschedular.push_back(tmp);
    for(int i=0;i<runschedular.size();i++)
        qDebug()<<runschedular.at(i).floor<<runschedular.at(i).inorout<<runschedular.at(i).num;
    out.open("Schedule.txt");
    if(!out){
        qDebug()<<"open file failed"<<endl;
    }else{
        qDebug()<<"open file successful"<<endl;
    }
    for(int i=0;i<runschedular.size()-1;i++)
        out<<runschedular.at(i).floor<<","<<runschedular.at(i).inorout<<","<<runschedular.at(i).num<<endl;

    out.close();
}
