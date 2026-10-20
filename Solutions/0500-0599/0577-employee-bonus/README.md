# [577. Employee Bonus](https://leetcode.com/problems/employee-bonus/)
**Difficulty:** `Easy` | **Tags:** `database`

---

## Problem Description
Table: `Employee`

```
+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| empId       | int     |
| name        | varchar |
| supervisor  | int     |
| salary      | int     |
+-------------+---------+
empId is the column with unique values for this table.
Each row of this table indicates the name and the ID of an employee in addition to their salary and the id of their manager.
```

Table: `Bonus`

```
+-------------+------+
| Column Name | Type |
+-------------+------+
| empId       | int  |
| bonus       | int  |
+-------------+------+
empId is the column of unique values for this table.
empId is a foreign key (reference column) to empId from the Employee table.
Each row of this table contains the id of an employee and their respective bonus.
```

Write a solution to report the name and bonus amount of each employee who satisfies either of the following:

* The employee has a bonus **less than** `1000`.
* The employee did not get any bonus.

Return the result table in **any order**.

The result format is in the following example.

**Example 1:**

```
Input: 
Employee table:
+-------+--------+------------+--------+
| empId | name   | supervisor | salary |
+-------+--------+------------+--------+
| 3     | Brad   | null       | 4000   |
| 1     | John   | 3          | 1000   |
| 2     | Dan    | 3          | 2000   |
| 4     | Thomas | 3          | 4000   |
+-------+--------+------------+--------+
Bonus table:
+-------+-------+
| empId | bonus |
+-------+-------+
| 2     | 500   |
| 4     | 2000  |
+-------+-------+
Output: 
+------+-------+
| name | bonus |
+------+-------+
| Brad | null  |
| John | null  |
| Dan  | 500   |
+------+-------+
```

---

## Solution & Editorial
# Intuition
The problem requires us to list all employees who either have a bonus under 1000 or received no bonus at all. Since employees without a bonus will not have matching entries in the `Bonus` table, an `INNER JOIN` would drop them. Thus, a `LEFT JOIN` starting from the `Employee` table is necessary to preserve all employees.

# Approach
1. Perform a `LEFT JOIN` from the `Employee` table to the `Bonus` table using the common column `empId`. This ensures that every employee is included in the intermediate result, with missing bonus entries appearing as `NULL`.
2. Apply a `WHERE` clause using `IFNULL(bonus, 0) < 1000` to filter out employees who received a bonus greater than or equal to 1000, while correctly converting `NULL` bonus values to `0` so they satisfy the condition.
3. Select only the `name` and `bonus` columns from the filtered result.

### Visual Walkthrough
Given the `Employee` and `Bonus` tables:

**Employee Table:**
- Brad (empId: 3)
- John (empId: 1)
- Dan (empId: 2)
- Thomas (empId: 4)

**Bonus Table:**
- Dan (empId: 2, bonus: 500)
- Thomas (empId: 4, bonus: 2000)

**Left Join Output (`Employee` LEFT JOIN `Bonus` ON `empId`):**
- Brad: `NULL` bonus $\to$ `IFNULL(NULL, 0) < 1000` is true (Included: Brad, null)
- John: `NULL` bonus $\to$ `IFNULL(NULL, 0) < 1000` is true (Included: John, null)
- Dan: `500` bonus $\to$ `IFNULL(500, 0) < 1000` is true (Included: Dan, 500)
- Thomas: `2000` bonus $\to$ `IFNULL(2000, 0) < 1000` is false (Excluded)

# Complexity
- Time complexity: $$O(N \log N)$$ where $$N$$ is the number of rows in the `Employee` table, due to potential indexing and hashing operations performed by the SQL engine during the join and filter processes.
- Space complexity: $$O(N)$$ to store the intermediate join and result sets.

# Code
```cpp
# Write your MySQL query statement below
SELECT name, bonus
FROM
Employee
LEFT JOIN Bonus USING (empId)
WHERE IFNULL(bonus, 0) < 1000;
```
