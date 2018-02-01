Given a Weather table, write a SQL query to find all dates' Ids with higher temperature compared to its previous (yesterday's) dates.

	+---------+------------+------------------+
	| Id(INT) | Date(DATE) | Temperature(INT) |
	+---------+------------+------------------+
	|       1 | 2015-01-01 |               10 |
	|       2 | 2015-01-02 |               25 |
	|       3 | 2015-01-03 |               20 |
	|       4 | 2015-01-04 |               30 |
	+---------+------------+------------------+
For example, return the following Ids for the above Weather table:

	+----+
	| Id |
	+----+
	|  2 |
	|  4 |
	+----+

# It testd for DATE manipulation and WHERE

## A trap in this problem; use datediff() or TO_DAYS()

Originally, my code was:

	select w1.Id
	from Weather w1, Weather w2
	where w1.Date = w2.Date + 1 and w1.Temperature > w2.Temperature;

However there are some test cases cannot use w1.Date = w2.Date + 1, when one date is at the end of a month, the other one is the start of the next month.

1. At this time, we can use MySQL built-in function datediff() to solve this problem!
Just change to :

**datediff(w1.Date, w2.Date) = 1**

2. or we can change the date time to a number of days using TO_DAYS(), then our subtraction won't cause error: 

**TO_DAYS(a.Date) = TO_DAYS(b.Date) + 1**

	/*  
	TO_DAYS(wt1.DATE) return the number of days between from year 0 to date DATE  
	TO_DAYS(wt1.DATE)-TO_DAYS(wt2.DATE)=1 check if wt2.DATE is yesterday with respect to wt1.DATE  
	  
	alternatively:  
	where DATE_SUB(a.Date,INTERVAL 1 DAY) = b.Date);  
	*/