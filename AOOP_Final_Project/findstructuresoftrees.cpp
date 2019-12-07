#include "findstructuresoftrees.h"

FindStructuresOfTrees::FindStructuresOfTrees()
{

}

string FindStructuresOfTrees::solve(string s)
{
    stringstream ss;
    ss<<s;
    ss>>pre>>in;

    index = 0;
    int rootpos=in.find_first_of(pre.at(index++));

    post=divide(in.substr(0,rootpos));
    post+=divide(in.substr(rootpos+1));
    post+=in.at(rootpos);

    return post;
}

string FindStructuresOfTrees::divide(string s)
{
    if(s.size()==1){
        index++;
        return s;
    }else if(s.size()>0){
        int rootpos=s.find_first_of(pre.at(index++));
        string tmp;
        if(rootpos>0)
            tmp=divide(s.substr(0,rootpos));
        if(rootpos+1<s.size())
            tmp+=divide(s.substr(rootpos+1));
        tmp+=s.at(rootpos);
        return tmp;
    }
    return "";
}
