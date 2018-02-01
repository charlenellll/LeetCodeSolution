There is a table courses with columns: student and class

Please list out all classes which have more than or equal to 5 students.

For example, the table:

	+---------+------------+
	| student | class      |
	+---------+------------+
	| A       | Math       |
	| B       | English    |
	| C       | Math       |
	| D       | Biology    |
	| E       | Math       |
	| F       | Computer   |
	| G       | Math       |
	| H       | Math       |
	| I       | Math       |
	+---------+------------+
Should output:

	+---------+
	| class   |
	+---------+
	| Math    |
	+---------+
Note:
The students should not be counted duplicate in each course.

# GROUP BY + COUNT + HAVING (+ DISTINCT)

In this case, it seems "distinct" can be used anywhere I want

## Difference between WHERE and HAVING

| WHERE   | HAVING   |
| restrict the data in the table  |  filter the data in the result set selected by previous group by operation or aggregation function   |
| cannot use aggregation function       |   can use aggregation function     |
|  can directly filter the data in the original table |  cannot filter data in the table, it can only filter the intermediate return values |

### WHERE

In summary:

+ we cannot use aggregation function in WHERE
+ If we want to filter the data directly in the table, not in the return value set, we should use WHERE

In detail:

+ WHERE is a restriction statement
+ It is used for restricting **the data in the table**, it works right before the result was returned.
+ Its priority is higher than aggregation function, if we can put an aggregation function in it (actually we can't since it will pop out error).
+ **So we cannot use aggregation function inside WHERE statement! It won't work!**
+ If we want to use aggregation function, we need to use HAVING.

### HAVING

In summary:

+ we can use aggregation function in HAVING
+ It only operates on the return value set
+ we cannot use it on data in the table, in that case, we need to use WHERE

In detail:

+ HAVING is a filter statement
+ It can filter **the return values set**, not the data in the table
+ Its priority is lower than the aggregation functions so aggregation function inside HAVING statement runs before HAVING itself, before the filtering
+ If we want to use aggregation function to filter out the result, we muuuuust use HAVING!