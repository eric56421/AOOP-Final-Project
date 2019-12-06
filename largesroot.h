#ifndef LARGESROOT_H
#define LARGESROOT_H

#include <float.h>

#include "mytree.h"

using namespace std;

class LargesRoot : public MyTree
{
    public:
        LargesRoot();
        virtual string solve(string s) override;
};

#endif // LARGESROOT_H
