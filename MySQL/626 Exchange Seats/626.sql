# 1. Change the id number
# beats 96% submissions

select (case when id % 2 = 0 then id - 1
        when id % 2 = 1 and id = (select count(*) from seat) then id
        else id + 1 end) as id, student
from seat
order by id;

# 2. Change the student name
# my first try was really slow: it is mainly because I used "IN" in this method
# 13%

select a.id, b.student
from seat a, seat b
where IF(a.id % 2 = 1, IF(a.id + 1 in (select id from seat), b.id = a.id + 1, b.id = a.id), b.id = a.id - 1)
order by a.id;

# an optimized version
# got rid of "IN"
# 58%

select a.id, b.student
from seat a, seat b
where IF(a.id % 2 = 1, IF(a.id <> (select count(*) from seat), b.id = a.id + 1, b.id = a.id), b.id = a.id - 1)
order by a.id;





# Others' note:
# Write your MySQL query statement belowU

1. Change Student ID
SELECT CASE 
            WHEN id % 2 <> 0 AND id <> (SELECT COUNT(*) FROM seat) THEN id + 1
            WHEN id % 2 <> 0 AND id = (SELECT COUNT(*) FROM seat) THEN id
            ELSE id - 1
            END AS id, student
FROM seat 
ORDER BY id

2. Change Student Name
SELECT s1.id, CASE 
                    WHEN s1.id % 2 <> 0 AND s1.id <> (SELECT COUNT(*) FROM seat) THEN (SELECT s2.student FROM seat s2 WHERE s2.id = s1.id + 1)
                    WHEN s1.id % 2 <> 0 AND s1.id = (SELECT COUNT(*) FROM seat) THEN s1.student
                    ELSE (SELECT s2.student FROM seat s2 WHERE s2.id = s1.id - 1)
                    END AS student
FROM seat s1