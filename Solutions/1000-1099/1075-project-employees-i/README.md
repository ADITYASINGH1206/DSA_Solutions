# [1075. Project Employees I](https://leetcode.com/problems/project-employees-i/)
**Difficulty:** `Easy` | **Tags:** `database`

---

## Problem Description
Table: `Project`

```
+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| project_id  | int     |
| employee_id | int     |
+-------------+---------+
(project_id, employee_id) is the primary key of this table.
employee_id is a foreign key to Employee table.
Each row of this table indicates that the employee with employee_id is working on the project with project_id.
```

Table: `Employee`

```
+------------------+---------+
| Column Name      | Type    |
+------------------+---------+
| employee_id      | int     |
| name             | varchar |
| experience_years | int     |
+------------------+---------+
employee_id is the primary key of this table. It's guaranteed that experience_years is not NULL.
Each row of this table contains information about one employee.
```

Write an SQL query that reports the **average** experience years of all the employees for each project, **rounded to 2 digits**.

Return the result table in **any order**.

The query result format is in the following example.

**Example 1:**

```
Input: 
Project table:
+-------------+-------------+
| project_id  | employee_id |
+-------------+-------------+
| 1           | 1           |
| 1           | 2           |
| 1           | 3           |
| 2           | 1           |
| 2           | 4           |
+-------------+-------------+
Employee table:
+-------------+--------+------------------+
| employee_id | name   | experience_years |
+-------------+--------+------------------+
| 1           | Khaled | 3                |
| 2           | Ali    | 2                |
| 3           | John   | 1                |
| 4           | Doe    | 2                |
+-------------+--------+------------------+
Output: 
+-------------+---------------+
| project_id  | average_years |
+-------------+---------------+
| 1           | 2.00          |
| 2           | 2.50          |
+-------------+---------------+
Explanation: The average experience years for the first project is (3 + 2 + 1) / 3 = 2.00 and for the second project is (3 + 2) / 2 = 2.50
```

---

## Solution & Editorial
# Intuition
To find the average experience years of employees for each project, we need to associate each project entry with the corresponding employee's experience years. By joining the `Project` table with the `Employee` table on `employee_id`, we can group the results by `project_id` and compute the aggregate average.

# Approach
1. Perform an inner join between the `Project` table and the `Employee` table using the common column `employee_id` (`USING (employee_id)`).
2. Group the joined records by `project_id` using `GROUP BY 1`.
3. Apply the aggregate function `AVG(experience_years)` to calculate the mean experience for each group.
4. Wrap the average result in the `ROUND(..., 2)` function to format the output to exactly two decimal places.

### Visual Walkthrough (Example 1)

Joined Rows:
| project_id | employee_id | experience_years |
|---|---|---|
| 1 | 1 | 3 |
| 1 | 2 | 2 |
| 1 | 3 | 1 |
| 2 | 1 | 3 |
| 2 | 4 | 2 |

Grouped and Aggregated:
- `project_id = 1`: Values `{3, 2, 1}` -> Average = `2.00`
- `project_id = 2`: Values `{3, 2}` -> Average = `2.50`

# Complexity
- Time complexity: $$O(N \log N)$$, where $$N$$ is the number of rows in the joined table, due to the sorting/hashing required for the `GROUP BY` operation.
- Space complexity: $$O(N)$$ to store the temporary hash table or intermediate sorted runs for aggregation.

# Code
```cpp
# Write your MySQL query statement
SELECT project_id, ROUND(AVG(experience_years), 2) AS average_years
FROM
Project
JOIN Employee USING (employee_id)
GROUP BY 1;
```
