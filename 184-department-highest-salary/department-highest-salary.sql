# Write your MySQL query statement below
SELECT D.name Department, E1.name Employee, Salary 
FROM Employee E1 
JOIN Department D ON E1.departmentId = D.id
WHERE salary = (SELECT max(salary) 
                FROM Employee E2 
                WHERE E2.departmentId = E1.departmentId)