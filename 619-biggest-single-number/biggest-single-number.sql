# Write your MySQL query statement below
select max(num) as num
from (select num
from MyNumbers a
group by num
having count(num) = 1) AS temp

