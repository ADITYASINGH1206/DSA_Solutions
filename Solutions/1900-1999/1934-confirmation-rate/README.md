# [1934. Confirmation Rate](https://leetcode.com/problems/confirmation-rate/)
**Difficulty:** `Medium` | **Tags:** `database`

---

## Problem Description
Table: `Signups`

```
+----------------+----------+
| Column Name    | Type     |
+----------------+----------+
| user_id        | int      |
| time_stamp     | datetime |
+----------------+----------+
user_id is the column of unique values for this table.
Each row contains information about the signup time for the user with ID user_id.
```

Table: `Confirmations`

```
+----------------+----------+
| Column Name    | Type     |
+----------------+----------+
| user_id        | int      |
| time_stamp     | datetime |
| action         | ENUM     |
+----------------+----------+
(user_id, time_stamp) is the primary key (combination of columns with unique values) for this table.
user_id is a foreign key (reference column) to the Signups table.
action is an ENUM (category) of the type ('confirmed', 'timeout')
Each row of this table indicates that the user with ID user_id requested a confirmation message at time_stamp and that confirmation message was either confirmed ('confirmed') or expired without confirming ('timeout').
```

The **confirmation rate** of a user is the number of `'confirmed'` messages divided by the total number of requested confirmation messages. The confirmation rate of a user that did not request any confirmation messages is `0`. Round the confirmation rate to **two decimal** places.

Write a solution to find the **confirmation rate** of each user.

Return the result table in **any order**.

The result format is in the following example.

**Example 1:**

```
Input: 
Signups table:
+---------+---------------------+
| user_id | time_stamp          |
+---------+---------------------+
| 3       | 2020-03-21 10:16:13 |
| 7       | 2020-01-04 13:57:59 |
| 2       | 2020-07-29 23:09:44 |
| 6       | 2020-12-09 10:39:37 |
+---------+---------------------+
Confirmations table:
+---------+---------------------+-----------+
| user_id | time_stamp          | action    |
+---------+---------------------+-----------+
| 3       | 2021-01-06 03:30:46 | timeout   |
| 3       | 2021-07-14 14:00:00 | timeout   |
| 7       | 2021-06-12 11:57:29 | confirmed |
| 7       | 2021-06-13 12:58:28 | confirmed |
| 7       | 2021-06-14 13:59:27 | confirmed |
| 2       | 2021-01-22 00:00:00 | confirmed |
| 2       | 2021-02-28 23:59:59 | timeout   |
+---------+---------------------+-----------+
Output: 
+---------+-------------------+
| user_id | confirmation_rate |
+---------+-------------------+
| 6       | 0.00              |
| 3       | 0.00              |
| 7       | 1.00              |
| 2       | 0.50              |
+---------+-------------------+
Explanation: 
User 6 did not request any confirmation messages. The confirmation rate is 0.
User 3 made 2 requests and both timed out. The confirmation rate is 0.
User 7 made 3 requests and all were confirmed. The confirmation rate is 1.
User 2 made 2 requests where one was confirmed and the other timed out. The confirmation rate is 1 / 2 = 0.5.
```

---

## Solution & Editorial
# Intuition
To calculate the confirmation rate for every user, we must account for users who have never requested a confirmation. A `LEFT JOIN` between the `Signups` table and the `Confirmations` table ensures that all users from the `Signups` table are included in the result set, even if they have no corresponding entries in the `Confirmations` table.

# Approach
1. Perform a `LEFT JOIN` on `Signups` and `Confirmations` using the `user_id` column. This preserves all users from `Signups`.
2. Group the resulting rows by `user_id` to aggregate data per user.
3. For each group, calculate the confirmation rate:
   - Use `SUM(action = 'confirmed')` to count the number of successful confirmations. This works because the boolean expression evaluates to 1 for true and 0 for false.
   - Use `COUNT(*)` (or `COUNT(1)`) to find the total number of requests associated with that user.
   - Use `IFNULL` to handle users with no requests (where the count would be 0, preventing division by zero errors or returning NULL).
4. Apply `ROUND(..., 2)` to format the result to two decimal places.

### Visual Trace (Example 1)
| user_id | action | Condition (action='confirmed') |
| :--- | :--- | :--- |
| 3 | timeout | 0 |
| 3 | timeout | 0 |
| 7 | confirmed | 1 |
| 7 | confirmed | 1 |
| 7 | confirmed | 1 |
| 2 | confirmed | 1 |
| 2 | timeout | 0 |
| 6 | NULL | 0 |

- User 6: SUM=0, COUNT=1 -> 0/1 = 0.00
- User 3: SUM=0, COUNT=2 -> 0/2 = 0.00
- User 7: SUM=3, COUNT=3 -> 3/3 = 1.00
- User 2: SUM=1, COUNT=2 -> 1/2 = 0.50

# Complexity
- Time complexity: $$O(N + M)$$, where $$N$$ is the number of signups and $$M$$ is the number of confirmation records. The database engine performs a join and a single pass aggregation over the joined set.
- Space complexity: $$O(N + M)$$ to store the intermediate joined table before aggregation.

# Code
```cpp
# Write your MySQL query statement below
SELECT
user_id,
ROUND(IFNULL(SUM(action = 'confirmed') / COUNT(1), 0), 2) AS confirmation_rate
FROM
SignUps
LEFT JOIN Confirmations USING (user_id)
GROUP BY 1;
```
