# Write your MySQL query statement below

select distinct a.Num as ConsecutiveNums
from Logs a, Logs b, Logs c
where a.Num = b.Num and a.Num = c.Num and a.Id+1 = b.Id and a.Id+2 = c.Id;