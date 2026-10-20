# [610. Triangle Judgement](https://leetcode.com/problems/triangle-judgement/)
**Difficulty:** `Easy` | **Tags:** `database`

---

## Problem Description
Table: `Triangle`

```
+-------------+------+
| Column Name | Type |
+-------------+------+
| x           | int  |
| y           | int  |
| z           | int  |
+-------------+------+
In SQL, (x, y, z) is the primary key column for this table.
Each row of this table contains the lengths of three line segments.
```

Report for every three line segments whether they can form a triangle.

Return the result table in **any order**.

The result format is in the following example.

**Example 1:**

```
Input: 
Triangle table:
+----+----+----+
| x  | y  | z  |
+----+----+----+
| 13 | 15 | 30 |
| 10 | 20 | 15 |
+----+----+----+
Output: 
+----+----+----+----------+
| x  | y  | z  | triangle |
+----+----+----+----------+
| 13 | 15 | 30 | No       |
| 10 | 20 | 15 | Yes      |
+----+----+----+----------+
```

---

## Solution & Editorial
# Intuition
The problem requires us to determine if three given line lengths $x$, $y$, and $z$ can form a valid triangle. According to the triangle inequality theorem, the sum of any two side lengths must be strictly greater than the third side length.

# Approach
1. Select all columns from the `Triangle` table using `SELECT *`.
2. Apply the SQL conditional function `IF` to evaluate the triangle inequality condition: `x + y > z AND x + z > y AND y + z > x`.
3. Return `'Yes'` if all inequalities hold true, and `'No'` otherwise, aliasing the resulting column as `triangle`.

### Visual Trace Walkthrough
For Example 1:
- Row 1: `x = 13, y = 15, z = 30` -> `13 + 15 > 30` is False -> Output `'No'`
- Row 2: `x = 10, y = 20, z = 15` -> `10 + 20 > 15`, `10 + 15 > 20`, and `20 + 15 > 10` are all True -> Output `'Yes'`

# Complexity
- Time complexity: $$O(N)$$ where $$N$$ is the number of rows in the `Triangle` table, as each row is scanned and evaluated once.
- Space complexity: $$O(1)$$ auxiliary space used for evaluating conditions per row.

# Code
```cpp
# Write your MySQL query statement below
SELECT
    *,
    IF(x + y > z AND x + z > y AND y + z > x, 'Yes', 'No') AS triangle
FROM Triangle;
```
