/**
 * Problem: Customer Who Visited but Did Not Make Any Transactions (1581)
 * Link: https://leetcode.com/problems/customer-who-visited-but-did-not-make-any-transactions/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

# Write your MySQL query statement below
SELECT customer_id, COUNT(1) AS count_no_trans
FROM Visits
WHERE visit_id NOT IN (SELECT visit_id FROM Transactions)
GROUP BY 1;
