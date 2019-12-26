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

    vector<People> ele;
    int nowfloor=1,down=1,up=27,go=1,outnum,innum;

    while(down<=up){
        outnum=innum=0;
        if(in.at(down).num==0)
            down++;
        if(in.at(up).num==0)
            up++;

        for(int i=0;i<ele.size();i++){
            if(ele.at(i).to==nowfloor){
                ele.erase(ele.begin()+i);
                i--;
                outnum++;
            }
        }
        tmp.floor=nowfloor;
        tmp.inorout='O';
        tmp.num=outnum;
        runschedular.push_back(tmp);
        for(int i=ele.size();i<10;i++){
            if(in.at(nowfloor).num!=0&&(in.at(nowfloor).to-nowfloor)/abs(in.at(nowfloor.to)-nowfloor)==go){
                ele.push_back(in.at(nowfloor));
                in.at(nowfloor).num--;
                innum++;
            }
        }
        tmp.floor=nowfloor;
        tmp.inorout='I';
        tmp.num=innum;
        runschedular.push_back(tmp);
        if(nowfloor==up)
            go=-1;
        if(nowfloor==down)
            go=1;
        nowfloor+=go;
    }
    tmp.floor=0;
    tmp.inorout='E';
    tmp.num=0;
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
