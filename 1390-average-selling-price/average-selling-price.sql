SELECT p.product_id, IFNULL(ROUND((SUM(p.price * u.units) / SUM(u.units)), 2), 0) as average_price
FROM Prices p
left JOIN UnitsSold u
    ON u.purchase_date BETWEEN p.start_date AND p.end_date
    AND u.product_id = p.product_id
GROUP BY p.product_id