# 77.5%

select question_id as survey_log
from survey_log
group by question_id
order by sum(case when action = 'answer' then 1 else 0 end)/sum(case when action='show' then 1 else 0 end) desc
limit 1

# 53%

select question_id as survey_log
from survey_log
group by question_id
order by count(answer_id)/count(q_num) desc
limit 1