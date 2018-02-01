Write a SQL query to delete all duplicate email entries in a table named Person, keeping only unique emails based on its smallest Id.

	+----+------------------+
	| Id | Email            |
	+----+------------------+
	| 1  | john@example.com |
	| 2  | bob@example.com  |
	| 3  | john@example.com |
	+----+------------------+
Id is the primary key column for this table.
For example, after running your query, the above Person table should have the following rows:

	+----+------------------+
	| Id | Email            |
	+----+------------------+
	| 1  | john@example.com |
	| 2  | bob@example.com  |
	+----+------------------+

## DELETE clause

Since I need to alter the original table "Person", it tests delete clause.
Get familiar with it!

### NOTICE

For the faster solution:

	delete from Person
	where Id not in 
	(select c.id from (select min(b.id) as id from Person b group by b.Email ) c)

Notice that to avoid the error "You can't specify target table 'Person' for update in FROM clause":
You can't use the table that is to be updated in the subclause of "from".  
so what we selected from should be a temp table, not the original table itself.