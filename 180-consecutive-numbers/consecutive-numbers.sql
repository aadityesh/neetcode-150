-- SELECT a.num as ConsecutiveNums
-- FROM Logs a
-- JOIN Logs b
--     ON b.id - a.id = 1
--     on a.num = b.num
-- GROUP BY a.num
-- HAVING COUNT(a.num) >= 2

-- SELECT distinct num as ConsecutiveNums
-- from logs
-- where (id+1, num) in (select * from logs) and (id+2, num) in (select * from logs)

SELECT distinct a.num as ConsecutiveNums
from Logs a, Logs b, Logs c
where (b.id - a.id = 1 AND c.id - b.id = 1)
AND a.num = b.num AND b.num = c.num