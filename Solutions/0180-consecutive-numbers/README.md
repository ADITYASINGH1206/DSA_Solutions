# [180. Consecutive Numbers](https://leetcode.com/problems/consecutive-numbers/)
**Difficulty:** `Medium` | **Tags:** `database`

---

## Problem Description
Table: `Logs`

```
+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| id          | int     |
| num         | varchar |
+-------------+---------+
In SQL, id is the primary key for this table.
id is an autoincrement column starting from 1.
```

Find all numbers that appear at least three times consecutively.

Return the result table in **any order**.

The result format is in the following example.

**Example 1:**

```
Input: 
Logs table:
+----+-----+
| id | num |
+----+-----+
| 1  | 1   |
| 2  | 1   |
| 3  | 1   |
| 4  | 2   |
| 5  | 1   |
| 6  | 2   |
| 7  | 2   |
+----+-----+
Output: 
+-----------------+
| ConsecutiveNums |
+-----------------+
| 1               |
+-----------------+
Explanation: 1 is the only number that appears consecutively for at least three times.
```

---

## Solution & Editorial
# Intuition
The problem asks us to find numbers that appear at least three times consecutively in a table called `Logs`. Since `id` is an auto-incrementing primary key starting from 1, consecutive rows imply consecutive `id` values (i.e., `id`, `id + 1`, and `id + 2`). We can effectively solve this by performing multiple self-joins on the `Logs` table, ensuring that the consecutive IDs match the same number value.

# Approach
1. Alias the `Logs` table three times as `l1`, `l2`, and `l3` to represent three consecutive log entries.
2. Join `l1` with `l2` using the condition `l1.id = l2.id - 1` and `l1.num = l2.num` to ensure `l2` immediately follows `l1` with the identical number.
3. Join `l2` with `l3` using the condition `l2.id = l3.id - 1` and `l2.num = l3.num` to ensure `l3` immediately follows `l2` with the identical number.
4. Project `l2.num` (or any of the matched columns) using `DISTINCT` to avoid duplicate outputs if a number appears consecutively four or more times.

### Visual Trace Walkthrough
Given Example 1 input table:
| id | num |
|----|-----|
| 1  | 1   |
| 2  | 1   |
| 3  | 1   |
| 4  | 2   |
| 5  | 1   |
| 6  | 2   |
| 7  | 2   |

Joining `l1` (id=1, num=1), `l2` (id=2, num=1), and `l3` (id=3, num=1) satisfies all conditions, yielding `num = 1`. No other combinations of three consecutive rows contain identical numbers.

# Complexity
- Time complexity: $$O(N)$$ where $$N$$ is the number of rows in the `Logs` table, as the database engine evaluates indexed joins across sequential rows.
- Space complexity: $$O(1)$$ auxiliary storage, since the result set streams directly from the relational query execution engine without building persistent auxiliary data structures.

# Code
```cpp
# Write your MySQL query statement below
SELECT DISTINCT l2.num AS ConsecutiveNums
FROM
    Logs AS l1
    JOIN Logs AS l2 ON l1.id = l2.id - 1 AND l1.num = l2.num
    JOIN Logs AS l3 ON l2.id = l3.id - 1 AND l2.num = l3.num;
```
