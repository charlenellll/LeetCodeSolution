# Using "=" can return an empty table when no such candidate exists. Why?
# beats 75.50%

select Name
from Candidate
where id = (
    select CandidateId
    from Vote
    group by CandidateId
    order by count(*) desc
    limit 1
)


# this solution won't pass when there is no such candidate, it will return null but the test case would return an empty table

select Name
from Vote a
left join Candidate b
on a.CandidateId = b.id
group by a.CandidateId
order by count(*) desc
limit 1;