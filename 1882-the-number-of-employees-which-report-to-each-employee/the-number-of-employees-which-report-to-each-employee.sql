# Write your MySQL query statement below
SELECT e1.employee_id as employee_id,
       e1.name as name,
       COUNT(*) AS reports_count, 
       round(sum(e2.age)/count(*)) AS average_age
FROM Employees e1
JOIN Employees e2
    ON e1.employee_id = e2.reports_to
GROUP BY e1.employee_id
ORDER BY e1.employee_id
