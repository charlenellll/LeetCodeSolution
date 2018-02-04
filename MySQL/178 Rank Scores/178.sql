# 1. MySQL User-Defined Variable
# 88%

set @i = 0, @pre = -1;
select Score, (@i := @i + (@pre<>(@pre:=Score))) as Rank
from Scores
order by Score desc

# It is the same as:
# 88%
select Score, (@i := @i + (@pre<>(@pre:=Score))) as Rank
from Scores, (select @i:= 0, @pre:= -1) init
order by Score desc;

# 2. for each Score, count the number of DISTINCT Score >= it
# 42%

select Score, (select count(distinct Score) from Scores where Score >= a.Score ) as Rank
from Scores a
order by Score desc;


# Sample fast code:

SELECT
  Score,
 @rank:=@rank+(@prev<>(@prev:=Score)) as Rank
FROM
  Scores,
  (SELECT @rank := 0, @prev := -1) init
ORDER BY Score desc
;

SELECT s.Score, @r := @r + (@prev <> (@prev := Score)) AS Rank
FROM scores s, (SELECT @r := 0, @prev := -1) r
ORDER BY s.score DESC