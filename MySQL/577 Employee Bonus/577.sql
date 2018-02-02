# Write your MySQL query statement below

select name, bonus
from Employee a
left join Bonus b
on a.empId = b.empId
where bonus < 1000 or bonus is null;


# This is also right but slower:

select a.name, b.bonus
from Employee a
left join Bonus b
on a.empId = b.empId
where bonus < 1000 or bonus is null;

# what's the difference? why when I use empId this will pop out error?