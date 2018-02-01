# Write your MySQL query statement below
# 1. use IF()

update salary
set sex = IF(sex='f','m','f');

# 2.use CASE..WHEN..THEN..ELSE..END
# this is slower

update salary
set sex = (case when sex='m' then 'f' else 'm' end);