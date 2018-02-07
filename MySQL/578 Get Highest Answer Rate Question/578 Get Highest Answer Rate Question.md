Get the highest answer rate question from a table survey_log with these columns: uid, action, question_id, answer_id, q_num, timestamp.

uid means user id; action has these kind of values: "show", "answer", "skip"; answer_id is not null when action column is "answer", while is null for "show" and "skip"; q_num is the numeral order of the question in current session.

Write a sql query to identify the question which has the highest answer rate.

Example:
Input:

	+------+-----------+--------------+------------+-----------+------------+
	| uid  | action    | question_id  | answer_id  | q_num     | timestamp  |
	+------+-----------+--------------+------------+-----------+------------+
	| 5    | show      | 285          | null       | 1         | 123        |
	| 5    | answer    | 285          | 124124     | 1         | 124        |
	| 5    | show      | 369          | null       | 2         | 125        |
	| 5    | skip      | 369          | null       | 2         | 126        |
	+------+-----------+--------------+------------+-----------+------------+
Output:

	+-------------+
	| survey_log  |
	+-------------+
	|    285      |
	+-------------+
Explanation:
question 285 has answer rate 1/1, while question 369 has 0/1 answer rate, so output 285.
Note: The highest answer rate meaning is: answer number's ratio in show number in the same question.

## weird test case, not well-defined by the definition of answer rate

It is so weird that my first solution won't pass some test case:

	select question_id as survey_log
	from survey_log
	group by question_id
	order by count(action = 'answer')/count(action='show') desc
	limit 1

Because in such test case the question can be answered without 'show'.

However, these ones can pass the test cases:

	select question_id as survey_log
	from survey_log
	group by question_id
	order by sum(case when action = 'answer' then 1 else 0 end)/sum(case when action='show' then 1 else 0 end) desc
	limit 1


	select question_id as survey_log from survey_log group by question_id order by count(answer_id)/count(if(action='show',1,0)) desc limit 0,1


	# I don't think these two are calculation the answer rate.

	select question_id as survey_log
	from survey_log
	group by question_id
	order by count(answer_id)/count(q_num) desc
	limit 1

	select question_id as survey_log from survey_log
	where answer_id is not null
	group by question_id
	order by count(question_id) desc
	limit 1