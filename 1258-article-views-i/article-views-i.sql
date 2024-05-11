# Write your MySQL query statement below
SELECT author_id AS id
FROM Views v
WHERE v.author_id = v.viewer_id
GROUP BY author_id
ORDER BY author_id
