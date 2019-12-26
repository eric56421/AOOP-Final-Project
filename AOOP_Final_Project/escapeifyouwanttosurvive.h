#ifndef ESCAPEIFYOUWANTTOSURVIVE_H
#define ESCAPEIFYOUWANTTOSURVIVE_H

#include <queue>

#include "myother.h"

using namespace std;

class EscapeIfYouWantToSurvive : public MyOther
{
    public:
        EscapeIfYouWantToSurvive();
        virtual string solve(string s) override;
};

#endif // ESCAPEIFYOUWANTTOSURVIVE_H
