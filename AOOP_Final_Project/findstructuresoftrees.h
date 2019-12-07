#ifndef FINDSTRUCTURESOFTREES_H
#define FINDSTRUCTURESOFTREES_H

#include "mytree.h"

using namespace std;

class FindStructuresOfTrees : public MyTree
{
    int index;
    string divide(string s);
    string pre,in,post;
    public:
        FindStructuresOfTrees();
        virtual string solve(string s) override;
};

#endif // FINDSTRUCTURESOFTREES_H
