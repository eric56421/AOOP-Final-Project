#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <vector>
#include <QtDebug>

#include "people.h"
#include "runinformation.h"

using namespace std;

class Scheduler
{
    public:
        Scheduler();
        RunInformation getSchedular();
        void reset();
        void solve(vector<People>);
    private:
        vector<RunInformation> runschedular;
        int index;
};

#endif // SCHEDULER_H
