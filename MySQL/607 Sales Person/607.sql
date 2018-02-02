# Write your MySQL query statement below

# this is of normal speed: 56%

select distinct name
from salesperson
where sales_id not in (
    select sales_id
    from orders a
    left join company b
    on a.com_id = b.com_id
    where name = 'RED'
);

# In fact, if I remove "distinct", it still got AC
# I got it now, there won't be duplicate because the names have no duplicate in the table "salesperson"
# (But in my logic I think I should use distinct to avoid duplicate?)
# if I remove "distinct", the speed goes up to 65%

select name
from salesperson
where sales_id not in (
    select sales_id
    from orders a
    left join company b
    on a.com_id = b.com_id
    where name = 'RED'
);


# this is waaaaay tooo slow!

select name
from salesperson
where name not in(
    select distinct name
    from salesperson a
    left join orders b
    on a.sales_id = b.sales_id
    where com_id = (select com_id
                     from company
                     where name = 'RED')
);