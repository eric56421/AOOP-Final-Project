#include "mydatabase.h"

MyDatabase::MyDatabase()
{
    connectMySQL();
    setupCityDB();
}

void MyDatabase::connectMySQL()
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
        qDebug()<<"Successful connection.";
    } else {
        qDebug()<<"Error: Cannot connect!!!";
    }
}

void MyDatabase::setupCityDB()
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
            qDebug()<<query.lastError().text();
            qDebug()<<"hi";
    //qDebug() << query.lastError().text() << endl;
}

