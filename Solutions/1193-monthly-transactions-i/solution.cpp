/**
 * Problem: Monthly Transactions I (1193)
 * Link: https://leetcode.com/problems/monthly-transactions-i/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

# Write your MySQL query statement below
SELECT
DATE_FORMAT(trans_date, '%Y-%m') AS month,
country,
COUNT(1) AS trans_count,
SUM(state = 'approved') AS approved_count,
SUM(amount) AS trans_total_amount,
SUM(IF(state = 'approved', amount, 0)) AS approved_total_amount
FROM Transactions
GROUP BY 1, 2;
