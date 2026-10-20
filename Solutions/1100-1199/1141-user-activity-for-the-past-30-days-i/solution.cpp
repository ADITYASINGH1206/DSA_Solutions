/**
 * Problem: User Activity for the Past 30 Days I (1141)
 * Link: https://leetcode.com/problems/user-activity-for-the-past-30-days-i/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

# Write your MySQL query statement below
SELECT activity_date AS day, COUNT(DISTINCT user_id) AS active_users
FROM Activity
WHERE activity_date <= '2019-07-27' AND DATEDIFF('2019-07-27', activity_date) < 30
GROUP BY 1;
