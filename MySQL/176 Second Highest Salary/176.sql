# This is slower but not susceptible to mistakes
# speed beats 58.44%

select MAX(Salary) as SecondHighestSalary
from Employee
where Salary < ( select MAX(Salary) from Employee );


# this is faster
# we have to use "distinct"!
# distinct + order by+ limit 1,1
# speed beats 80.50%

select ifnull(
    (select distinct Salary
     from Employee
     order by Salary desc
     limit 1,1), null
) as SecondHighestSalary;

# A very standard version of this solution

SELECT
    IFNULL(
      (SELECT DISTINCT Salary
       FROM Employee
       ORDER BY Salary DESC
        LIMIT 1 OFFSET 1),
    NULL) AS SecondHighestSalary