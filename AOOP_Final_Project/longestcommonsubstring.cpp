#include "longestcommonsubstring.h"

LongestCommonSubstring::LongestCommonSubstring()
{

}

string LongestCommonSubstring::lcs(string X, string Y)
{
    int m=X.length();
    int n=Y.length(),i,j;
    int maxlen = 0,count=0,index=1000000;			// stores the max length of LCS
    int endingIndex[100]= {m};	// stores the ending index of LCS in X
    int detectmaxlen[100]={0};
    // lookup[i][j] stores the length of LCS of substring
    // X[0..i-1], Y[0..j-1]
    int lookup[m + 1][n + 1];
    char c='Z';

    // initialize all cells of lookup table to 0
    memset(lookup, 0, sizeof(lookup));

    // fill the lookup table in bottom-up manner
    for (i = 1; i <= m; i++)
    {
        for (j = 1; j <= n; j++)
        {
            // if current character of X and Y matches
            if (X[i - 1] == Y[j - 1])
            {
                lookup[i][j] = lookup[i - 1][j - 1] + 1;

                // update the maximum length and ending index
                if (lookup[i][j] >= maxlen)
                {
                    maxlen = lookup[i][j];
                    endingIndex[count]=index=i;
                    detectmaxlen[count]=maxlen;
                    count++;
                }
            }
        }
    }
  //  cout<<"index:"<<index<<endl;
    /*for(i=count-1;i>=0;i--)
    {
        if(detectmaxlen[i]==maxlen && index>endingIndex[i] )
        {
            index=endingIndex[i];
        }
    }
    // return Longest common substring having length maxlen
    return X.substr(index - maxlen, maxlen);*/
    for(i=count-1;i>=0;i--)
        {
       //     cout<<"END:"<<endingIndex[i]<<"Len:"<<detectmaxlen[i]<<endl;
            if(detectmaxlen[i]==maxlen && X[endingIndex[i]-maxlen]<c )
            {
      //          cout<<"END:"<<endingIndex[i]<<endl;
                c=X[index-maxlen];
                index=endingIndex[i];
            }
        }

        return X.substr(index - maxlen, maxlen);

}

string LongestCommonSubstring::solve(string s)
{
    stringstream ss;
     int i,pos=0,prev=0;
     string s1,s2,s3,s4,sans;
     ss<<s;
     ss>>s1;
     ss>>s2;

     while((pos=s1.find_first_of(".,!?",pos))!=string::npos)
     {
         s3+=s1.substr(prev,pos-prev);
         prev=++pos;
     }
     s3+=s1.substr(prev);
     pos=0;
     prev=0;
     while((pos=s2.find_first_of(".,!?",pos))!=string::npos)
     {
         s4+=s2.substr(prev,pos-prev);
         prev=++pos;
     }
     s4+=s2.substr(prev);
     for(i=0;i<s3.size();i++)
     {
         s3[i]=toupper(s3[i]);
     }
     for(i=0;i<s4.size();i++)
     {
         s4[i]=toupper(s4[i]);
     }

     sans=lcs(s3,s4);

     return sans;
}
