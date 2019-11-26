#include "add1.h"

Add1::Add1()
{

}

string Add1::solve(string s){
    vector<int> in=stringToVectorInt(s);
    transform(in.begin(),in.end(),in.begin(),[](int n){return n+1;});
    s=vectorIntToString(in);
    return s;
}
