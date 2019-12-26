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
/*    runschedular.clear();
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

    out.close();*/
    runschedular.clear();
    for(int i=0;i<in.size();i++)
        qDebug()<<in.at(i).num<<in.at(i).to;

    RunInformation tmp;
    vector<People> ele;
    int nowfloor=1,down=1,up=27,go=1,outnum,innum,empty=0;

    while(down<=up){
        qDebug()<<"now floor : "<<nowfloor<<endl;
        empty=0;
        for(int i=1;i<=27;i++){
            qDebug()<<"floor "<<i<<" remain "<<in[i].num<<endl;
            if(in[i].num==0)
                empty++;
        }
        if(in.at(down).num==0){
            int flag=true;
            for(int i=1;i<=up&&flag;i++){
                if(in.at(i).num!=0&&in.at(i).to==down)
                    flag=false;
            }
            if(flag)
                down++;
        }
        if(in.at(up).num==0){
            int flag=true;
            for(int i=down;i<=27&&flag;i++){
                if(in.at(i).num!=0&&in.at(i).to==up)
                    flag=false;
            }
            if(flag)
                up--;
        }
        outnum=innum=0;
        for(int i=0;i<ele.size();i++){
            if(ele.at(i).to==nowfloor){
                ele.erase(ele.begin()+i);
                i--;
                outnum++;
            }
        }
        if(outnum!=0){
            tmp.floor=nowfloor;
            tmp.inorout='O';
            tmp.num=outnum;
            runschedular.push_back(tmp);
        }
        for(int i=ele.size();i<10;i++){
            if(in.at(nowfloor).num!=0&&(in.at(nowfloor).to-nowfloor)/abs(in.at(nowfloor).to-nowfloor)==go){
                ele.push_back(in.at(nowfloor));
                in.at(nowfloor).num--;
                innum++;
            }
        }
        if(innum!=0){
            tmp.floor=nowfloor;
            tmp.inorout='I';
            tmp.num=innum;
            runschedular.push_back(tmp);
        }
        if(ele.size()==10){
            int flag=true;
            while(flag){
                nowfloor+=go;
                for(int i=0;i<ele.size();i++)
                    if(ele[i].to==nowfloor)
                        flag=false;
            }
        }else{
            nowfloor+=go;
        }
        if(nowfloor==up)
            go=-1;
        if(nowfloor==down)
            go=1;
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
