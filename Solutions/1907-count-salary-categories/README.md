# [1907. Count Salary Categories](https://leetcode.com/problems/count-salary-categories/)
**Difficulty:** `Medium` | **Tags:** `database`

---

## Problem Description
Table: `Accounts`

```
+-------------+------+
| Column Name | Type |
+-------------+------+
| account_id  | int  |
| income      | int  |
+-------------+------+
account_id is the primary key (column with unique values) for this table.
Each row contains information about the monthly income for one bank account.
```

Write a solution to calculate the number of bank accounts for each salary category. The salary categories are:

* `"Low Salary"`: All the salaries **strictly less** than `$20000`.
* `"Average Salary"`: All the salaries in the **inclusive** range `[$20000, $50000]`.
* `"High Salary"`: All the salaries **strictly greater** than `$50000`.

The result table **must** contain all three categories. If there are no accounts in a category, return `0`.

Return the result table in **any order**.

The result format is in the following example.

**Example 1:**

```
Input: 
Accounts table:
+------------+--------+
| account_id | income |
+------------+--------+
| 3          | 108939 |
| 2          | 12747  |
| 8          | 87709  |
| 6          | 91796  |
+------------+--------+
Output: 
+----------------+----------------+
| category       | accounts_count |
+----------------+----------------+
| Low Salary     | 1              |
| Average Salary | 0              |
| High Salary    | 3              |
+----------------+----------------+
Explanation: 
Low Salary: Account 2.
Average Salary: No accounts.
High Salary: Accounts 3, 6, and 8.
```

---

## Solution & Editorial
# Intuition
To categorize accounts into fixed buckets while ensuring all categories appear in the output (even if the count is zero), we can perform independent aggregations for each category and combine them using the `UNION` operator. This approach treats each category as a distinct query, allowing us to handle the "must contain all three categories" requirement naturally.

# Approach
1. For each category ("Low Salary", "Average Salary", "High Salary"), we construct a query that filters the `Accounts` table based on the specified income range.
2. We use the `SUM()` function combined with a boolean condition (e.g., `income < 20000`). In SQL, this evaluates to 1 for true and 0 for false, effectively counting the rows that satisfy the condition.
3. We use `IFNULL(..., 0)` to ensure that if no rows match the condition, the result is 0 instead of `NULL`.
4. Finally, we combine the three result sets using `UNION` to produce the final table.

### Visual Trace (Example 1)
| Category | Condition | Matches | Count |
| :--- | :--- | :--- | :--- |
| Low Salary | income < 20000 | {12747} | 1 |
| Average Salary | 20000 <= income <= 50000 | {} | 0 |
| High Salary | income > 50000 | {108939, 87709, 91796} | 3 |

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the number of rows in the `Accounts` table. Each of the three queries performs a full table scan.
- Space complexity: $$O(1)$$, as we only store the counts for the three categories regardless of the input size.

# Code
```cpp
# Write your MySQL query statement below
SELECT 'Low Salary' AS category, IFNULL(SUM(income < 20000), 0) AS accounts_count FROM Accounts
UNION
SELECT
    'Average Salary' AS category,
    IFNULL(SUM(income BETWEEN 20000 AND 50000), 0) AS accounts_count
FROM Accounts
UNION
SELECT 'High Salary' AS category, IFNULL(SUM(income > 50000), 0) AS accounts_count FROM Accounts;
```
