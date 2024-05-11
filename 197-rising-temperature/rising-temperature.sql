# Write your MySQL query statement below
SELECT b.id
FROM Weather a
JOIN Weather b
WHERE a.temperature < b.temperature AND DATEDIFF(b.recordDate, a.recordDate) = 1