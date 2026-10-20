# [1633. Percentage of Users Attended a Contest](https://leetcode.com/problems/percentage-of-users-attended-a-contest/)
**Difficulty:** `Easy` | **Tags:** `database`

---

## Problem Description
Table: `Users`

```
+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| user_id     | int     |
| user_name   | varchar |
+-------------+---------+
user_id is the primary key (column with unique values) for this table.
Each row of this table contains the name and the id of a user.
```

Table: `Register`

```
+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| contest_id  | int     |
| user_id     | int     |
+-------------+---------+
(contest_id, user_id) is the primary key (combination of columns with unique values) for this table.
Each row of this table contains the id of a user and the contest they registered into.
```

Write a solution to find the percentage of the users registered in each contest rounded to **two decimals**.

Return the result table ordered by `percentage` in **descending order**. In case of a tie, order it by `contest_id` in **ascending order**.

The result format is in the following example.

**Example 1:**

```
Input: 
Users table:
+---------+-----------+
| user_id | user_name |
+---------+-----------+
| 6       | Alice     |
| 2       | Bob       |
| 7       | Alex      |
+---------+-----------+
Register table:
+------------+---------+
| contest_id | user_id |
+------------+---------+
| 215        | 6       |
| 209        | 2       |
| 208        | 2       |
| 210        | 6       |
| 208        | 6       |
| 209        | 7       |
| 209        | 6       |
| 215        | 7       |
| 208        | 7       |
| 210        | 2       |
| 207        | 2       |
| 210        | 7       |
+------------+---------+
Output: 
+------------+------------+
| contest_id | percentage |
+------------+------------+
| 208        | 100.0      |
| 209        | 100.0      |
| 210        | 100.0      |
| 215        | 66.67      |
| 207        | 33.33      |
+------------+------------+
Explanation: 
All the users registered in contests 208, 209, and 210. The percentage is 100% and we sort them in the answer table by contest_id in ascending order.
Alice and Alex registered in contest 215 and the percentage is ((2/3) * 100) = 66.67%
Bob registered in contest 207 and the percentage is ((1/3) * 100) = 33.33%
```

---

## Solution & Editorial
# Intuition
To calculate the percentage of users per contest, we need two values: the count of unique users registered for a specific contest and the total number of users in the system. Since the total user count is a constant across all contests, we can retrieve it using a subquery and divide the contest-specific count by this total.

# Approach
1. **Calculate Total Users**: Use a subquery `(SELECT COUNT(1) FROM Users)` to determine the denominator, which represents the total population of users.
2. **Group by Contest**: Group the `Register` table by `contest_id` to isolate registrations for each specific contest.
3. **Calculate Percentage**: For each group, count the number of registrations using `COUNT(1)`. Multiply this by 100.0 and divide by the total user count obtained in step 1.
4. **Rounding**: Apply the `ROUND(..., 2)` function to ensure the result is formatted to two decimal places.
5. **Ordering**: Sort the final result set by `percentage` in descending order, and use `contest_id` in ascending order as a tie-breaker.

### Visual Trace (Example 1)
| Step | Operation | Result |
| :--- | :--- | :--- |
| 1 | Total Users | 3 |
| 2 | Group 208 | Count=3, Pct=(3/3)*100 = 100.0 |
| 3 | Group 215 | Count=2, Pct=(2/3)*100 = 66.67 |
| 4 | Group 207 | Count=1, Pct=(1/3)*100 = 33.33 |

# Complexity
- Time complexity: $$O(N + M)$$, where $$N$$ is the number of users and $$M$$ is the number of registrations. The subquery takes $$O(N)$$ and the grouping/aggregation takes $$O(M)$$.
- Space complexity: $$O(K)$$, where $$K$$ is the number of unique contests, required to store the intermediate result set before sorting.

# Code
```cpp
# Write your MySQL query statement below
SELECT
contest_id,
ROUND(COUNT(1) * 100 / (SELECT COUNT(1) FROM Users), 2) AS percentage
FROM Register
GROUP BY 1
ORDER BY 2 DESC, 1;
```
