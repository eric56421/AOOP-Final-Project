#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <vector>
#include <QtDebug>
#include <fstream>
#include <iomanip>
#include <queue>
#include <stack>
#include <utility>

#include "people.h"
#include "runinformation.h"

using namespace std;

class Scheduler
{
    struct floorInfo
    {
        // Update when leaving floor
        int toUp;
        int toDown;
        // Update when entering floor
        int fromUp;
        int fromDown;

        floorInfo() {fromUp = fromDown = 0;}
    };

    public:
        Scheduler();
        RunInformation getSchedular();
        void reset();
        void solve(vector<People>);
    private:
        vector<RunInformation> runschedular;
        int index;  // nowfloor
        ofstream out;
};

#endif // SCHEDULER_H
