# [584. Find Customer Referee](https://leetcode.com/problems/find-customer-referee/)
**Difficulty:** `Easy` | **Tags:** `database`

---

## Problem Description
Table: `Customer`

```
+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| id          | int     |
| name        | varchar |
| referee_id  | int     |
+-------------+---------+
In SQL, id is the primary key column for this table.
Each row of this table indicates the id of a customer, their name, and the id of the customer who referred them.
```

Find the names of the customer that are either:

1. **referred by** any customer with `id != 2`.
2. **not referred by** any customer.

Return the result table in **any order**.

The result format is in the following example.

**Example 1:**

```
Input: 
Customer table:
+----+------+------------+
| id | name | referee_id |
+----+------+------------+
| 1  | Will | null       |
| 2  | Jane | null       |
| 3  | Alex | 2          |
| 4  | Bill | null       |
| 5  | Zack | 1          |
| 6  | Mark | 2          |
+----+------+------------+
Output: 
+------+
| name |
+------+
| Will |
| Jane |
| Bill |
| Zack |
+------+
```

---

## Solution & Editorial
# Intuition
The problem requires us to filter rows from the `Customer` table based on a condition involving the `referee_id` column. Specifically, we want customers whose `referee_id` is either not equal to `2` or is explicitly `NULL`.

# Approach
1. Use a standard `SELECT name FROM Customer` query to retrieve the desired column.
2. Apply a `WHERE` clause with the condition `referee_id != 2 OR referee_id IS NULL` to properly capture both criteria.
3. Note that in SQL, comparisons involving `NULL` evaluate to unknown, so `referee_id IS NULL` is mandatory to include rows where the customer was not referred by anyone.

### Visual Walkthrough
Given Example 1 input:
| id | name | referee_id |
|---|---|---|
| 1 | Will | null |
| 2 | Jane | null |
| 3 | Alex | 2 |
| 4 | Bill | null |
| 5 | Zack | 1 |
| 6 | Mark | 2 |

Evaluating the `WHERE` condition row by row:
- Row 1 (Will, null): `referee_id IS NULL` is true -> Included
- Row 2 (Jane, null): `referee_id IS NULL` is true -> Included
- Row 3 (Alex, 2): `referee_id != 2` is false and `IS NULL` is false -> Excluded
- Row 4 (Bill, null): `referee_id IS NULL` is true -> Included
- Row 5 (Zack, 1): `referee_id != 2` (1 != 2) is true -> Included
- Row 6 (Mark, 2): `referee_id != 2` is false and `IS NULL` is false -> Excluded

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the number of rows in the `Customer` table, as the database engine performs a full table scan or index scan to evaluate the predicate.
- Space complexity: $$O(1)$$ auxiliary memory, assuming the result set is streamed or returned without additional internal storage overhead.

# Code
```cpp
# Write your MySQL query statement below
SELECT name from Customer
WHERE referee_id != 2 or referee_id IS NULL;
```
