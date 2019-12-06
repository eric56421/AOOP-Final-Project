#include "shortestandlongestpair.h"

ShortestAndLongestPair::ShortestAndLongestPair()
{

}

string ShortestAndLongestPair::solve(string s)
{
    vector<Point3D> data = stringToVectorPoint3D(s);
    vector<double> ans;//ans[0] shortest , ans[1] longest
    ans.push_back(DBL_MAX);
    ans.push_back(0);
    double dx,dy,dz;

    for(int i=0;i<data.size()-1;i++){
        for(int j=i+1;j<data.size();j++){
            dx = data[i].x - data[j].x;
            dy = data[i].y - data[j].y;
            dz = data[i].z - data[j].z;
            if(dx<=ans[0]&&dy<=ans[0]&&dz<=ans[0]&&sqrt(dx*dx+dy*dy+dz*dz)<ans[0]){
                ans[0]=sqrt(dx*dx+dy*dy+dz*dz);
            }
            if(dx>ans[1]||dy>ans[1]||dz>ans[1]||sqrt(dx*dx+dy*dy+dz*dz)>ans[1]){
                ans[1]=sqrt(dx*dx+dy*dy+dz*dz);
            }
        }
    }
    return vectorDoubleToString(ans);
}
