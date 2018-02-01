# Write your MySQL query statement below

# If use this, only beats 33% submissions:
# select a.FirstName, a.LastName, b.City, b.State

# use this beats 99.53% submissions! 
# I don't need to specify each column is from which table since I joined them and it is one table now.
select FirstName, LastName, City, State
from Person a
left join Address b
on a.PersonId = b.PersonId;