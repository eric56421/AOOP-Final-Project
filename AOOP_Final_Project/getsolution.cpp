#include "getsolution.h"

GetSolution::GetSolution()
{

}

string GetSolution::solve(string s)
{
    stringstream ss,sans;
    int n,i,j,k;
    double p;
    ss<<s;

    ss>>n;
    double matrix[n][n+1];
    double ans[n];

    for(i=0;i<n;i++)
    {
        for (j=0;j<n;j++)
        {
            ss>>matrix[i][j];
        }
    }
    for(i=0;i<n;i++)
    {
        ss>>matrix[i][n];
    }


    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(abs(matrix[i][i]) < abs(matrix[j][i]))
            {
                for(k=0;k<n+1;k++)
                {
                    /* swapping mat[i][k] and mat[j][k] */
                    matrix[i][k]=matrix[i][k]+matrix[j][k];
                    matrix[j][k]=matrix[i][k]-matrix[j][k];
                    matrix[i][k]=matrix[i][k]-matrix[j][k];
                }
            }
      }
    }

     /* Gaussian elimination */
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            p=matrix[j][i]/matrix[i][i];
            for(k=0;k<n+1;k++)
            {
                matrix[j][k]=matrix[j][k]-p*matrix[i][k];
            }
        }
    }
    /* Backward substitution for discovering values of unknowns */
    for(i=n-1;i>=0;i--)
    {
        ans[i]=matrix[i][n];

        for(j=i+1;j<n;j++)
        {
          if(i!=j)
          {
              ans[i]=ans[i]-matrix[i][j]*ans[j];
          }
        }
        ans[i]=ans[i]/matrix[i][i];
    }

    for(i=0;i<n;i++)
    {
        if(ans[i]<=1e-9 && ans[i]>=-1e-9)
        {
            sans<<"0.00"<<" ";
        }
        else
            sans<<fixed<<setprecision(2)<<ans[i]<<" ";
    }

    return sans.str().substr(0,sans.str().size()-1);
}
