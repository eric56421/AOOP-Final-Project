#include "sumoflargehexadecimalintegers.h"

SumOfLargeHexadecimalIntegers::SumOfLargeHexadecimalIntegers()
{

}

string SumOfLargeHexadecimalIntegers::solve(string s)
{
    stringstream ss;
    ss<<s;
    ans.clear();
    ans.push_back(0);
    while(ss>>s){
        if(s.size()>ans.size()){
            for(i=0;i<ans.size();i++){
                if(i!=0){
                    if('0'<=s[s.size()-1-i]&&s[s.size()-1-i]<='9'){
                        ans[i]+=s[s.size()-1-i]-'0';
                    }
                    else if ('a'<=s[s.size()-1-i]&&s[s.size()-1-i]<='f') {
                        ans[i]+=s[s.size()-1-i]-'a'+10;
                    }
                }else{
                    if('0'<=s[s.size()-1-i]&&s[s.size()-1-i]<='9'){
                        ans[i]+=s[s.size()-1-i]-'0';
                    }else if ('a'<=s[s.size()-1-i]&&s[s.size()-1-i]<='f') {
                        ans[i]+=s[s.size()-1-i]-'a'+10;
                    }
                }
            }
            for(i=ans.size();i<s.size();i++){
                if('0'<=s[s.size()-1-i]&&s[s.size()-1-i]<='9')
                    n=s[s.size()-1-i]-'0';
                else if ('a'<=s[s.size()-1-i]&&s[s.size()-1-i]<='f') {
                    n=s[s.size()-1-i]-'a'+10;
                }
                ans.push_back(n);
            }
        }else{
            for(i=0;i<s.size();i++){
                if(i!=0){
                    if('0'<=s[s.size()-1-i]&&s[s.size()-1-i]<='9')
                        ans[i]+=s[s.size()-1-i]-'0';
                    else if ('a'<=s[s.size()-1-i]&&s[s.size()-1-i]<='f') {
                        ans[i]+=s[s.size()-1-i]-'a'+10;
                    }
                }else{
                    if('0'<=s[s.size()-1-i]&&s[s.size()-1-i]<='9')
                        ans[i]+=s[s.size()-1-i]-'0';
                    else if ('a'<=s[s.size()-1-i]&&s[s.size()-1-i]<='f') {
                        ans[i]+=s[s.size()-1-i]-'a'+10;
                    }
                }
            }
        }
        for(int i=1;i<ans.size();i++){
            ans[i]+=ans[i-1]/16;
            ans[i-1]%=16;
        }
        while(ans[ans.size()-1]>=16){
            ans.push_back(ans[ans.size()-1]/16);
            ans[ans.size()-2]%=16;
        }
    }
    s="";
    for(int i=ans.size()-1;i>=0;i--){
        if(0<=ans[i]&&ans[i]<=9)
            s+=to_string(ans[i]);
        else if (10<=ans[i]&&ans[i]<=15) {
            s+=(ans[i]-10+'a');
        }

    }
    return s;
}
