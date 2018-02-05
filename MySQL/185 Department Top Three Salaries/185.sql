# 38% tooo slow!

select b.Name as Department, a.Name as Employee, Salary
from Employee a
left join Department b
on a.DepartmentId = b.Id
where (select count(distinct Salary) from Employee where a.DepartmentId = DepartmentId and Salary >= a.Salary) <= 3 and b.Name is not null
order by Department, Salary desc


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