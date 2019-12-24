DROP DATABASE IF EXISTS FINAL;
CREATE DATABASE FINAL;   
USE FINAL;

USE FINAL;
DROP TABLE IF EXISTS problemlist;
CREATE TABLE problemlist
                (ID varchar(8), Floor int, Question text, Answer text,
                PRIMARY KEY (ID));