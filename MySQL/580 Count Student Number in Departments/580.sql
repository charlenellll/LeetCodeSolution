# 73%

select dept_name, count(student_id) as student_number
from student
right join department
using(dept_id)
group by dept_id
order by count(student_id) desc, dept_name

# I don't know why but RIGHT JOIN here is faster than LEFT JOIN:
# 55%

select dept_name, count(student_id) as student_number
from department
left join student
using(dept_id)
group by dept_id
order by count(student_id) desc, dept_name