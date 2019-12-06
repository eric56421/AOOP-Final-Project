#include "myother.h"

MyOther::MyOther()
{

}

vector<int> MyOther::stringToVectorInt(string s)
{
    stringstream ss;
    ss<<s;
    int data;
    vector<int> returndata;
    while(ss>>data){
        returndata.push_back(data);
    }
    return returndata;
}
