# Write your MySQL query statement below
SELECT emp.name
FROM Employee emp
INNER JOIN Employee man
ON emp.id = man.managerID
GROUP BY man.managerID
HAVING COUNT(man.managerID) >= 5
