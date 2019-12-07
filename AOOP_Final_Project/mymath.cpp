#include "mymath.h"

MyMath::MyMath()
{

}

vector<int> MyMath::stringToVectorInt(string s)
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

string MyMath::vectorIntToString(vector<int> v)
{
    stringstream ss;
    for(int i=0;i<v.size();i++){
        ss<<v.at(i)<<" ";
    }
    string returndata=ss.str();
    returndata.erase(returndata.size()-1);
    return returndata;
}

vector<double> MyMath::stringToVectorDouble(string s)
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

string MyMath::vectorDoubleToString(vector<double> v)
{
    stringstream ss;
    ss<<fixed<<setprecision(2);
    for(int i=0;i<v.size();i++){
        ss<<v.at(i)<<" ";
    }
    string returndata=ss.str();
    returndata.erase(returndata.size()-1);
    return returndata;
}

vector<MyMath::Point3D> MyMath::stringToVectorPoint3D(string s)
{
    stringstream ss;
    ss<<s;
    Point3D data;
    vector<Point3D> returndata;
    while(ss>>data.x>>data.y>>data.z){
        returndata.push_back(data);
    }
    return returndata;
}
