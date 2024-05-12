SELECT query_name, ROUND((SUM(rating/position) / COUNT(query_name)),2) AS quality, 
ROUND(((SELECT COUNT(rating) FROM Queries a WHERE rating < 3 AND q.query_name = a.query_name ) / COUNT(query_name)),4) * 100 AS  poor_query_percentage
FROM Queries q
WHERE query_name IS NOT NULL
GROUP BY query_name