#ifndef THEEASYCITY1_H
#define THEEASYCITY1_H

#include <mydatabase.h>

class TheEasyCity1 : public MyDatabase
{
public:
    TheEasyCity1();
    virtual string solve(string s);
};

#endif // THEEASYCITY1_H
