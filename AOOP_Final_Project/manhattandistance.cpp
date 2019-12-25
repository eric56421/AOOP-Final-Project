#include "manhattandistance.h"

ManhattanDistance::ManhattanDistance()
{

}

string ManhattanDistance::solve(string s)
{
    setupCityDB();

    string ans, queryCmd;
    stringstream token;

    int ds, t;
    double v1, v2;                    // eo -> even/odd  ad -> asc/desc

    token<<s;
    token>>ds>>t>>v1>>v2;

    token.str("");
    token.clear();

    QSqlQuery query;
    query.exec("USE CITYDATABASE");
    query.exec("SET SQL_SAFE_UPDATES = 0;");

    int offset = ds-1, num = t-ds+1;
    // 7
    queryCmd = "select abs(x2-x1) + abs(y2-y1) from ";
    queryCmd += "(select min(lon) as x1, max(lon) as x2 from (select * from citytable where lat < " + to_string(v1)+ " order by lat desc limit " + to_string(offset) + ", " + to_string(num) + ") as t1) as t3,";
    queryCmd += "(select min(lat) as y1, max(lat) as y2 from (select * from citytable where lon > " + to_string(v2)+ " order by lon asc limit " + to_string(offset) + ", " + to_string(num) + ") as t2) as t4;";
//    cout<<queryCmd<<endl;
    query.exec(queryCmd.c_str());
    query.next();
    if (query.value(0).isNull())
        token<<"NULL";
    else
        token<<fixed<<setprecision(4)<<query.value(0).toDouble();

    ans = token.str();

    return ans;
}
