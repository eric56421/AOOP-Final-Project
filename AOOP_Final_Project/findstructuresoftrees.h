#ifndef FINDSTRUCTURESOFTREES_H
#define FINDSTRUCTURESOFTREES_H

#include "mytree.h"

using namespace std;

class FindStructuresOfTrees : public MyTree
{
    int index;
    string divide(string s);
    string pre,in,post;
    char inO[100],preO[100];
    string ans;
    public:
        FindStructuresOfTrees();
        virtual string solve(string s) override;
        int search(char arr[],int x,int n);
        void printPostOrder(char inOrder[],char preOrder[],int n);
        virtual ~FindStructuresOfTrees(){}
};

#endif // FINDSTRUCTURESOFTREES_H
