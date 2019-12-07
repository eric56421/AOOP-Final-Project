#include "mytree.h"

MyTree::MyTree()
{

}

vector<double> MyTree::stringToVectorDouble(string s)
{
    stringstream ss;
    ss<<s;
    double data;
    vector<double> returndata;
    while(ss>>data){
        returndata.push_back(data);
    }
    return returndata;
}
