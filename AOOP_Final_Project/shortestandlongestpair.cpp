#include "shortestandlongestpair.h"

ShortestAndLongestPair::ShortestAndLongestPair()
{

}

string ShortestAndLongestPair::solve(string s)
{
/*
    stringstream ss,ans;
    ss<<s;
    vector<Point> point;
    while(ss>>x>>y>>z){
        point.push_back({x,y,z});
    }

    max_dis=0,min_dis=DBL_MAX;
    for(int i=0;i<point.size()-1;i++){
        for(int j=i+1;j<point.size();j++){
            max_dis=max(max_dis,pow(point[i].x-point[j].x,2)+pow(point[i].y-point[j].y,2)+pow(point[i].z-point[j].z,2));
            min_dis=min(min_dis,pow(point[i].x-point[j].x,2)+pow(point[i].y-point[j].y,2)+pow(point[i].z-point[j].z,2));
        }
    }
    max_dis=sqrt(max_dis);
    min_dis=sqrt(min_dis);

    ans<<fixed<<setprecision(2)<<min_dis<<" "<<max_dis;
    return ans.str();
*/

    data = stringToVectorPoint3D(s);
    vector<double> ans;//ans[0] shortest , ans[1] longest
    ans.push_back(DBL_MAX);
    ans.push_back(0);

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
