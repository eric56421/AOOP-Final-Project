#include "scheduler.h"

Scheduler::Scheduler()
{
    nowFloor.push_back(1);
    nowFloor.push_back(3);
    nowFloor.push_back(4);
    nowFloor.push_back(6);
//    nowFloor.push_back(9);
//    nowFloor.push_back(10);
//    nowFloor.push_back(8);
//    nowFloor.push_back(7);
//    nowFloor.push_back(5);
//    nowFloor.push_back(2);
//    nowFloor.push_back(0);
    index = 0;
}

int Scheduler::getNowFloor()
{
    return nowFloor.at(index++);
}

void Scheduler::reset()
{
    index = 0;
}
