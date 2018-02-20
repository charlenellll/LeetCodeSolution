select  avg(n.Number) median
from Numbers n
where n.Frequency >= abs((select sum(Frequency) from Numbers where Number<=n.Number) -
                         (select sum(Frequency) from Numbers where Number>=n.Number))


set @currTot=0, @prevTot=NULL;

select avg(t.Number) median
from
(select 
 Number, 
 Frequency,
 (@prevTot := @currTot) previous_total,
 (@currTot := @currTot + Frequency) current_total,
 (select sum(Frequency) from Numbers) total
 from Numbers
 order by Number) t
where t.current_total >= floor((t.total+1)/2)
and t.previous_total <= t.total- floor((t.total+1)/2)