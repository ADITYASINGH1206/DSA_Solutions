# [570. Managers with at Least 5 Direct Reports](https://leetcode.com/problems/managers-with-at-least-5-direct-reports/)
**Difficulty:** `Medium` | **Tags:** `database`

---

## Problem Description
Table: `Employee`

```
+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| id          | int     |
| name        | varchar |
| department  | varchar |
| managerId   | int     |
+-------------+---------+
id is the primary key (column with unique values) for this table.
Each row of this table indicates the name of an employee, their department, and the id of their manager.
If managerId is null, then the employee does not have a manager.
No employee will be the manager of themself.
```

Write a solution to find managers with at least **five direct reports**.

Return the result table in **any order**.

The result format is in the following example.

**Example 1:**

```
Input: 
Employee table:
+-----+-------+------------+-----------+
| id  | name  | department | managerId |
+-----+-------+------------+-----------+
| 101 | John  | A          | null      |
| 102 | Dan   | A          | 101       |
| 103 | James | A          | 101       |
| 104 | Amy   | A          | 101       |
| 105 | Anne  | A          | 101       |
| 106 | Ron   | B          | 101       |
+-----+-------+------------+-----------+
Output: 
+------+
| name |
+------+
| John |
+------+
```

---

## Solution & Editorial
# Intuition
The problem requires us to identify managers who have at least five direct reports based on the `Employee` table. We can achieve this by aggregating the employee records by their `managerId`, filtering for those with a count of 5 or greater, and then joining back to the original employee table to retrieve their names.

# Approach
1. Create a subquery that groups the `Employee` table by `managerId` and counts the number of occurrences using `COUNT(1)`.
2. Apply a `HAVING` clause to retain only those groups where the count is greater than or equal to 5, mapping the `managerId` as `id`.
3. Perform an inner join between the original `Employee` table and this aggregated subquery using the common column `id`.
4. Select and return the `name` column from the joined result set.

# Complexity
- Time complexity: $$O(N \log N)$$ or $$O(N)$$ depending on the database engine's execution plan for grouping and joining hashes, where $$N$$ is the number of rows in the `Employee` table.
- Space complexity: $$O(U)$$ where $$U$$ is the number of unique managers stored in the intermediate hash table or temporary grouping structure.

# Code
```cpp
# Write your MySQL query statement below
SELECT name
FROM
Employee
JOIN (
SELECT managerId AS id, COUNT(1) AS cnt
FROM Employee
GROUP BY 1
HAVING cnt >= 5
) AS t
USING (id);
```
