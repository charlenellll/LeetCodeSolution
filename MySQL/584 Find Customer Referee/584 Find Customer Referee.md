Given a table customer holding customers information and the referee.

+------+------+-----------+
| id   | name | referee_id|
+------+------+-----------+
|    1 | Will |      NULL |
|    2 | Jane |      NULL |
|    3 | Alex |         2 |
|    4 | Bill |      NULL |
|    5 | Zack |         1 |
|    6 | Mark |         2 |
+------+------+-----------+
Write a query to return the list of customers NOT referred by the person with id '2'.

For the sample data above, the result is:

+------+
| name |
+------+
| Will |
| Jane |
| Bill |
| Zack |
+------+

# val != 2 OR IS NULL

My first solution was:

	SELECT name FROM customer WHERE referee_id != 2;

However, this query will only return one result:Zack although there are 4 customers not referred by Jane (including Jane herself).  
All the customers who were referred by nobody at all (NULL value in the referee_id column) don’t show up. But why?

(all the explanations refer to http://blog.csdn.net/weixin_39436195/article/details/76101687)

## Important! MySQL three-value logic

MySQL uses three-valued logic: TRUE, FALSE and UNKNOWN.  
**Anything compared to NULL evaluates to the third value: UNKNOWN. That “anything” includes NULL itself!** That’s why MySQL provides the IS NULL and IS NOT NULL operators to specifically check for NULL.

Thus, one more condition 'referee_id IS NULL' should be added to the WHERE clause.