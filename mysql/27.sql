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

# test
# 7
update citytable set lat=lon, lon=@tmp where (@tmp:=lat) is not null and id%2 = 1;

# 8
update citytable set lat = lon where id%10 = 6;

# 9
select * from

(select distinct t1.x as ex, t1.y as ey 
from
#(select @row_num:=0) as t3,
(select id, if(round(lat, 0)=-0, 0, round(lat, 0)) as x, if(round(lon, 0)=-0, 0, round(lon, 0)) as y from citytable) as t1
join
(select id, if(round(lat, 0)=-0, 0, round(lat, 0)) as x, if(round(lon, 0)=-0, 0, round(lon, 0)) as y from citytable) as t2
on t1.id != t2.id
where t1.x = t2.y and t1.y = t2.x and t1.x <= t1.y
order by t1.x, t1.y
#limit 1165, 5;
) as e

left join

(SELECT 
	X1, Y1
FROM(
	SELECT *
	#CONVERT(X1,CHAR(40)), CONVERT(Y,CHAR(40)) 
	FROM (
		SELECT id1, CONVERT(x1, DECIMAL(38,0)) AS X1 ,CONVERT(y1, DECIMAL(38,0)) AS Y1, id2, CONVERT(x2, DECIMAL(38,0)) AS X2,CONVERT(y2, DECIMAL(38,0)) AS Y2
		FROM
			(SELECT id AS id1, ROUND(lat,0) AS x1, ROUND(lon,0) AS y1 FROM CityTable WHERE lat<=lon) AS tmp0, 
			(SELECT id AS id2, ROUND(lat,0) AS x2, ROUND(lon,0) AS y2 FROM CityTable ) AS tmp1) AS tmp2
	WHERE (id1<>id2)) AS tmp3 
WHERE X1=Y2 and X2=Y1 GROUP BY X1,Y1 ORDER BY X1, Y1) as d

on e.ex=d.X1 and e.ey=d.Y1
where e.ey != d.Y1 is null;

;

update citytable set lat=lon, lon=@tmp where (@tmp:=lat) is not null and id%2 = 0;
update citytable set lat = lon where id%10 = 2;

SELECT *
FROM(
	SELECT *
	FROM (
		SELECT id1, CONVERT(x1, DECIMAL(38,0)) AS X1 ,CONVERT(y1, DECIMAL(38,0)) AS Y1, id2, CONVERT(x2, DECIMAL(38,0)) AS X2,CONVERT(y2, DECIMAL(38,0)) AS Y2
		FROM
			(SELECT id AS id1, ROUND(lat,0) AS x1, ROUND(lon,0) AS y1 FROM CityTable ) AS tmp0, 
			(SELECT id AS id2, ROUND(lat,0) AS x2, ROUND(lon,0) AS y2 FROM CityTable ) AS tmp1
	) AS tmp2
	WHERE (id1<>id2) and 
	GROUP BY X1,Y1
) AS tmp3 
WHERE X1=Y2 and X2=Y1 ORDER BY X1, Y1;