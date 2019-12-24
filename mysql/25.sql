SELECT * FROM CITYTABLE order by country asc;
SET SQL_SAFE_UPDATES = 0;

# 25-7
SELECT substr(country, 1, 3) as country_name, count(city) as count from CITYTABLE group by country order by count(city) asc limit 1, 1;

# 25-8
delete from citytable where (city regexp '^[^nz]|[aeiou]$' or (lat between 121.5 and 131.5 and lon between 25.3 and 30.3));

# 25-9
update citytable set lat=lon, lon=@tmp where (@tmp:=lat) is not null and Id%10=5;

# 25-10
select format(sqrt(pow(max(lat)-min(lat), 2)+pow(max(lon)-min(lon), 2)), 4) from citytable;


# Test Area
# 7
SELECT country, count(city) from CITYTABLE group by country order by count(city) asc limit 1, 1;
# 9
UPDATE swap_test SET state_id=district_id, district_id=@temp WHERE (@temp:=state_id) IS NOT NULL;
# 10
select sqrt(pow(x1-x2,2)+pow(y1-y2,2)) as dis from (select max(lon) as x1 , min(lon) as x2 , max(lat) as y1 , min(lat) as y2 from citytable) as dis;

# Jacky
#2-8.
delete  from CITYTABLE where (CITY like '%a' or CITY like '%e' or CITY like '%i' or CITY like '%o' or CITY like '%u') or (CITY not like 'N%' and CITY not like 'Z%') or ((LAT between 121.5 and 131.5) and (LON between 25.3 and 30.3));
#2-9.
UPDATE citytable t1, citytable t2  set t1.lat=t1.lon,t2.lon=t2.lat where t1.id%10 = 5 && t2.id%10 = 5;
#2-10 
select sqrt(pow(x1-x2,2)+pow(y1-y2,2)) as dis from (select max(lon) as x1 , min(lon) as x2 , max(lat) as y1 , min(lat) as y2 from citytable) as dis;

