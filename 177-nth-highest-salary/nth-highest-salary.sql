CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  RETURN (
      SELECT IF(COUNT(*) < N OR N<1, NULL, MIN(salary))
      FROM (
        SELECT DISTINCT salary
        FROM Employee
        ORDER BY salary DESC
        LIMIT N
      ) t
  );
END
