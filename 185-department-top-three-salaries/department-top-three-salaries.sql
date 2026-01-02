# Write your MySQL query statement below
SELECT d.name as Department,e.name as Employee, e.salary 
FROM Employee e
JOIN Department d
ON e.departmentId = d.id
WHERE 3 > (
    SELECT COUNT(DISTINCT e1.salary)
    FROM Employee e1
    WHERE e1.salary > e.salary AND e1.departmentId = e.departmentId
)
ORDER BY 1, 3 DESC
