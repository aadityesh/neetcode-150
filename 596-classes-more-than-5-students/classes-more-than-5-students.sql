# Write your MySQL query statement below
SELECT Class
from Courses
group by class
having count(student) >= 5