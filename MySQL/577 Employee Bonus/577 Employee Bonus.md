Select all employee's name and bonus whose bonus is < 1000.

Table:Employee

	+-------+--------+-----------+--------+
	| empId |  name  | supervisor| salary |
	+-------+--------+-----------+--------+
	|   1   | John   |  3        | 1000   |
	|   2   | Dan    |  3        | 2000   |
	|   3   | Brad   |  null     | 4000   |
	|   4   | Thomas |  3        | 4000   |
	+-------+--------+-----------+--------+
empId is the primary key column for this table.
Table: Bonus

	+-------+-------+
	| empId | bonus |
	+-------+-------+
	| 2     | 500   |
	| 4     | 2000  |
	+-------+-------+
empId is the primary key column for this table.
Example ouput:

	+-------+-------+
	| name  | bonus |
	+-------+-------+
	| John  | null  |
	| Dan   | 500   |
	| Brad  | null  |
	+-------+-------+

## LEFT JOIN
  
**"select" keys when joining table:**  
if the selected column has no duplicate in different tables, we can just use the column. If there are duplicates, we should use a.key1, b.key2 to specify each column do we want. There's no way can we use just the column name when there are duplicate because it will be ambiguous.