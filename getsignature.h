#ifndef GETSIGNATURE_H
#define GETSIGNATURE_H

#include "myother.h"

class GetSignature : public MyOther
{
    public:
        struct link{
            int from;
            int to;
        };
        GetSignature();
        virtual string solve(string s) override;
};

bool order(GetSignature::link&,GetSignature::link&);

#endif // GETSIGNATURE_H
