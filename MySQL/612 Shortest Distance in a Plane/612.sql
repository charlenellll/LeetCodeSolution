# 83%

select round(min(sqrt(power(a.x-b.x,2) + power(a.y-b.y,2))), 2) as shortest
from point_2d a, point_2d b
where (a.x <> b.x or a.y <> b.y)

# 78%

select round(min(sqrt(power(a.x-b.x,2) + power(a.y-b.y,2))), 2) as shortest
from point_2d a, point_2d b
where not(a.x = b.x and a.y = b.y)


# this is slooooow! I was trapped by my thoughts of using a variable, however, in this case I don't need the variable at all!
# 30%

set @dist = 10000;
select round(min(short), 2) as shortest from(
select if(@dist > sqrt(power(a.x-b.x,2) + power(a.y-b.y,2)), @dist:=sqrt(power(a.x-b.x,2) + power(a.y-b.y,2)), @dist) as short
from point_2d a, point_2d b
where not(a.x = b.x and a.y = b.y)) p;