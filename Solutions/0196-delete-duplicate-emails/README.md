# [196. Delete Duplicate Emails](https://leetcode.com/problems/delete-duplicate-emails/)
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

Write a solution to **delete** all duplicate emails, keeping only one unique email with the smallest `id`.

For SQL users, please note that you are supposed to write a `DELETE` statement and not a `SELECT` one.

For Pandas users, please note that you are supposed to modify `Person` in place.

After running your script, the answer shown is the `Person` table. The driver will first compile and run your piece of code and then show the `Person` table. The final order of the `Person` table **does not matter**.

The result format is in the following example.

**Example 1:**

```
Input: 
Person table:
+----+------------------+
| id | email            |
+----+------------------+
| 1  | john@example.com |
| 2  | bob@example.com  |
| 3  | john@example.com |
+----+------------------+
Output: 
+----+------------------+
| id | email            |
+----+------------------+
| 1  | john@example.com |
| 2  | bob@example.com  |
+----+------------------+
Explanation: john@example.com is repeated two times. We keep the row with the smallest Id = 1.
```

---

## Solution & Editorial
# Intuition
The problem requires us to remove duplicate email rows from the `Person` table while retaining the row with the smallest `id` for each unique email address. We can achieve this efficiently using a self-join where we match rows sharing the same email but having a larger `id` on the deletion side.

# Approach
1. Perform a `JOIN` operation on the `Person` table with an alias `p1` (the rows to be deleted) and an alias `p2` (the reference rows to keep).
2. Set the join condition such that `p1.email = p2.email` and `p1.id > p2.id`, which isolates any record with a duplicate email that possesses a strictly greater `id` than its counterpart.
3. Execute the `DELETE p1` clause to remove all matching rows identified by the join condition.

### Visual Walkthrough (Example 1)

Initial `Person` table:
| id | email |
|---|---|
| 1 | john@example.com |
| 2 | bob@example.com |
| 3 | john@example.com |

Self-join condition (`p1.email = p2.email AND p1.id > p2.id`):
- Comparing `p1` (id=3, john@example.com) with `p2` (id=1, john@example.com): matches because emails are equal and $3 > 1$.
- Therefore, the row with `id = 3` is targeted for deletion.

# Complexity
- Time complexity: $$O(N^2)$$ in the worst-case depending on the database engine's join implementation, where $$N$$ is the number of rows in the `Person` table.
- Space complexity: $$O(1)$$ auxiliary space used by the query execution.

# Code
```cpp
# Write your MySQL query statement below
DELETE p1 FROM Person p1
JOIN Person p2
ON p1.email=p2.email AND p1.id>p2.id
```
