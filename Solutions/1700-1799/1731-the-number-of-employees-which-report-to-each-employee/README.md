# [1731. The Number of Employees Which Report to Each Employee](https://leetcode.com/problems/the-number-of-employees-which-report-to-each-employee/)
**Difficulty:** `Easy` | **Tags:** `database`

---

## Problem Description
Table: `Employees`

```
+-------------+----------+
| Column Name | Type     |
+-------------+----------+
| employee_id | int      |
| name        | varchar  |
| reports_to  | int      |
| age         | int      |
+-------------+----------+
employee_id is the column with unique values for this table.
This table contains information about the employees and the id of the manager they report to. Some employees do not report to anyone (reports_to is null).
```

For this problem, we will consider a **manager** an employee who has at least 1 other employee reporting to them.

Write a solution to report the ids and the names of all **managers**, the number of employees who report **directly** to them, and the average age of the reports rounded to the nearest integer.

Return the result table ordered by `employee_id`.

The result format is in the following example.

**Example 1:**

```
Input: 
Employees table:
+-------------+---------+------------+-----+
| employee_id | name    | reports_to | age |
+-------------+---------+------------+-----+
| 9           | Hercy   | null       | 43  |
| 6           | Alice   | 9          | 41  |
| 4           | Bob     | 9          | 36  |
| 2           | Winston | null       | 37  |
+-------------+---------+------------+-----+
Output: 
+-------------+-------+---------------+-------------+
| employee_id | name  | reports_count | average_age |
+-------------+-------+---------------+-------------+
| 9           | Hercy | 2             | 39          |
+-------------+-------+---------------+-------------+
Explanation: Hercy has 2 people report directly to him, Alice and Bob. Their average age is (41+36)/2 = 38.5, which is 39 after rounding it to the nearest integer.
```

**Example 2:**

```
Input: 
Employees table:
+-------------+---------+------------+-----+ 
| employee_id | name    | reports_to | age |
|-------------|---------|------------|-----|
| 1           | Michael | null       | 45  |
| 2           | Alice   | 1          | 38  |
| 3           | Bob     | 1          | 42  |
| 4           | Charlie | 2          | 34  |
| 5           | David   | 2          | 40  |
| 6           | Eve     | 3          | 37  |
| 7           | Frank   | null       | 50  |
| 8           | Grace   | null       | 48  |
+-------------+---------+------------+-----+ 
Output: 
+-------------+---------+---------------+-------------+
| employee_id | name    | reports_count | average_age |
| ----------- | ------- | ------------- | ----------- |
| 1           | Michael | 2             | 40          |
| 2           | Alice   | 2             | 37          |
| 3           | Bob     | 1             | 37          |
+-------------+---------+---------------+-------------+
```

---

## Solution & Editorial
# Intuition
To identify managers and their direct reports, we need to relate employees to their managers. Since both entities exist within the same `Employees` table, a self-join is the most efficient way to pair each report with their respective manager.

# Approach
1. Perform an `INNER JOIN` on the `Employees` table with itself (aliased as `e1` for reports and `e2` for managers) where `e1.reports_to` matches `e2.employee_id`.
2. Group the resulting rows by the manager's `employee_id` and `name`.
3. Calculate the `reports_count` using `COUNT(1)` and the `average_age` using `ROUND(AVG(e1.age))`.
4. Order the final result by `employee_id` as required.

### Visual Trace (Example 1)
| e1 (Report) | e2 (Manager) | Join Condition (e1.reports_to = e2.employee_id) |
| :--- | :--- | :--- |
| Alice (41) | Hercy (9) | 9 = 9 |
| Bob (36) | Hercy (9) | 9 = 9 |

**Aggregation:**
- Manager: Hercy (ID 9)
- Count: 2
- Average Age: (41 + 36) / 2 = 38.5 -> Rounded to 39

# Complexity
- Time complexity: $$O(N \log N)$$ where $$N$$ is the number of employees, due to the grouping and sorting operations required by the SQL engine.
- Space complexity: $$O(N)$$ to store the intermediate join results before aggregation.

# Code
```cpp
# Write your MySQL query statement below
SELECT
    e2.employee_id,
    e2.name,
    COUNT(1) AS reports_count,
    ROUND(AVG(e1.age)) AS average_age
FROM
    Employees AS e1
    JOIN Employees AS e2 ON e1.reports_to = e2.employee_id
GROUP BY 1
ORDER BY 1;
```
