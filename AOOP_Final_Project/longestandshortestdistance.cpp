#include "longestandshortestdistance.h"

LongestAndShortestDistance::LongestAndShortestDistance()
{

}

string LongestAndShortestDistance::solve(string s)
{
    setupCityDB();

    string ans, queryCmd;
    stringstream token;

    int n, a, b;
    string ar;                      // ar -> alphabetical/reverse

    token<<s;
    token>>n>>a>>b>>ar;

    token.str("");
    token.clear();

    QSqlQuery query;
    query.exec("USE CITYDATABASE");
    query.exec("SET SQL_SAFE_UPDATES = 0;");

    // 7
    queryCmd = "select max(sqrt(pow(t2.lat-t3.lat, 2)+pow(t2.lon-t3.lon, 2))), min(sqrt(pow(t2.lat-t3.lat, 2)+pow(t2.lon-t3.lon, 2))) from ";
    string tmp = "(select distinct lat, lon from (select id, city, round(lat, " + to_string(n) + ") as lat, round(lon, " + to_string(n) + ") as lon from citytable) as t1 order by city ";
    if (ar == "al")
        tmp += "asc";
    else
        tmp += "desc";
    tmp += " limit " + to_string(a-1) + ", " + to_string(b-a+1) + ") as ";
    queryCmd += tmp + "t2 join " + tmp + "t3 ";
    queryCmd += "on t2.lat!=t3.lat or t2.lon!=t3.lon;";

//    cout<<queryCmd<<endl;
    query.exec(queryCmd.c_str());
    query.next();
    if (query.value(0).isNull())
        token<<"NULL";
    else
        token<<fixed<<setprecision(4)<<query.value(0).toDouble();
    if (query.value(1).isNull())
        token<<" NULL";
    else
        token<<fixed<<setprecision(4)<<' '<<query.value(1).toDouble();

    ans = token.str();

    return ans;
}
