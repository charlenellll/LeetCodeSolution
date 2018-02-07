# Union two table (itself) together and count it together
# 75%: this is fast and convenient.

select requester_id as id, count(*) as num
from (select requester_id, accepter_id from request_accepted
      union all
      select accepter_id, requester_id from request_accepted) t
group by requester_id
order by num desc
limit 1;


# this is trivial and slooooow
# 43%

select a.req as id, if(req_cnt is null and acc_cnt is null, null, (ifnull(req_cnt,0) + ifnull(acc_cnt,0))) as num
from
(select requester_id as req, count(*) as req_cnt
from request_accepted
group by requester_id) a
left join
(select accepter_id as acc, count(*) as acc_cnt
from request_accepted
group by accepter_id) b
on a.req = b.acc
order by num desc
limit 1