Write a SQL query to rank scores. If there is a tie between two scores, both should have the same ranking. Note that after a tie, the next ranking number should be the next consecutive integer value. In other words, there should be no "holes" between ranks.

+----+-------+
| Id | Score |
+----+-------+
| 1  | 3.50  |
| 2  | 3.65  |
| 3  | 4.00  |
| 4  | 3.85  |
| 5  | 4.00  |
| 6  | 3.65  |
+----+-------+
For example, given the above Scores table, your query should generate the following report (order by highest score):

+-------+------+
| Score | Rank |
+-------+------+
| 4.00  | 1    |
| 4.00  | 1    |
| 3.85  | 2    |
| 3.65  | 3    |
| 3.65  | 3    |
| 3.50  | 4    |
+-------+------+

# Solutions

2 method:  

## 1. for each Score, count the number of DISTINCT Score >= it

This method is reasonable but slow.

## 2. MySQL User-Defined Variables

We use a variable @i starts from 0 to count the rank.  
In order to solve the problem if there's a tie, we use another variable @pre to store the value of the last Score and compare it to the current one. If equals, don't change @i, if not, @i:=@i+1.  
This process can be simplified by @i := @i + (@pre<>(@pre:=Score))

### Note that the bracket @pre<>(@pre:=Score) is important!! Or i will never increment!

why?


