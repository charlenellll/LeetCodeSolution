# Write your MySQL query statement below

select x,y,z, IF(((x+y>z) and (y+z>x) and (x+z>y)) = 1, 'Yes', 'No') as triangle
from triangle;

# this is a little bit faster in this problem

select x,y,z, 
case when (x+y>z) and (y+z>x) and (x+z>y) then 'Yes' else 'No' end as triangle
from triangle;