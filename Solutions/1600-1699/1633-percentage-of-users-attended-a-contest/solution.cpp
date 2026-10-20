/**
 * Problem: Percentage of Users Attended a Contest (1633)
 * Link: https://leetcode.com/problems/percentage-of-users-attended-a-contest/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

# Write your MySQL query statement below
SELECT
contest_id,
ROUND(COUNT(1) * 100 / (SELECT COUNT(1) FROM Users), 2) AS percentage
FROM Register
GROUP BY 1
ORDER BY 2 DESC, 1;
