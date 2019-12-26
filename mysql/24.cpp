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

    int a, b, m;
    string lalo, ad;                      // lalo -> lat/lon ad -> asc/des

    getline(cin, s);
    getline(cin, theans);
    cout<<endl<<"Command"<<endl;
    token<<s;
    token>>a>>b>>lalo>>m>>ad;

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
    queryCmd = "select avg(" + lalo + ") from ";

    string tmp = " from (select " + lalo + " from citytable where id%10 = " + to_string(m) + " order by " + lalo;
    if (ad == "asc")
        tmp += " asc ";
    else
        tmp += " desc ";
    tmp += " limit " + to_string(a-1) + ", " + to_string(b-a+1) + ") as t1) ";
    // string tmp1 = " from citytable where id%10 = " + to_string(m) + " order by " + lalo;
    // if (ad == "asc")
    //     tmp1 += " asc ";
    // else
    //     tmp1 += " desc ";
    // tmp += " limit " + to_string(a-1) + ", " + to_string(b-a+1) + ") ";

    queryCmd += "(select row_number() over (order by " + lalo;
    if (ad == "asc")
        queryCmd += " asc ";
    else
        queryCmd += " desc ";
    queryCmd += ") as row_num, " + lalo + tmp + "as t2 join ";
    queryCmd += "(select count(" + lalo + ") as cnt " + tmp + "as t3 ";
    queryCmd += "where row_num = if(cnt%2=0, cnt/2, (cnt+1)/2) or row_num = if(cnt%2=0, cnt/2+1, (cnt+1)/2);";
    cout<<queryCmd<<endl;
    query.exec(queryCmd.c_str());
    query.next();
    if (query.value(0).isNull())
        token<<"NULL";
    else
        token<<fixed<<setprecision(4)<<query.value(0).toDouble();

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
