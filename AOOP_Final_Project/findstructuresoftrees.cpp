#include "findstructuresoftrees.h"

FindStructuresOfTrees::FindStructuresOfTrees()
{

}

string FindStructuresOfTrees::solve(string s)
{
//    stringstream ss;
//    ss<<s;
//    ss>>pre>>in;

//    index = 0;
//    int rootpos=in.find_first_of(pre.at(index++));

//    post=divide(in.substr(0,rootpos));
//    post+=divide(in.substr(rootpos+1));
//    post+=in.at(rootpos);

//    return post;
    stringstream ss;
    string pre,in;
    ss<<s;
    ss>>pre>>in;
    ans="";
    for(int i=0;i<pre.size();i++)
    {
        inO[i]=in[i];
        preO[i]=pre[i];
    }

    printPostOrder(inO,preO,pre.size());

    return ans.substr(0,pre.size());
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

int FindStructuresOfTrees::search(char arr[],int x,int n)
{
    int i;
    for(i=0;i<n;i++)
        if(arr[i]==x)
         return i;
    return -1;
}

void FindStructuresOfTrees::printPostOrder(char inOrder[],char preOrder[],int n)
{
    int rootNode=search(inOrder,preOrder[0],n);
    if(rootNode)
        printPostOrder(inOrder,preOrder+1,rootNode);
    if(rootNode!=n-1)
        printPostOrder(inOrder+rootNode+1,preOrder+rootNode+1,n-rootNode-1);
    ans+=preOrder[0];
}
