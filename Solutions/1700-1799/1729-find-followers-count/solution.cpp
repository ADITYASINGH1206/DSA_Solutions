/**
 * Problem: Find Followers Count (1729)
 * Link: https://leetcode.com/problems/find-followers-count/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

# Write your MySQL query statement below
SELECT user_id, COUNT(1) AS followers_count
FROM Followers
GROUP BY 1
ORDER BY 1;
