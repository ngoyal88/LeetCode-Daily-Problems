# Write your MySQL query statement below
SELECT  ROUND(COUNT(DISTINCT customer_id)/(SELECT COUNT(DISTINCT customer_id) FROM Delivery),4)*100 as immediate_percentage
FROM Delivery
WHERE order_date = customer_pref_delivery_date 
AND (customer_id, order_date) IN (
      SELECT customer_id, MIN(order_date)
      FROM Delivery
      GROUP BY customer_id
  )