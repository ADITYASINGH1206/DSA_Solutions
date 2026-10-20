# [1667. Fix Names in a Table](https://leetcode.com/problems/fix-names-in-a-table/)
**Difficulty:** `Easy` | **Tags:** `database`

---

## Problem Description
Table: `Users`

```
+----------------+---------+
| Column Name    | Type    |
+----------------+---------+
| user_id        | int     |
| name           | varchar |
+----------------+---------+
user_id is the primary key (column with unique values) for this table.
This table contains the ID and the name of the user. The name consists of only lowercase and uppercase characters.
```

Write a solution to fix the names so that only the first character is uppercase and the rest are lowercase.

Return the result table ordered by `user_id`.

The result format is in the following example.

**Example 1:**

```
Input: 
Users table:
+---------+-------+
| user_id | name  |
+---------+-------+
| 1       | aLice |
| 2       | bOB   |
+---------+-------+
Output: 
+---------+-------+
| user_id | name  |
+---------+-------+
| 1       | Alice |
| 2       | Bob   |
+---------+-------+
```

---

## Solution & Editorial
# Intuition
To normalize the user names, we need to isolate the first character and convert it to uppercase, while simultaneously converting the remainder of the string to lowercase. SQL provides built-in string functions that allow us to perform these transformations efficiently.

# Approach
1. Use `SUBSTRING(name, 1, 1)` to extract the first character of the name.
2. Apply `UPPER()` to the extracted first character to ensure it is capitalized.
3. Use `SUBSTRING(name, 2)` to extract the remainder of the string starting from the second character.
4. Apply `LOWER()` to the remainder to ensure all subsequent characters are lowercase.
5. Use `CONCAT()` to join the transformed first character and the transformed remainder.
6. Order the final result by `user_id` as required.

### Visual Trace (Example 1)
| Input Name | SUBSTRING(n,1,1) | UPPER | SUBSTRING(n,2) | LOWER | Result |
| :--- | :--- | :--- | :--- | :--- | :--- |
| aLice | a | A | Lice | lice | Alice |
| bOB | b | B | OB | ob | Bob |

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the number of rows in the `Users` table. Each row is processed exactly once.
- Space complexity: $$O(N)$$, as the result set stores the transformed names for all rows.

# Code
```cpp
select user_id, concat(upper(substring(name,1,1)),lower(substring(name,2))) as name
from users
order by user_id
```
