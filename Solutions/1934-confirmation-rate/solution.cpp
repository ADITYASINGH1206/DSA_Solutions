/**
 * Problem: Confirmation Rate (1934)
 * Link: https://leetcode.com/problems/confirmation-rate/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

# Write your MySQL query statement below
SELECT
user_id,
ROUND(IFNULL(SUM(action = 'confirmed') / COUNT(1), 0), 2) AS confirmation_rate
FROM
SignUps
LEFT JOIN Confirmations USING (user_id)
GROUP BY 1;
