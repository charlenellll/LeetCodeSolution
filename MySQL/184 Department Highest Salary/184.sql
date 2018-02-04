# 2 INNER JOIN
# beats 74%

select c.Name as Department, a.Name as Employee, a.Salary
from Employee a
inner join(
    select DepartmentId, max(Salary) as Salary
    from Employee
    group by DepartmentId
) t
using(DepartmentId, Salary)
inner join Department c
on t.DepartmentId = c.Id


# faster solution:

SELECT Department.name as Department, 
        employee.name as Employee, 
        employee.Salary
FROM Employee
    INNER JOIN Department
    ON employee.departmentid = department.id
WHERE (employee.departmentid, salary) IN 
                (SELECT departmentid, MAX(SALARY)
                FROM Employee
                GROUP BY departmentid);