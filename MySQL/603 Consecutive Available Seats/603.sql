# this is faster
# 40 %
select distinct a1.seat_id
from cinema a1, cinema a2
where abs(a1.seat_id - a2.seat_id) = 1 and a1.free = 1 and a2.free = 1
order by seat_id;

# a faster sample code
# beats 61% submissions

select distinct a1.seat_id
from cinema a1
left join cinema a2
on abs(a1.seat_id - a2.seat_id) = 1
where a1.free = 1 and a2.free = 1
order by a1.seat_id;


# This got AC, but reeeeeeally slow
# 13%

select a1.seat_id
from cinema a1
where a1.free = 1 and (
    a1.seat_id + 1 in (select seat_id from cinema where free = 1)
    or
    a1.seat_id - 1 in (select seat_id from cinema where free = 1)
);

# in this code, note that: only when we use "IN" or "NOT IN", the temp table after that does not need an alias.