# Write your MySQL query statement below

select ifnull(
    (select max(num) from(
    select num
    from number
    group by num
    having count(*) = 1
) p), null) as num;

# other sample code:

SELECT ifnull(max(num), NULL) as 'num' FROM (SELECT num FROM number
            group by num having(count(num)) = 1) as a

select(
  select num
  from number
  group by num
  having count(*) = 1
  order by num desc limit 1
) as num;