# 85%

select distinct id, 
(case when(p_id is null) then 'Root'
      when( p_id is not null and id in (select p_id from tree) ) then 'Inner'
      else 'Leaf' end) as Type
from tree;