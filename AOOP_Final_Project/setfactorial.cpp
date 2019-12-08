#include "findfactorial.h"
#include <fstream>

using namespace std;

void FindFactorial::set()
{
    ifstream in;
    in.open("numoffact.txt");
    int num=0,n;
    while(in){
        in>>n;
        num+=n;
        factoriallist.push_back(num);
    }
    in.close();
}
