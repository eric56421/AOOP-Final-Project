#include "getsolution.h"
#include <iostream>

GetSolution::GetSolution()
{

}

string GetSolution::solve(string s)
{
    stringstream ss,sans;
    ss<<s;

    ss>>n;
    matrix=new double *[n];
    for(i=0;i<n;i++)
        matrix[i]=new double[n+1];
    ans=new double[n];

    for(i=0;i<n;i++){
        for (j=0;j<n;j++){
            ss>>matrix[i][j];
        }
    }
    for(i=0;i<n;i++){
        ss>>matrix[i][n];
    }

    for(i=0;i<n-1;i++){
        if(matrix[i][i]!=0)
            min=matrix[i][i];
        else
            min=INT_MAX;
        r=i;
        for(j=i+1;j<n;j++){
            if(matrix[j][i]!=0&&matrix[j][i]<min){
                min=matrix[j][i];
                r=j;
            }
        }
        if(r!=i){
            for(k=0;k<n+1;k++){
                /* swapping mat[i][k] and mat[j][k] */
                matrix[i][k]=matrix[i][k]+matrix[r][k];
                matrix[r][k]=matrix[i][k]-matrix[r][k];
                matrix[i][k]=matrix[i][k]-matrix[r][k];
            }
        }

        for(j=i+1;j<n;j++){
            p=matrix[j][i]/matrix[i][i];
            for(k=0;k<n+1;k++){
                matrix[j][k]=matrix[j][k]-p*matrix[i][k];
            }
        }
    }

    for(i=n-1;i>=0;i--){
        ans[i]=matrix[i][n];

        for(j=i+1;j<n;j++){
            ans[i]=ans[i]-matrix[i][j]*ans[j];
        }
        ans[i]=ans[i]/matrix[i][i];
    }

    for(i=0;i<n;i++){
        if(ans[i]<=1e-9 && ans[i]>=-1e-9){
            sans<<"0.00 ";
        }else{
            sans<<fixed<<setprecision(2)<<ans[i]<<" ";
        }
    }

    for(i=0;i<n;i++)
        delete [] matrix[i];
    delete [] matrix;
    delete []ans;
    s=sans.str();
    s.erase(s.end()-1);
    return s;


//    stringstream ss,sans;
//    int n,i,j,k;
//    double p;
//    ss<<s;

//    ss>>n;
//    qDebug()<<n;
//    double **matrix=new double *[n];
//    for(int i=0;i<n;i++)
//        matrix[i]=new double[n+1];
//    double *ans=new double[n];

//    for(i=0;i<n;i++)
//    {
//        for (j=0;j<n;j++)
//        {
//            ss>>matrix[i][j];
//        }
//    }
//    for(i=0;i<n;i++)
//    {
//        ss>>matrix[i][n];
//    }




//    for(i=0;i<n;i++)
//    {
//        for(j=i+1;j<n;j++)
//        {
//            if(abs(matrix[i][i]) < abs(matrix[j][i]))
//            {
//                for(k=0;k<n+1;k++)
//                {
//                    /* swapping mat[i][k] and mat[j][k] */
//                    matrix[i][k]=matrix[i][k]+matrix[j][k];
//                    matrix[j][k]=matrix[i][k]-matrix[j][k];
//                    matrix[i][k]=matrix[i][k]-matrix[j][k];
//                }
//            }
//      }
//    }

//     /* Gaussian elimination */
//    for(i=0;i<n-1;i++)
//    {
//        for(j=i+1;j<n;j++)
//        {
//            p=matrix[j][i]/matrix[i][i];
//            for(k=0;k<n+1;k++)
//            {
//                matrix[j][k]=matrix[j][k]-p*matrix[i][k];
//            }
//        }
//    }
//    /* Backward substitution for discovering values of unknowns */
//    for(i=n-1;i>=0;i--)
//    {
//        ans[i]=matrix[i][n];

//        for(j=i+1;j<n;j++)
//        {
//          if(i!=j)
//          {
//              ans[i]=ans[i]-matrix[i][j]*ans[j];
//          }
//        }
//        ans[i]=ans[i]/matrix[i][i];
//    }

//    for(int i=0;i<n;i++)
//        qDebug()<<matrix[i][n]<<ans[i];

//    for(i=0;i<n;i++)
//    {
//        if(ans[i]<=1e-9 && ans[i]>=-1e-9)
//        {
//            sans<<"0.00"<<" ";
//        }
//        else
//            sans<<fixed<<setprecision(2)<<ans[i]<<" ";
//    }

//    for(int i=0;i<n;i++)
//        delete [] matrix[i];
//    delete [] matrix;
//    delete []ans;

//    return sans.str().substr(0,sans.str().size()-1);
}
