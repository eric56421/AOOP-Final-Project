SELECT * FROM CITYTABLE order by lat asc, lon asc;
SET SQL_SAFE_UPDATES = 0;

# 7
select max(sqrt(pow(t2.lat-t3.lat, 2)+pow(t2.lon-t3.lon, 2))), min(sqrt(pow(t2.lat-t3.lat, 2)+pow(t2.lon-t3.lon, 2))) from 
(select distinct lat, lon from (select id, city, round(lat, 1) as lat, round(lon, 1) as lon from citytable) as t1 order by city asc limit 2, 3) as t2 
join 
(select distinct lat, lon from (select id, city, round(lat, 1) as lat, round(lon, 1) as lon from citytable) as t1 order by city asc limit 2, 3) as t3
on t2.lat!=t3.lat or t2.lon!=t3.lon;

# c
sqrt(pow(t2.lat-t3.lat, 2)+pow(t2.lon-t3.lon, 2));
t2.lat, t3.lat, t2.lon, t3.lon;
select max(sqrt(pow(t2.lat-t3.lat, 2)+pow(t2.lon-t3.lon, 2))) from 
(select distinct lat, lon from (select id, city, round(lat, 1) as lat, round(lon, 1) as lon from citytable) as t1 order by city asc limit 2, 3) as t2 
join 
(select distinct lat, lon from (select id, city, round(lat, 1) as lat, round(lon, 1) as lon from citytable) as t1 order by city asc limit 2, 3) as t3
on t2.lat!=t3.lat or t2.lon!=t3.lon;

# b
select distinct id, lat, lon from (select id, city, round(lat, 1) as lat, round(lon, 1) as lon from citytable) as t1;

DELETE (select round(lat, 1) as lat, round(lon, 1) as lon from citytable) as t1 FROM t1 t2
INNER JOIN t1 t3
WHERE
	t3.id < t2.id and
    t3.lat = t2.lat AND 
    t3.lon = t2.lon;

# a
(select round(lat, 1) as lat, round(lon, 1) as lon from citytable);

update citytable set lat = round(lat, 1), lon = round(lon, 1);
DELETE t1 FROM citytable t1
INNER JOIN citytable t2 
WHERE
	t1.id < t2.id and
    t1.lat = t2.lat AND 
    t1.lon = t2.lon;
    
select * from citytable as t1 join citytable as t2 on t1.lat!=t2.lat or t1.lon!=t2.lon;