SELECT * FROM CITYTABLE order by country asc;
SET SQL_SAFE_UPDATES = 0;

# 7
select count(city) - count(distinct city) from citytable where CITY regexp '^[nz].*[^aeiou]$' and lat > 121.5 and lon < 25.3;
# 8
update citytable set lat=lat*2, lon=lon*5 where id%2=1;
# 9
select format(sum(lat), 3), format(sum(lon), 3), max(length(city))-min(length(city)) from (select * from citytable where id%2=0 order by length(city) desc, city desc limit 0, 5) as t1;

# test area
select min(length(city)) from citytable;

select city from citytable;
select city from citytable
union
;
select city, distinct city from citytable;

select count(city) from citytable where CITY regexp '^[nz].*[^aeiou]$' ;and lat > 121.5 and lon < 25.3;

select * from citytable as t1,citytable as t2;