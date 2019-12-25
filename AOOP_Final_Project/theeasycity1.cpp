#include "theeasycity1.h"

TheEasyCity1::TheEasyCity1()
{

}

string TheEasyCity1::solve(string s)
{
    setupCityDB();

    string ans, queryCmd;
    stringstream token;

    int m, n;
    double la, lo, p, q;
    string ch, eo1, eo2, ad;                    // eo -> even/odd  ad -> asc/desc

    token<<s;
    token>>ch>>la>>lo>>p>>q>>eo1>>m>>eo2>>ad>>n;

    token.str("");
    token.clear();

    QSqlQuery query;
    query.exec("USE CITYDATABASE");
    query.exec("SET SQL_SAFE_UPDATES = 0;");


    // 7
    queryCmd = "select count(city) - count(distinct city) from citytable where CITY regexp ";
    queryCmd += "'^[" + ch + "].*[^aeiou]$' and lat > " + to_string(la) + " and lon < " + to_string(lo) + ";";
//    cout<<queryCmd<<endl;
    query.exec(queryCmd.c_str());
    query.next();
    if (query.value(0).isNull())
        token<<" NULL";
    else
        token<<query.value(0).toString().toStdString();

    // 8
    queryCmd = "update citytable set lat=lat*" + to_string(p) + ", lon=lon*" + to_string(q);
    if (eo1 == "ev")
        queryCmd += " where id%2=0;";
    else
        queryCmd += " where id%2=1;";
//    cout<<queryCmd<<endl;
    query.exec(queryCmd.c_str());

    // 9
    queryCmd = "select format(sum(lat), " + to_string(n) + "), format(sum(lon), " + to_string(n) + "), max(length(city))-min(length(city)) ";
    queryCmd = "select sum(lat), sum(lon), max(length(city))-min(length(city)) ";
    queryCmd += "from (select * from citytable";
    if (eo2 == "even")
        queryCmd += " where id%2=0 order by length(city) ";
    else
        queryCmd += " where id%2=1 order by length(city) ";
    if (ad == "des")
        queryCmd += "desc, ";
    else
        queryCmd += "asc, ";
    queryCmd += "city desc limit 0, " + to_string(m) + ") as t1;";
//    cout<<queryCmd<<endl;
    query.exec(queryCmd.c_str());
    query.next();
    if (query.value(0).isNull())
        token<<" NULL";
    else
        token<<fixed<<setprecision(n)<<' '<<query.value(0).toDouble();
    if (query.value(1).isNull())
        token<<" NULL";
    else
        token<<fixed<<setprecision(n)<<' '<<query.value(1).toDouble();
    if (query.value(2).isNull())
        token<<" NULL";
    else
        token<<' '<<query.value(2).toString().toStdString();

    ans = token.str();
//    cout<<endl<<endl;
//    cout<<ans<<endl;
//    cout<<theans<<endl;
//    cout<<"Correct: "<<(ans==theans)<<endl<<endl;

    return ans;
}
