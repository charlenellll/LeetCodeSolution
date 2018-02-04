# 74%

select sum(distinct a.TIV_2016) as TIV_2016
from insurance a
where 1 = (select count(*) from insurance b where a.LAT = b.LAT and a.LON = b.LON)
and 1 < (select count(*) from insurance b where a.TIV_2015 = B.TIV_2015);

# faster solution: ???

SELECT
    SUM(insurance.TIV_2016) AS TIV_2016
FROM
    insurance
WHERE
    insurance.TIV_2015 IN
    (
      SELECT
        TIV_2015
      FROM
        insurance
      GROUP BY TIV_2015
      HAVING COUNT(*) > 1
    )
    AND CONCAT(LAT, LON) IN
    (
      SELECT
        CONCAT(LAT, LON)
      FROM
        insurance
      GROUP BY LAT , LON
      HAVING COUNT(*) = 1
    )