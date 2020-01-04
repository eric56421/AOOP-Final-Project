DROP DATABASE IF EXISTS FINAL;
CREATE DATABASE FINAL;   
USE FINAL;

DROP TABLE IF EXISTS problemlist;
CREATE TABLE problemlist (
ID varchar(8), Floor int, Question text, Answer text,
PRIMARY KEY (ID)
);

LOAD DATA INFILE 'C:/ProgramData/MySQL/MySQL Server 8.0/Uploads/testdata_1225.csv' 
                    INTO TABLE problemlist  
                    FIELDS TERMINATED BY ','  
                    ENCLOSED BY '"' 
                    LINES TERMINATED BY '\r\n' 
                    IGNORE 1 ROWS;

SELECT * FROM problemlist;