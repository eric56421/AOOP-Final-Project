SELECT * FROM CITYTABLE order by id asc;
SET SQL_SAFE_UPDATES = 0;

# 7
update citytable set lat=lon, lon=@tmp where (@tmp:=lat) is not null and id%2 = 1;

# 8
update citytable set lat = lon where id%10 = 6;

# 9
select distinct t1.x, t1.y, t2.x, t2.y from 
(select id, round(lat, 1) as x, round(lon, 1) as y from citytable) as t1
join
(select id, round(lat, 1) as x, round(lon, 1) as y from citytable) as t2
on t1.id != t2.id
where t1.x = t2.y and t1.y = t2.x and t1.x <= t1.y
order by t1.x, t1.y
limit 3, 1;
;

select distinct round(lat, 1) as x, round(lon, 1) as y from citytable;
