#include "theeasycity2.h"

TheEasyCity2::TheEasyCity2()
{

}

string TheEasyCity2::solve(string s)
{
    setupCityDB();

    string ans, queryCmd;
    stringstream token;

    int n, m;
    double la, ha, lo, ho;
    string LorS, chs, che;

    qDebug()<<endl<<"Command"<<endl;
    token<<s;
    token>>n>>LorS>>chs>>che>>la>>ha>>lo>>ho>>m;

    token.str("");
    token.clear();

    QSqlQuery query;
    query.exec("USE CITYDATABASE;");
    query.exec("SET SQL_SAFE_UPDATES = 0;");

    // 25-7
    queryCmd = "SELECT substr(country, 1, 3) as country_name, count(city) as count from CITYTABLE group by country order by count(city) ";
    if (LorS == "sma")
        queryCmd += "asc";
    else
        queryCmd += "desc";
    queryCmd += " limit " + to_string(n-1) + ", 1;";

    // qDebug()<<QString::fromStdString(queryCmd)<<endl;
    query.exec(queryCmd.c_str());
    query.next();
    token<<query.value(0).toString().toStdString()<<' '<<query.value(1).toString().toStdString();

    // 25-8
    queryCmd = "delete from citytable where (city regexp '^[^" + chs + "]|[" + che + "]$' or (lat between "\
                + to_string(la) + " and " + to_string(ha) + " and lon between " + to_string(lo) + " and " + to_string(ho) + "));";

    // qDebug()<<QString::fromStdString(queryCmd)<<endl;
    query.exec(queryCmd.c_str());

    // 25-9
    queryCmd = "update citytable set lat=lon, lon=@tmp where (@tmp:=lat) is not null and Id%10=" + to_string(m) + ";";

    // qDebug()<<QString::fromStdString(queryCmd)<<endl;
    query.exec(queryCmd.c_str());

    // 25-10
    queryCmd = "select format(sqrt(pow(max(lat)-min(lat), 2)+pow(max(lon)-min(lon), 2)), 4) from citytable;";

    // qDebug()<<QString::fromStdString(queryCmd)<<endl;
    query.exec(queryCmd.c_str());
    query.next();
    if (query.value(0).isNull())
        token<<" NULL";
    else
        token<<' '<<query.value(0).toString().toStdString();

    //s.clear();
    ans = token.str();
    // qDebug()<<"ans: "<<QString::fromStdString(ans);
//    qDebug()<<endl<<endl;
//    qDebug()<<s<<endl;
//    qDebug()<<ans<<endl;
//    qDebug()<<"Correct: "<<(s==ans)<<endl<<endl;

    return ans;
}
