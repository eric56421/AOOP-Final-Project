#include "shortestandlongestpair.h"

ShortestAndLongestPair::ShortestAndLongestPair()
{

}

double ShortestAndLongestPair::sqrtOfDis(const Point &p1,const Point &p2)
{
    return (p1.x-p2.x)*(p1.x-p2.x)+ (p1.y-p2.y)*(p1.y-p2.y)+ (p1.z-p2.z)*(p1.z-p2.z);
}

string ShortestAndLongestPair::solve(string s)
{
    stringstream ss;
    ss<<s;
    double tmp1,tmp2,tmp3;
    vector<Point> points;
    while(ss>>tmp1>>tmp2>>tmp3)
        points.push_back({tmp1,tmp2,tmp3});

    double max_dis=DBL_MIN,min_dis=DBL_MAX;
    for(int i=0; i<points.size()-1;++i)
        for(int j=i+1;j<points.size();++j)
        {
            max_dis=max(max_dis,sqrtOfDis(points[i],points[j]));
            min_dis=min(min_dis,sqrtOfDis(points[i],points[j]));
        }

    string ans,tmp;
    tmp=to_string(round(sqrt(min_dis)*100)/100);
    ans += (tmp.substr(0, tmp.find('.') + 3) + ' ');
    tmp=to_string(round(sqrt(max_dis)*100)/100);
    ans+=tmp.substr(0, tmp.find('.') + 3);

    return ans;

//    data = stringToVectorPoint3D(s);
//    vector<double> ans;//ans[0] shortest , ans[1] longest
//    ans.push_back(DBL_MAX);
//    ans.push_back(0);

//    for(int i=0;i<data.size()-1;i++){
//        for(int j=i+1;j<data.size();j++){
//            dx = data[i].x - data[j].x;
//            dy = data[i].y - data[j].y;
//            dz = data[i].z - data[j].z;
//            if(dx<=ans[0]&&dy<=ans[0]&&dz<=ans[0]&&sqrt(dx*dx+dy*dy+dz*dz)<ans[0]){
//                ans[0]=sqrt(dx*dx+dy*dy+dz*dz);
//            }
//            if(dx>ans[1]||dy>ans[1]||dz>ans[1]||sqrt(dx*dx+dy*dy+dz*dz)>ans[1]){
//                ans[1]=sqrt(dx*dx+dy*dy+dz*dz);
//            }
//        }
//    }
//    return vectorDoubleToString(ans);
}
