SELECT * FROM CITYTABLE order by id asc;
SET SQL_SAFE_UPDATES = 0;

# error 7
# 7
update citytable set lat=lon, lon=@tmp where (@tmp:=lat) is not null and id%2 = 0;

# 8
update citytable set lat = lon where id%10 = 2;

# 9
select x1, y1, x2, y2, x1=y2, y1=x2
from (
	select distinct t1.x as x1, t1.y as y1, t2.x x2, t2.y y2 
	from 
		(select id, if(round(lat, 4) =-0, 0, round(lat, 4))  as x, if(round(lon, 4) =-0, 0, round(lon, 4))  as y from citytable) as t1 
	join 
		(select id, if(round(lat, 4) =-0, 0, round(lat, 4))  as x, if(round(lon, 4) =-0, 0, round(lon, 4))  as y from citytable) as t2 
	on t1.id != t2.id  
	where t1.x = t2.y and t1.y = t2.x and t1.x <= t1.y 
    ) as t3
order by x1, y1
limit 15, 5;
;

# error 27
# 7
update citytable set lat=lon, lon=@tmp where (@tmp:=lat) is not null and id%2 = 0;

# 8
update citytable set lat = lon where id%10 = 6;

# 9
select x1, y1, x2, y2, x1=y2, y1=x2
from (
	select distinct t1.x as x1, t1.y as y1, t2.x x2, t2.y y2 
	from 
		(select id, if(round(lat, 4) =-0, 0, round(lat, 4))  as x, if(round(lon, 4) =-0, 0, round(lon, 4))  as y from citytable) as t1 
	join 
		(select id, if(round(lat, 4) =-0, 0, round(lat, 4))  as x, if(round(lon, 4) =-0, 0, round(lon, 4))  as y from citytable) as t2 
	on t1.id != t2.id 
	where t1.x = t2.y and t1.y = t2.x and t1.x <= t1.y 
    ) as t3
order by x1, y1
#limit 192, 5;
;


