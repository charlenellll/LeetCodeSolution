# My first solution
# 81%

CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
    DECLARE M INT;
    SET M = N-1;
  RETURN (
      # Write your MySQL query statement below.
      SELECT IFNULL(
      (SELECT DISTINCT Salary
      FROM Employee
      ORDER BY Salary DESC
      LIMIT M,1), null)
  );
END


# A variation of it, although I don't agree that changing N is a good idea
# 77%

CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
    SET N = N-1;
  RETURN (
      # Write your MySQL query statement below.
      SELECT IFNULL(
      (SELECT DISTINCT Salary
      FROM Employee
      ORDER BY Salary DESC
      LIMIT N,1), null)
  );
END