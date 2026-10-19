# [182. Duplicate Emails](https://leetcode.com/problems/duplicate-emails/)
**Difficulty:** `Easy` | **Tags:** `database`

---

## Problem Description
Table: `Person`

```
+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| id          | int     |
| email       | varchar |
+-------------+---------+
id is the primary key (column with unique values) for this table.
Each row of this table contains an email. The emails will not contain uppercase letters.
```

Write a solution to report all the duplicate emails. Note that it's guaranteed that the email field is not NULL.

Return the result table in **any order**.

The result format is in the following example.

**Example 1:**

```
Input: 
Person table:
+----+---------+
| id | email   |
+----+---------+
| 1  | a@b.com |
| 2  | c@d.com |
| 3  | a@b.com |
+----+---------+
Output: 
+---------+
| Email   |
+---------+
| a@b.com |
+---------+
Explanation: a@b.com is repeated two times.
```

---

## Solution & Editorial
# Intuition
To find duplicate emails from the `Person` table, we need to group the records by the email address and filter out those that appear more than once.

# Approach
1. Use the `GROUP BY` clause to aggregate rows by the `email` column.
2. Apply the `HAVING` clause with `COUNT(email) > 1` to filter and retain only the email addresses that appear with a frequency greater than 1.
3. Select the `email` column from the resulting grouped records.

### Visual Trace Walkthrough
Given `Person` table:
| id | email |
|----|---------|
| 1 | a@b.com |
| 2 | c@d.com |
| 3 | a@b.com |

- Group by `email`:
  - `a@b.com`: count = 2
  - `c@d.com`: count = 1
- Filter with `HAVING COUNT(email) > 1`:
  - Retains `a@b.com`

# Complexity
- Time complexity: $$O(N)$$ — where $$N$$ is the number of rows in the `Person` table, required to group and count the emails.
- Space complexity: $$O(N)$$ — for storing the intermediate hash or sort-based aggregation groups.

# Code
```cpp
# Write your MySQL query statement below
SELECT email FROM Person
GROUP BY email
HAVING COUNT(email)>1
```
