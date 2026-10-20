# [1581. Customer Who Visited but Did Not Make Any Transactions](https://leetcode.com/problems/customer-who-visited-but-did-not-make-any-transactions/)
**Difficulty:** `Easy` | **Tags:** `database`

---

## Problem Description
Table: `Visits`

```
+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| visit_id    | int     |
| customer_id | int     |
+-------------+---------+
visit_id is the column with unique values for this table.
This table contains information about the customers who visited the mall.
```

Table: `Transactions`

```
+----------------+---------+
| Column Name    | Type    |
+----------------+---------+
| transaction_id | int     |
| visit_id       | int     |
| amount         | int     |
+----------------+---------+
transaction_id is column with unique values for this table.
This table contains information about the transactions made during the visit_id.
```

Write a solution to find the IDs of the users who visited without making any transactions and the number of times they made these types of visits.

Return the result table sorted in **any order**.

The result format is in the following example.

**Example 1:**

```
Input: 
Visits
+----------+-------------+
| visit_id | customer_id |
+----------+-------------+
| 1        | 23          |
| 2        | 9           |
| 4        | 30          |
| 5        | 54          |
| 6        | 96          |
| 7        | 54          |
| 8        | 54          |
+----------+-------------+
Transactions
+----------------+----------+--------+
| transaction_id | visit_id | amount |
+----------------+----------+--------+
| 2              | 5        | 310    |
| 3              | 5        | 300    |
| 9              | 5        | 200    |
| 12             | 1        | 910    |
| 13             | 2        | 970    |
+----------------+----------+--------+
Output: 
+-------------+----------------+
| customer_id | count_no_trans |
+-------------+----------------+
| 54          | 2              |
| 30          | 1              |
| 96          | 1              |
+-------------+----------------+
Explanation: 
Customer with id = 23 visited the mall once and made one transaction during the visit with id = 12.
Customer with id = 9 visited the mall once and made one transaction during the visit with id = 13.
Customer with id = 30 visited the mall once and did not make any transactions.
Customer with id = 54 visited the mall three times. During 2 visits they did not make any transactions, and during one visit they made 3 transactions.
Customer with id = 96 visited the mall once and did not make any transactions.
As we can see, users with IDs 30 and 96 visited the mall one time without making any transactions. Also, user 54 visited the mall twice and did not make any transactions.
```

---

## Solution & Editorial
# Intuition
To identify customers who visited but did not make transactions, we need to filter the `Visits` table to exclude any `visit_id` that appears in the `Transactions` table. Once filtered, we group the remaining visits by `customer_id` and count the occurrences.

# Approach
1. Use a subquery to select all `visit_id` values present in the `Transactions` table.
2. Filter the `Visits` table using a `NOT IN` clause to keep only those `visit_id`s that do not exist in the `Transactions` table.
3. Group the resulting rows by `customer_id`.
4. Apply the `COUNT(1)` aggregate function to calculate the number of non-transaction visits per customer.

### Visual Trace (Example 1)
| visit_id | customer_id | In Transactions? | Keep? |
| :--- | :--- | :--- | :--- |
| 1 | 23 | Yes | No |
| 2 | 9 | Yes | No |
| 4 | 30 | No | Yes |
| 5 | 54 | Yes | No |
| 6 | 96 | No | Yes |
| 7 | 54 | No | Yes |
| 8 | 54 | No | Yes |

Resulting set: (30, 1), (96, 1), (54, 1), (54, 1). Grouping by `customer_id` yields (30, 1), (96, 1), (54, 2).

# Complexity
- Time complexity: $$O(V + T)$$, where $$V$$ is the number of visits and $$T$$ is the number of transactions. The `NOT IN` operation effectively scans the transaction set, and the grouping operation processes the filtered visit list.
- Space complexity: $$O(T)$$ to store the set of `visit_id`s from the `Transactions` table for the exclusion check.

# Code
```cpp
# Write your MySQL query statement below
SELECT customer_id, COUNT(1) AS count_no_trans
FROM Visits
WHERE visit_id NOT IN (SELECT visit_id FROM Transactions)
GROUP BY 1;
```
