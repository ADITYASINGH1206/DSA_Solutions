# [1729. Find Followers Count](https://leetcode.com/problems/find-followers-count/)
**Difficulty:** `Easy` | **Tags:** `database`

---

## Problem Description
Table: `Followers`

```
+-------------+------+
| Column Name | Type |
+-------------+------+
| user_id     | int  |
| follower_id | int  |
+-------------+------+
(user_id, follower_id) is the primary key (combination of columns with unique values) for this table.
This table contains the IDs of a user and a follower in a social media app where the follower follows the user.
```

Write a solution that will, for each user, return the number of followers.

Return the result table ordered by `user_id` in ascending order.

The result format is in the following example.

**Example 1:**

```
Input: 
Followers table:
+---------+-------------+
| user_id | follower_id |
+---------+-------------+
| 0       | 1           |
| 1       | 0           |
| 2       | 0           |
| 2       | 1           |
+---------+-------------+
Output: 
+---------+----------------+
| user_id | followers_count|
+---------+----------------+
| 0       | 1              |
| 1       | 1              |
| 2       | 2              |
+---------+----------------+
Explanation: 
The followers of 0 are {1}
The followers of 1 are {0}
The followers of 2 are {0,1}
```

---

## Solution & Editorial
# Intuition
To determine the number of followers for each user, we need to aggregate the data based on the `user_id` and count the occurrences of `follower_id` associated with each user.

# Approach
1. Use the `GROUP BY` clause on the `user_id` column to consolidate all rows belonging to the same user.
2. Apply the `COUNT()` aggregate function to calculate the number of entries for each group, aliasing the result as `followers_count`.
3. Use the `ORDER BY` clause on `user_id` to ensure the output is sorted in ascending order as required.

### Visual Trace (Example 1)
| user_id | follower_id | Grouping | Count |
| :--- | :--- | :--- | :--- |
| 0 | 1 | Group 0 | 1 |
| 1 | 0 | Group 1 | 1 |
| 2 | 0 | Group 2 | 2 |
| 2 | 1 | Group 2 | 2 |

# Complexity
- Time complexity: $$O(N \log N)$$ where $$N$$ is the number of rows in the `Followers` table. The grouping operation typically involves sorting or hashing, and the final ordering adds the logarithmic factor.
- Space complexity: $$O(N)$$ to store the intermediate result set before returning the final table.

# Code
```cpp
# Write your MySQL query statement below
SELECT user_id, COUNT(1) AS followers_count
FROM Followers
GROUP BY 1
ORDER BY 1;
```
