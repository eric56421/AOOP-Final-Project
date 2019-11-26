#include "shortestsummationdistance.h"

ShortestSummationDistance::ShortestSummationDistance()
{

}

string ShortestSummationDistance::solve(string s){
    vector<int> in=stringToVectorInt(s);
    //vector<double> ans;
    for(int i=0;i<in.size();i++)
        qDebug()<<in[i]<<" ";
    qDebug()<<endl<<endl;
    for(int i=0;i<in.size();i++){
        vector<point> data;
        point tmp;
        for(int j=0;j<in[i]*4;j+=2){
            tmp.x=in[i+j+1];
            tmp.y=in[i+j+2];
            data.push_back(tmp);
        }
        double **dis=new double *[in[i]];
        for(int j=0;i<in[i];i++){
            dis[j]=new double [in[i]];
            for(int k=0;k<in[i];k++)
                dis[j][k]=1e10;
        }
        for(int j=0;j<in[i];j++){
            for(int k=0;j<in[i];k++)
                if(j!=k)
                    dis[j][k]=sqrt(pow(data[j].x-data[k].x,2)+pow(data[j].y-data[k].y,2));
        }




        i+=in[i]*4;
    }
}
