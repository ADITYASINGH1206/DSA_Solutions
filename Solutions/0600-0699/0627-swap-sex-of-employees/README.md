# [627. Swap Sex of Employees](https://leetcode.com/problems/swap-sex-of-employees/)
**Difficulty:** `Easy` | **Tags:** `database`

---

## Problem Description
Table: `Salary`

```
+-------------+----------+
| Column Name | Type     |
+-------------+----------+
| id          | int      |
| name        | varchar  |
| sex         | ENUM     |
| salary      | int      |
+-------------+----------+
id is the primary key (column with unique values) for this table.
The sex column is ENUM (category) value of type ('m', 'f').
The table contains information about an employee.
```

Write a solution to swap all `'f'` and `'m'` values (i.e., change all `'f'` values to `'m'` and vice versa) with a **single update statement** and no intermediate temporary tables.

Note that you must write a single update statement, **do not** write any select statement for this problem.

The result format is in the following example.

**Example 1:**

```
Input: 
Salary table:
+----+------+-----+--------+
| id | name | sex | salary |
+----+------+-----+--------+
| 1  | A    | m   | 2500   |
| 2  | B    | f   | 1500   |
| 3  | C    | m   | 5500   |
| 4  | D    | f   | 500    |
+----+------+-----+--------+
Output: 
+----+------+-----+--------+
| id | name | sex | salary |
+----+------+-----+--------+
| 1  | A    | f   | 2500   |
| 2  | B    | m   | 1500   |
| 3  | C    | f   | 5500   |
| 4  | D    | m   | 500    |
+----+------+-----+--------+
Explanation: 
(1, A) and (3, C) were changed from 'm' to 'f'.
(2, B) and (4, D) were changed from 'f' to 'm'.
```

---

## Solution & Editorial
# Intuition
The problem requires updating a database table column conditionally in a single statement without using temporary tables or additional SELECT queries. We can achieve this directly in SQL using the `UPDATE` statement combined with a `CASE` expression.

# Approach
1. Use the `UPDATE salary` command to target the target table directly.
2. Set the `sex` column using a `CASE` control flow structure.
3. Evaluate the current value of `sex`: if it is `'m'`, switch it to `'f'`; otherwise, default to `'m'` (which covers `'f'`).

# Complexity
- Time complexity: $$O(N)$$ — where $$N$$ is the number of rows in the `Salary` table, as every row is evaluated and updated.
- Space complexity: $$O(1)$$ — constant auxiliary storage since the update is performed in-place on the database table.

# Code
```cpp
UPDATE salary SET sex =
CASE sex
    WHEN 'm' THEN 'f'
    ELSE 'm'
END;
```
