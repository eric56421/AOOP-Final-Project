#include <iostream>
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

    int n, m;
    double la, ha, lo, ho;
    string LorS, chs, che;

    getline(cin, s);
    getline(cin, theans);
    cout<<endl<<"Command"<<endl;
    token<<s;
    token>>n>>LorS>>chs>>che>>la>>ha>>lo>>ho>>m;

    token.str("");
    token.clear();

    QSqlQuery query;
    query.exec("SET SQL_SAFE_UPDATES = 0;");

    // 25-7
    queryCmd = "SELECT substr(country, 1, 3) as country_name, count(city) as count from CITYTABLE group by country order by count(city) ";
    if (LorS == "sma")
        queryCmd += "asc";
    else
        queryCmd += "desc";
    queryCmd += " limit " + to_string(n-1) + ", 1;";

    cout<<queryCmd<<endl;
    query.exec(queryCmd.c_str());
    query.next();
    token<<query.value(0).toString().toStdString()<<' '<<query.value(1).toString().toStdString();

    // 25-8
    queryCmd = "delete from citytable where (city regexp '^[^" + chs + "]|[" + che + "]$' or (lat between "\
                + to_string(la) + " and " + to_string(ha) + " and lon between " + to_string(lo) + " and " + to_string(ho) + "));";

    cout<<queryCmd<<endl;
    query.exec(queryCmd.c_str());

    // 25-9
    queryCmd = "update citytable set lat=lon, lon=@tmp where (@tmp:=lat) is not null and Id%10=" + to_string(m) + ";";

    cout<<queryCmd<<endl;
    query.exec(queryCmd.c_str());

    // 25-10
    queryCmd = "select format(sqrt(pow(max(lat)-min(lat), 2)+pow(max(lon)-min(lon), 2)), 4) from citytable;";

    cout<<queryCmd<<endl;
    query.exec(queryCmd.c_str());
    query.next();
    if (query.value(0).isNull())
        token<<" NULL";
    else
        token<<' '<<query.value(0).toString().toStdString();

    //s.clear();
    ans = token.str();
    cout<<endl<<endl;
    cout<<ans<<endl;
    cout<<theans<<endl;
    cout<<"Correct: "<<(ans==theans)<<endl<<endl;

    return ans;
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
    query.exec("DROP DATABASE IF EXISTS CITYDATABAS;");
    query.exec("CREATE DATABASE CITYDATABAS;");
    query.exec("USE CITYDATABAS;");
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
