# [619. Biggest Single Number](https://leetcode.com/problems/biggest-single-number/)
**Difficulty:** `Easy` | **Tags:** `database`

---

## Problem Description
Table: `MyNumbers`

```
+-------------+------+
| Column Name | Type |
+-------------+------+
| num         | int  |
+-------------+------+
This table may contain duplicates (In other words, there is no primary key for this table in SQL).
Each row of this table contains an integer.
```

A **single number** is a number that appeared only once in the `MyNumbers` table.

Find the largest **single number**. If there is no **single number**, report `null`.

The result format is in the following example.

 

**Example 1:**

```
Input: 
MyNumbers table:
+-----+
| num |
+-----+
| 8   |
| 8   |
| 3   |
| 3   |
| 1   |
| 4   |
| 5   |
| 6   |
+-----+
Output: 
+-----+
| num |
+-----+
| 6   |
+-----+
Explanation: The single numbers are 1, 4, 5, and 6.
Since 6 is the largest single number, we return it.
```

**Example 2:**

```
Input: 
MyNumbers table:
+-----+
| num |
+-----+
| 8   |
| 8   |
| 7   |
| 7   |
| 3   |
| 3   |
| 3   |
+-----+
Output: 
+------+
| num  |
+------+
| null |
+------+
Explanation: There are no single numbers in the input table so we return null.
```

---

## Solution & Editorial
# Intuition
To find the largest single number, we first need to filter out all numbers that appear more than once. We can achieve this by grouping the numbers and using a `HAVING` clause to keep only those with a count of 1. Finally, wrapping this result in a subquery allows us to apply the `MAX()` aggregate function to find the largest value among the remaining single numbers.

# Approach
1. Use a subquery to group the `MyNumbers` table by the `num` column.
2. Filter the grouped rows using `HAVING COUNT(1) = 1` to isolate numbers that appear exactly once.
3. Wrap the subquery and select `MAX(num)` to find the maximum value among the isolated single numbers. If no rows are returned by the subquery, `MAX(num)` correctly evaluates to `NULL`.

# Visual Walkthrough
For Example 1:
- Input rows: `[8, 8, 3, 3, 1, 4, 5, 6]`
- Group counts:
  - `8`: count = 2 (discarded)
  - `3`: count = 2 (discarded)
  - `1`: count = 1 (retained)
  - `4`: count = 1 (retained)
  - `5`: count = 1 (retained)
  - `6`: count = 1 (retained)
- Subquery result: `[1, 4, 5, 6]`
- Outer query `MAX(num)`: `6`

# Complexity
- Time complexity: $$O(N)$$ where $$N$$ is the number of rows in the `MyNumbers` table. The database engine scans the table to group rows and compute counts.
- Space complexity: $$O(U)$$ where $$U$$ is the number of unique elements stored in the intermediate hash table/temporary table during grouping.

# Code
```cpp
# Write your MySQL query statement below
SELECT MAX(num) AS num
FROM
    (
        SELECT num
        FROM MyNumbers
        GROUP BY 1
        HAVING COUNT(1) = 1
    ) AS t;
```
