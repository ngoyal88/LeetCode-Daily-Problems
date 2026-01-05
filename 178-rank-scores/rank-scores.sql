# Write your MySQL query statement below
SELECT s1.score , count(distinct s2.score) as 'rank'
FROM Scores s1 , Scores s2
WHERE s2.score >= s1.score
GROUP BY s1.Id
ORDER BY score DESC