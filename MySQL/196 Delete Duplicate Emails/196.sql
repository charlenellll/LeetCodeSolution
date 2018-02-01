# speed beats 82.20%
# Write your MySQL query statement below

delete p1
from Person p1, Person p2
where p1.Id > p2.Id and p1.Email = p2.Email;

# a faster solution is:

delete from Person
where Id not in 
(select c.id from (select min(b.id) as id from Person b group by b.Email ) c)

# Notice that to avoid the error "You can't specify target table 'Person' for update in FROM clause"
# You can't use the table that is to be updated in the subclause of "from"
# so what we selected from should be a temp table, not the original table itself