Write a SQL query to get the second highest salary from the Employee table.

	+----+--------+
	| Id | Salary |
	+----+--------+
	| 1  | 100    |
	| 2  | 200    |
	| 3  | 300    |
	+----+--------+
For example, given the above Employee table, the query should return 200 as the second highest salary. If there is no second highest salary, then the query should return null.

	+---------------------+
	| SecondHighestSalary |
	+---------------------+
	| 200                 |
	+---------------------+

## Solution 1: the max number except the max one

This solution can only be used for this specific condition. If we are asked for k-th highest when k is a large number, this solution is not useful.

## Solution 2: distinct + order by + limit 1,1 + ifnull(our answer, null)

1. LIMIT

I learned the use of limit clause here.  
"limit m,n":  
+ m means the start index (0-based)
+ n means fetch n records starting from (m+1)-th element (the element with index m)

So the second element's index is 1. We fetch 1 record starts from the second largest element whose index is 1. The clause should be **"limit 1,1" or "limit 1 offset 1"**

2. DISTINCT

We need the distinct here since some test case the Salary columns only have one value so there is no second highest one.

3.

Notice that if we 