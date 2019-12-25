#ifndef SYMMETRICPAIRS_H
#define SYMMETRICPAIRS_H

#include "mydatabase.h"

class SymmetricPairs : public MyDatabase
{
    public:
        SymmetricPairs();
        string solve(string s);
};

#endif // SYMMETRICPAIRS_H
