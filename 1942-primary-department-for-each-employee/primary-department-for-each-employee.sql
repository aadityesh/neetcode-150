-- # Write your MySQL query statement below
-- SELECT employee_id, department_id
-- FROM Employee
-- WHERE primary_flag="Y"

-- SELECT * 
-- FROM Employee
-- WHERE () (
    -- SELECT COUNT(department_id)
    -- FROM EMPLOYEE
    -- GROUP BY employee_id

SELECT employee_id, department_id
FROM EMPLOYEE
WHERE primary_flag = 'Y'
union
SELECT employee_id, department_id
FROM EMPLOYEE
GROUP BY employee_id
HAVING COUNT(employee_id) = 1
