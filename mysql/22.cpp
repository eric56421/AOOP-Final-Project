#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>

#include <QSqlQuery>
#include <QSqlResult>
#include <QSqlDatabase>
#include <QSqlError>

using namespace std;

void connectMySQL();
void setupCityDB();

int main()
{
    connectMySQL();
    setupCityDB();

    string s, ans, theans, queryCmd;
    stringstream token;

    int m, n;
    double la, lo, p, q;
    string ch, eo1, eo2, ad;                    // eo -> even/odd  ad -> asc/desc

    getline(cin, s);
    getline(cin, theans);
    cout<<endl<<"Command"<<endl;
    token<<s;
    token>>ch>>la>>lo>>p>>q>>eo1>>m>>eo2>>ad>>n;

    token.str("");
    token.clear();

    QSqlQuery query;
    query.exec("USE CITYDATABASE");
    query.exec("SET SQL_SAFE_UPDATES = 0;");

    // Template
    /*
    queryCmd =
    cout<<queryCmd<<endl;
    query.exec(queryCmd.c_str());
    query.next();
    if (query.value(0).isNull())
        token<<" NULL";
    else
        token<<' '<<query.value(0).toString().toStdString();
    */

    // 7
    queryCmd = "select count(city) - count(distinct city) from citytable where CITY regexp ";
    queryCmd += "'^[" + ch + "].*[^aeiou]$' and lat > " + to_string(la) + " and lon < " + to_string(lo) + ";";
    cout<<queryCmd<<endl;
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
    cout<<queryCmd<<endl;
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
    cout<<queryCmd<<endl;
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
    cout<<endl<<endl;
    cout<<ans<<endl;
    cout<<theans<<endl;
    cout<<"Correct: "<<(ans==theans)<<endl<<endl;

    //return ans;
}

void connectMySQL()
{
    QSqlDatabase database;
    database = QSqlDatabase::addDatabase("QMYSQL");
    database.setHostName("localhost");
    database.setPort(3306);
    database.setUserName("root");

    //database.setPassword("nctuece");
    database.setPassword("123456");

    bool ok = database.open();
    if (ok) {
        cout<<"Successful connectsn.";
    } else {
        cout<<"Error: Cannot connect!!!";
    }
}

void setupCityDB()
{
    QSqlQuery query;
    query.exec("DROP DATABASE IF EXISTS CITYDATABASE;");
    query.exec("CREATE DATABASE CITYDATABASE;");
    query.exec("USE CITYDATABASE;");
    query.exec("DROP TABLE IF EXISTS CITYTABLE;");
    query.exec("CREATE TABLE CITYTABLE (\
                ID INT, COUNTRY VARCHAR(50), CITY VARCHAR(60),\
                LAT DOUBLE, LON DOUBLE, PRIMARY KEY(ID)\
                );");
    query.exec("LOAD DATA INFILE 'C:/ProgramData/MySQL/MySQL Server 8.0/Uploads/city_forFinal4.csv'\
                    INTO TABLE CITYTABLE  \
                    FIELDS TERMINATED BY ','  \
                    ENCLOSED BY '\"' \
                    LINES TERMINATED BY '\r\n' \
                    IGNORE 1 ROWS;");

    cout << query.lastError().text().toStdString() << endl;
}
