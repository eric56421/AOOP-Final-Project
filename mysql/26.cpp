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

    int n, a, b;
    string ar;                      // ar -> alphabetical/reverse

    getline(cin, s);
    getline(cin, theans);
    cout<<endl<<"Command"<<endl;
    token<<s;
    token>>n>>a>>b>>ar;

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
    queryCmd = "select max(sqrt(pow(t2.lat-t3.lat, 2)+pow(t2.lon-t3.lon, 2))), min(sqrt(pow(t2.lat-t3.lat, 2)+pow(t2.lon-t3.lon, 2))) from ";
    string tmp = "(select distinct lat, lon from (select id, city, round(lat, " + to_string(n) + ") as lat, round(lon, " + to_string(n) + ") as lon from citytable) as t1 order by city ";
    if (ar == "al")
        tmp += "asc";
    else
        tmp += "desc";
    tmp += " limit " + to_string(a-1) + ", " + to_string(b-a+1) + ") as ";
    queryCmd += tmp + "t2 join " + tmp + "t3 ";
    queryCmd += "on t2.lat!=t3.lat or t2.lon!=t3.lon;";

    cout<<queryCmd<<endl;
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
    query.exec("LOAD DATA INFILE 'C:/ProgramData/MySQL/MySQL Server 8.0/Uploads/city.csv'\
                    INTO TABLE CITYTABLE  \
                    FIELDS TERMINATED BY ','  \
                    ENCLOSED BY '\"' \
                    LINES TERMINATED BY '\r\n' \
                    IGNORE 1 ROWS;");

    cout << query.lastError().text().toStdString() << endl;
}
