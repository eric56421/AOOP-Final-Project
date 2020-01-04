#include "themedian.h"

TheMedian::TheMedian()
{

}

string TheMedian::solve(string s)
{
    setupCityDB();

    string ans, queryCmd;
    stringstream token;

    int a, b, m;
    string lalo, ad;                      // lalo -> lat/lon ad -> asc/des

    token<<s;
    token>>a>>b>>lalo>>m>>ad;

    token.str("");
    token.clear();

    QSqlQuery query;
    query.exec("USE CITYDATABASE");
    query.exec("SET SQL_SAFE_UPDATES = 0;");

    // 7
    queryCmd = "select avg(" + lalo + ") from ";

    string tmp = " from (select " + lalo + " from citytable where id%10 = " + to_string(m) + " order by " + lalo;
    if (ad == "asc")
        tmp += " asc ";
    else
        tmp += " desc ";
    tmp += " limit " + to_string(a-1) + ", " + to_string(b-a+1) + ") as t1) ";

    queryCmd += "(select row_number() over (order by " + lalo;
    if (ad == "asc")
        queryCmd += " asc ";
    else
        queryCmd += " desc ";
    queryCmd += ") as row_num, " + lalo + tmp + "as t2 join ";
    queryCmd += "(select count(" + lalo + ") as cnt " + tmp + "as t3 ";
    queryCmd += "where row_num = if(cnt%2=0, cnt/2, (cnt+1)/2) or row_num = if(cnt%2=0, cnt/2+1, (cnt+1)/2);";
    qDebug()<<QString::fromStdString(queryCmd);
    query.exec(queryCmd.c_str());
    query.next();
    if (query.value(0).isNull())
        token<<"NULL";
    else
        token<<fixed<<setprecision(4)<<query.value(0).toDouble();

    ans = token.str();

    return ans;
}

