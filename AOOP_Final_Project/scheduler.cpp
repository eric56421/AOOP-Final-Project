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
    // Update whenever changing floor
    int lowest = 27, highest = 1, nowFloor = 1, nowDir = 0;  // 1->toUp, 0->toDown
    // Update whenever entering or leaving floor
    int nowNum = 0;
    vector<floorInfo> floor(28);
    queue<pair<int, int>> upNext, downNext;
    
    RunInformation tmp;
    
    runschedular.clear();

    for (int i=1; i<=27; i++) {
        int offset = in.at(i).to - i;
        floor.at(i).toUp = offset>0 ? in.at(i).num : 0;
        floor.at(i).toDown = offset<0 ? in.at(i).num : 0;
        floor.at(in.at(i).to).fromUp += offset<0 ? in.at(i).num : 0;
        floor.at(in.at(i).to).fromDown += offset>0 ? in.at(i).num : 0;

        lowest = in.at(i).to < lowest ? in.at(i).to : lowest;
        highest = in.at(i).to > highest ? in.at(i).to : highest;
    }


    out.open("Schedule_Tmp.txt");
    if(!out){
        qDebug()<<"open tmp file failed"<<endl;
    }else{
        qDebug()<<"open tmp file successful"<<endl;
    }
    out << lowest << ' ' << highest << endl;
    for (int i=1; i<floor.size(); i++)
        out<<fixed<<setw(2)<<i<<": "<<setw(2)<<floor.at(i).toUp<<", "<<setw(2)<<floor.at(i).toDown<<", "<<setw(2)<<floor.at(i).fromUp<<", "<<setw(2)<<floor.at(i).fromDown<<endl;
    out.close();
    qDebug()<<"output to tmp";


    // downNext.push(make_pair(lowest, 0));
    
    while (downNext.size() || upNext.size()) {
        if (nowDir == 0) {
            nowFloor = downNext.front().first;
            tmp.floor = nowFloor;
            tmp.num = downNext.front().second;
            tmp.inorout = 'O';
            runschedular.push_back(tmp);

            nowNum -= tmp.num;
            floor.at(nowFloor).fromUp -= tmp.num;
            downNext.pop();
        }
        else {
            nowFloor = upNext.front().first;
            tmp.floor = nowFloor;
            tmp.num = upNext.front().second;
            tmp.inorout = 'O';
            runschedular.push_back(tmp);

            nowNum -= tmp.num;
            floor.at(nowFloor).fromDown -= tmp.num;
            upNext.pop();
        }

        if (nowDir == 0 && downNext.size() == 0) {
            nowDir = 1;
            
        }
        if (nowDir == 1 && nowFloor >= highest) {
            nowDir = 0;
            for (int i=27; i>nowFloor; i--)
                if (floor.at(i).toDown) {
                    nowDir = 1;
                    break;
                }
        }
        else if (nowDir == 0 && nowFloor <= lowest){
            nowDir = 1;
            for (int i=1; i<nowFloor; i++)
                if (floor.at(i).toUp) {
                    nowDir = 0;
                    break;
                }
        }

        

    }
    

    while (lowest <= highest) {
        tmp.floor = nowFloor;

        // Entering floor
        tmp.inorout = 'O';
        if (nowNum) {
            // Entering floor at terminal
            if (nowDir == 1 && (nowFloor == highest /*|| floor.at(nowFloor).toUp == 0*/)) {
                if (floor.at(nowFloor).fromDown <= 0)
                    qDebug()<<"error1";
                // check;
                if (nowNum) {
                    tmp.num = upNext.front().first;
                    // tmp.num = min(nowNum, floor.at(nowFloor).fromDown);
                    runschedular.push_back(tmp);

                    nowNum -= tmp.num;
                    floor.at(nowFloor).fromDown -= tmp.num;
                }
                else {
                    qDebug()<<"error1_1";
                }
            }
            else if (nowDir == 0 && (nowFloor == lowest /*|| floor.at(nowFloor).toDown == 0*/)) {
                if (floor.at(nowFloor).fromUp <= 0)
                    qDebug()<<"error2";
                if (nowNum) {
                    tmp.num = min(nowNum, floor.at(nowFloor).fromUp);
                    runschedular.push_back(tmp);

                    nowNum -= tmp.num;
                    floor.at(nowFloor).fromUp -= tmp.num;
                }
                else {
                    qDebug()<<"error2_1";
                }
            }
            /*
            // Enter floor at middle
            else if (nowDir == 1 && floor.at(nowFloor).fromDown && nowNum) {
                tmp.num = min(nowNum, floor.at(nowFloor).fromDown);
                if (tmp.num <= 0)
                    qDebug()<<"error3";
                runschedular.push_back(tmp);

                floor.at(nowFloor).fromDown -= tmp.num;
                nowNum -= tmp.num;
            }
            else if (nowDir == 0 && floor.at(nowFloor).fromUp && nowNum) {
                tmp.num = min(nowNum, floor.at(nowFloor).fromUp);
                if (tmp.num <= 0)
                    qDebug()<<"error4";
                runschedular.push_back(tmp);

                floor.at(nowFloor).fromUp -= tmp.num;
                nowNum -= tmp.num;
            }
            */
        }


        // change dir;
        if (nowDir == 1 && nowFloor >= highest) {
            nowDir = 0;
            for (int i=27; i>nowFloor; i--)
                if (floor.at(i).toDown) {
                    nowDir = 1;
                    break;
                }
        }
        else if (nowDir == 0 && nowFloor <= lowest){
            nowDir = 1;
            for (int i=1; i<nowFloor; i++)
                if (floor.at(i).toUp) {
                    nowDir = 0;
                    break;
                }
        }                

        // Leaving floor
        tmp.inorout = 'I';

        if (nowNum < 10) {
            if (nowDir == 1 && floor.at(nowFloor).toUp > 0) {
                tmp.num = min(10-nowNum, floor.at(nowFloor).toUp);
                runschedular.push_back(tmp);

                nowNum += tmp.num;
                floor.at(nowFloor).toUp -= tmp.num;
            }
            else if (nowDir == 0 && floor.at(nowFloor).toDown > 0) {
                tmp.num = min(10-nowNum, floor.at(nowFloor).toDown);
                runschedular.push_back(tmp);

                nowNum += tmp.num;
                floor.at(nowFloor).toDown -= tmp.num;
            }
        }

        // update highest lowest
        while (floor.at(lowest).fromUp == 0)
            lowest++;
        while (floor.at(highest).fromDown == 0)
            highest--;
        
        

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
