#include "findfactorial.h"
#include <fstream>

using namespace std;

void FindFactorial::set()
{
    if(!factoriallist.empty()){
        return;
    }else{
        ifstream in;
        in.open("push.txt");
        int num=0,n;
        while(in){
            in>>n;
            factoriallist.push_back(n);
        }
        in.close();
    }
}
