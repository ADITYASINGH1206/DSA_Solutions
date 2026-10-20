# [1141. User Activity for the Past 30 Days I](https://leetcode.com/problems/user-activity-for-the-past-30-days-i/)
**Difficulty:** `Easy` | **Tags:** `database`

---

## Problem Description
Table: `Activity`

```
+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| user_id       | int     |
| session_id    | int     |
| activity_date | date    |
| activity_type | enum    |
+---------------+---------+
This table may have duplicate rows.
The activity_type column is an ENUM (category) of type ('open_session', 'end_session', 'scroll_down', 'send_message').
The table shows the user activities for a social media website. 
Note that each session belongs to exactly one user.
```

Write a solution to find the daily active user count for a period of `30` days ending `2019-07-27` inclusively. A user was active on someday if they made at least one activity on that day.

Return the result table in **any order**.

The result format is in the following example.

Note: **Any** activity from (`'open_session'`, `'end_session'`, `'scroll_down'`, `'send_message'`) will be considered valid activity for a user to be considered active on a day.

**Example 1:**

```
Input: 
Activity table:
+---------+------------+---------------+---------------+
| user_id | session_id | activity_date | activity_type |
+---------+------------+---------------+---------------+
| 1       | 1          | 2019-07-20    | open_session  |
| 1       | 1          | 2019-07-20    | scroll_down   |
| 1       | 1          | 2019-07-20    | end_session   |
| 2       | 4          | 2019-07-20    | open_session  |
| 2       | 4          | 2019-07-21    | send_message  |
| 2       | 4          | 2019-07-21    | end_session   |
| 3       | 2          | 2019-07-21    | open_session  |
| 3       | 2          | 2019-07-21    | send_message  |
| 3       | 2          | 2019-07-21    | end_session   |
| 4       | 3          | 2019-06-25    | open_session  |
| 4       | 3          | 2019-06-25    | end_session   |
+---------+------------+---------------+---------------+
Output: 
+------------+--------------+ 
| day        | active_users |
+------------+--------------+ 
| 2019-07-20 | 2            |
| 2019-07-21 | 2            |
+------------+--------------+ 
Explanation: Note that we do not care about days with zero active users.
```

---

## Solution & Editorial
# Intuition
The problem requires calculating the number of distinct active users for each day over a 30-day window ending on '2019-07-27'. Since a user might perform multiple activities on the same day, we must use `COUNT(DISTINCT user_id)` grouped by the activity date.

# Approach
1. Filter the `Activity` table to include only rows where `activity_date` falls within the 30-day range up to and including '2019-07-27'. This can be expressed via `activity_date <= '2019-07-27' AND DATEDIFF('2019-07-27', activity_date) < 30`.
2. Group the filtered records by `activity_date` (aliased as `day`).
3. Compute the number of unique active users per day using `COUNT(DISTINCT user_id)` (aliased as `active_users`).

### Visual Walkthrough for Example 1

| activity_date | user_id | Within Window (<= 2019-07-27 & < 30 days diff) |
| :--- | :--- | :--- |
| 2019-07-20 | 1 | Yes |
| 2019-07-20 | 1 | Yes |
| 2019-07-20 | 1 | Yes |
| 2019-07-20 | 2 | Yes |
| 2019-07-21 | 2 | Yes |
| 2019-07-21 | 2 | Yes |
| 2019-07-21 | 3 | Yes |
| 2019-07-21 | 3 | Yes |
| 2019-07-21 | 3 | Yes |
| 2019-06-25 | 4 | No (Out of 30-day window) |

Grouping by `activity_date` and counting distinct `user_id` values gives:
- `2019-07-20`: Users {1, 2} -> `2` active users
- `2019-07-21`: Users {2, 3} -> `2` active users

# Complexity
- Time complexity: $$O(N 	ext{ log } N)$$ or $$O(N)$$ depending on the database engine's aggregation and hashing strategy, where $$N$$ is the number of rows in the `Activity` table.
- Space complexity: $$O(K)$$ where $$K$$ is the number of unique dates and users stored in hash tables during the `GROUP BY` and `DISTINCT` operations.

# Code
```cpp
# Write your MySQL query statement below
SELECT activity_date AS day, COUNT(DISTINCT user_id) AS active_users
FROM Activity
WHERE activity_date <= '2019-07-27' AND DATEDIFF('2019-07-27', activity_date) < 30
GROUP BY 1;
```
