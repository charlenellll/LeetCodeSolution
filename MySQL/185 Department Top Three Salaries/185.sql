# 65.77%

select b.Name as Department, a.Name as Employee, Salary
from Employee a
left join Department b
on a.DepartmentId = b.Id
where (select count(distinct Salary) from Employee where a.DepartmentId = DepartmentId and Salary >= a.Salary) <= 3 and b.Name is not null
order by Department, Salary desc


######################## Below are wrong ansers #################

# When I tried to find the top three salary (before merging it with the Department table)
# This leads to error:
# Line 7: SyntaxError: near 'where (select count(distinct Salary) from Employee where a.DepartmentId = Depart'

select Name as Employee, Salary
from Employee a
group by DepartmentId
order by Salary desc
where (select count(distinct Salary) from Employee where a.DepartmentId = DepartmentId and Salary >= a.Salary) <= 3

# And this is fine:

select Name as Employee, Salary
from Employee a
where (select count(distinct Salary) from Employee where a.DepartmentId = DepartmentId and Salary >= a.Salary) <= 3
order by Salary desc

# It seems that the problem is from GROUP BY?

########## another wrong approach #################
# Reason

select a.Name as Department, t.Name as Employee, t.Salary
from (select b.Name, b.Salary, b.DepartmentId
    from Employee b, Employee c
    where b.DepartmentId = c.DepartmentId
    having count(c.Salary >= b.Salary) <= 3 ) as t
right join Department a
on a.Id = t.DepartmentId
order by a.Name, Salary desc

# there is no output from the temp table, because no operation can be done inside COUNT() except DISTINCT (It is not an operation in fact)

select b.Name, b.Salary, b.DepartmentId
from Employee b, Employee c
where b.DepartmentId = c.DepartmentId
having count(c.Salary > b.Salary) < 3


####### To resolve this problem: #############
# So actually, what I need to do is to put "c.Salary > b.Salary" in the WHERE condition

select b.Name, b.Salary, b.DepartmentId
from Employee b, Employee c
where b.DepartmentId = c.DepartmentId and c.Salary > b.Salary
having count() < 3 ????

# I need to count up all the Salary that satisfy this condition

(select count(distinct b.Salary)
from Employee b, Employee c
where b.DepartmentId = c.DepartmentId and c.Salary > b.Salary) < 3

# this is how I got it look like my only solution at the top of this file.