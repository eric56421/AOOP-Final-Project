#ifndef LARGESROOT_H
#define LARGESROOT_H

#include <float.h>

#include "mytree.h"

using namespace std;

class LargesRoot : public MyTree
{
    vector<double> in;
    int maxnode;
    double maxvalue;
    double node[15];
    double value[15];
    public:
        LargesRoot();
        virtual string solve(string s) override;
};

#endif // LARGESROOT_H
