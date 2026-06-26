-- Write your query below
SELECT employee_id, CASE
WHEN name NOT LIKE 'M%' AND employee_id % 2 = 1 THEN salary 
ELSE 0 
END as bonus from employees order by employee_id;