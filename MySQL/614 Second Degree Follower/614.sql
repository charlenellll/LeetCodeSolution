# 43.79%
select a.follower, count(distinct b.follower) as num
from follow a
left join follow b
on a.follower = b.followee
group by a.follower
having num > 0
order by a.follower


# faster solution:

select a.id as follower,
       count(distinct b.follower) as num from
(SELECT distinct follower as id from follow) a,
follow b
where a.id = b.followee
group by a.id
order by a.id;