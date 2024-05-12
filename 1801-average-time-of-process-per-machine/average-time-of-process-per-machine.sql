# Write your MySQL query statement below
-- SELECT a.machine_id, COUNT(DISTINCT a.process_id)
SELECT a.machine_id, round(SUM(b.timestamp - a.timestamp) / COUNT(a.machine_id), 3) as "processing_time"
FROM Activity a
JOIN Activity b
    ON a.activity_type = 'start' AND b.activity_type = 'end'
    AND a.process_id = b.process_id
    AND a.MACHINE_id = b.MACHINE_id
GROUP BY a.machine_id