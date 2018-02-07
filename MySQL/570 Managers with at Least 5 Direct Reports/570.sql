# INNER JOIN
# beats 100% submission

select a.Name
from Employee a
inner join
(select ManagerId
from Employee
group by ManagerId
having count(*) >= 5) b
on a.Id = b.ManagerId

# WHERE
# beats 83.93% submission

select Name
from Employee a,
(select ManagerId
from Employee
group by ManagerId
having count(*) >= 5) b
where a.Id = b.ManagerId