SELECT * FROM CITYTABLE order by id asc;
SET SQL_SAFE_UPDATES = 0;

# 7
select abs(x2-x1) + abs(y2-y1) from 
(select min(lon) as x1, max(lon) as x2 from (select * from citytable where lat < 121.7 order by lat desc limit 3, 6) as t1) as t3,
(select min(lat) as y1, max(lat) as y2 from (select * from citytable where lon > 25 order by lon asc limit 3, 6) as t2) as t4;

select max(x1), max(x2) from 
(select min(lon) as x1, max(lon) as x2 from (select * from citytable where lat < 121.700000 order by lat desc limit 3, 6) as t1) as t3 
union (select min(lat) as y1, max(lat) as y2 from (select * from citytable where lon > 25.000000 order by lon asc limit 3, 6) as t2);

select min(lat) as x1, max(lat) as x2 from (select lat from citytable order by lat desc limit 3, 6) as t1 where lat < 121.7;
select min(lon) as y1, max(lon) as y2 from (select lon from citytable order by lon asc limit 3, 6) as t2 where lon > 25;

select * from citytable where lat < 121.7 order by lat desc limit 3, 6;
select * from citytable where lon > 25 order by lon asc limit 3, 6;
select lon from citytable order by lon asc;
