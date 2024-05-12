SELECT r.contest_id, ROUND((COUNT(r.user_id) * 100 / (select count(*) from users)), 2) AS percentage
FROM Users u
JOIN Register r
    ON u.user_id = r.user_id
GROUP BY r.contest_id
ORDER BY percentage DESC, contest_id