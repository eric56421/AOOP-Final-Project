#include "add1.h"

Add1::Add1()
{

}

string Add1::solve(string s)
{
    in=stringToVectorInt(s);
    for(int i=in.size()-1;i>=0;i--)
        in.at(i)++;
    return vectorIntToString(in);
}
