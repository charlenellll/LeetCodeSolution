# This is slower but not susceptible to mistakes

select MAX(Salary) as SecondHighestSalary
from Employee
where Salary < ( select MAX(Salary) from Employee );


# this is faster
# we have to use "distinct"!
# distinct + order by+ limit 1,1



# A very standard version of this solution

SELECT
    IFNULL(
      (SELECT DISTINCT Salary
       FROM Employee
       ORDER BY Salary DESC
        LIMIT 1 OFFSET 1),
    NULL) AS SecondHighestSalary