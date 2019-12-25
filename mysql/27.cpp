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

    int m, n, k;
    string eo;                      // eo -> even/odd

    getline(cin, s);
    getline(cin, theans);
    cout<<endl<<"Command"<<endl;
    token<<s;
    token>>eo>>m>>n>>k;

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

    // 14
    queryCmd = "update citytable set lat=lon, lon=@tmp where (@tmp:=lat) is not null and id%2 = ";
    if (eo == "ev")
        queryCmd += "0;";
    else
        queryCmd += "1;";
    cout<<queryCmd<<endl;
    query.exec(queryCmd.c_str());
    
    // 15
    queryCmd = "update citytable set lat = lon where id%10 = " + to_string(m) + ";";
    cout<<queryCmd<<endl;
    query.exec(queryCmd.c_str());
    
    // 16
    queryCmd = "select distinct t1.x, t1.y, t2.x, t2.y from ";
    string tmp = "(select id, round(lat, " + to_string(n) + ") as x, round(lon, " + to_string(n) + ") as y from citytable) as ";
    queryCmd += tmp + "t1 join " + tmp + "t2 ";
    queryCmd += "on t1.id != t2.id where t1.x = t2.y and t1.y = t2.x and t1.x <= t1.y order by t1.x, t1.y ";
    queryCmd += "limit " + to_string(k-1) + ", 1;";

    cout<<queryCmd<<endl;
    query.exec(queryCmd.c_str());
    query.next();
    if (query.value(0).isNull())
        token<<"NULL";
    else
        token<<fixed<<setprecision(1)<<query.value(0).toDouble();
    if (query.value(1).isNull())
        token<<" NULL";
    else
        token<<fixed<<setprecision(1)<<' '<<query.value(1).toDouble();

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
