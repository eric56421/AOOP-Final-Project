#include "findfactorial.h"

FindFactorial::FindFactorial()
{
    for(int i=0;i<1000;i++){
        prime.push_back(1);
    }
    prime[0]=prime[1]=0;
    for(int i=2;i<1000;i++){
        if(prime[i]){
            for(int j=2;j*i<1000;j++){
                prime[i*j]=0;
            }
        }
    }
}

string FindFactorial::solve(string s){
    vector<int> in=stringToVectorInt(s);
    for(int i=0;i<in.size();i++){
        int j=1,c=0;
        while(c<in[i]){
            j++;
            c+=numofprime(j);
            qDebug()<<j<<" "<<c<<endl;
        }
        if(c==in[i])
            in[i]=j;
        else
            in[i]=-1;
    }
    return vectorIntToStringOfFactorial(in);
}

int FindFactorial::numofprime(int n){
    int c=0;
    for(int i=2;i<=n;i++){
        if(prime[i]){
            while(n%i==0){
                c++;
                n/=i;
            }
        }
    }
    return c;
}
