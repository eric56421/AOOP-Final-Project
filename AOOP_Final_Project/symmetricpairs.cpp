#include "symmetricpairs.h"

SymmetricPairs::SymmetricPairs()
{

}

string SymmetricPairs::solve(string s)
{
    setupCityDB();

    string ans, queryCmd;
    stringstream token;

    int m, n, k;
    string eo;                      // eo -> even/odd

    token<<s;
    token>>eo>>m>>n>>k;

    token.str("");
    token.clear();

    QSqlQuery query;
    query.exec("USE CITYDATABASE");
    query.exec("SET SQL_SAFE_UPDATES = 0;");

    // 14
    queryCmd = "update citytable set lat=lon, lon=@tmp where (@tmp:=lat) is not null and id%2 = ";
    if (eo == "ev")
        queryCmd += "0;";
    else
        queryCmd += "1;";
//    cout<<queryCmd<<endl;
    query.exec(queryCmd.c_str());

    // 15
    queryCmd = "update citytable set lat = lon where id%10 = " + to_string(m) + ";";
//    cout<<queryCmd<<endl;
    query.exec(queryCmd.c_str());

    // 16
    queryCmd = "select x1, y1 from ( ";
    queryCmd += "select distinct t1.x x1, t1.y y1, t2.x x2, t2.y y2 from ";
    string ifLatRound = "if(round(lat, " + to_string(n) + ") =-0, 0, round(lat, " + to_string(n) + ")) ";
    string ifLonRound = "if(round(lon, " + to_string(n) + ") =-0, 0, round(lon, " + to_string(n) + ")) ";
    string tmp = "(select id, " + ifLatRound + " as x, " + ifLonRound + " as y from citytable) as ";
    queryCmd += tmp + "t1 join " + tmp + "t2 ";
    queryCmd += "on t1.id != t2.id where t1.x = t2.y and t1.y = t2.x and t1.x <= t1.y ) as t3 ";
    queryCmd += "order by x1, y1 ";
    queryCmd += "limit " + to_string(k-1) + ", 1;";

//    cout<<queryCmd<<endl;
    query.exec(queryCmd.c_str());
    query.next();
    if (query.value(0).isNull())
        token<<"NULL";
    else
        token<<fixed<<setprecision(n)<<query.value(0).toDouble();
    if (query.value(1).isNull())
        token<<" NULL";
    else
        token<<fixed<<setprecision(n)<<' '<<query.value(1).toDouble();

    ans = token.str();

    return ans;
}
