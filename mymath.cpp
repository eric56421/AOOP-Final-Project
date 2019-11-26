#include "mymath.h"

MyMath::MyMath()
{

}

vector<int> MyMath::stringToVectorInt(string s){
    stringstream in;
    int n;
    vector<int> tmp;
    in<<s;
    while(in>>n){
        tmp.push_back(n);
    }
    return tmp;
}

string MyMath::vectorIntToString(vector<int> in){
    stringstream out;
    for(int i=0;i<in.size();i++){
        out<<in[i];
        if(i!=in.size()-1)
            out<<" ";
    }
    return out.str();
}

vector<double> MyMath::stringToVectorDouble(string s){
    stringstream in;
    double n;
    vector<double> tmp;
    in<<s;
    while(in>>n){
        tmp.push_back(n);
    }
    return tmp;
}

string MyMath::vectorDoubleToString(vector<double> in){
    stringstream out;
    for(int i=0;i<in.size();i++){
        out<<fixed<<setprecision(2)<<in[i];
        if(i!=in.size()-1)
            out<<" ";
    }
    return out.str();
}

string MyMath::vectorIntToStringOfFactorial(vector<int> in){
    stringstream out;
    for(int i=0;i<in.size();i++){
        if(in[i]!=-1){
            out<<in[i]<<"!";
        }
        else {
            out<<"N";
        }
        if(i!=in.size()-1)
            out<<" ";
    }
    return out.str();
}
