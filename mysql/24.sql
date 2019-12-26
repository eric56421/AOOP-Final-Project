SELECT * FROM CITYTABLE order by lat asc, lon asc;
SET SQL_SAFE_UPDATES = 0;

# 7
select avg(lat)
from 
(select row_number() over (order by lat asc ) as row_num, lat from (select lat from citytable where id%10 = 0 order by lat asc limit 2, 3) as t1) as t2
join 
(select count(lat) as cnt from (select lat from citytable where id%10 = 0 order by lat asc limit 2, 3) as t1) as t3
where row_num = if(cnt%2=0, cnt/2, (cnt+1)/2) or row_num = if(cnt%2=0, cnt/2+1, (cnt+1)/2);


select avg(lon)
from 
(select row_number() over (order by lon desc) as row_num, lon from citytable where id%10 = 6 order by lon desc limit 0, 4) as t1
join
(select count(lon) as cnt from citytable where id%10 = 6 order by lon desc limit 0, 4) as t2
where row_num = if(cnt%2=0, cnt/2, (cnt-1)/2) or row_num = if(cnt%2=0, cnt/2+1, (cnt-1)/2);


# test area
select if ( select (@cnt := count(lon)%2) = 1  from (select lon from citytable where id%10 = 6 order by lon desc limit 0, 4) as t1, 
	(select lon from citytable limit 1, 1) as t2,
    (select lat from citytable limit 2, 3) as t3,
) from citytable;

end if;

select * from citytable limit 1, 2;

;
select lon from (select row_number() over (order by lon desc) row_num, lon, (@cnt := count(lon)) as cnt from citytable where id%10 = 6 order by lon desc limit 0, 4) as t1
#limit truncate(2.5, 1), 2;
;

select lon, if(lon<25.001, 1, 0) from citytable;

#select row_num, lon, cnt

;

select lon from citytable where id%10 = 6 order by lon desc limit 0, 4;
#, (@cnt := count(lon)) as cnt 
# row_number() over (order by lon desc) row_num, 

select lon from citytable where id%10 = 6 order by lon desc limit 0, 4;
