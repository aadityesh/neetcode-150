# Write your MySQL query statement below
SELECT x,y,z,(IF(x+y > z AND x > 0 AND y+z>x AND x+z>y, "Yes", "No")) as triangle
FROM Triangle
