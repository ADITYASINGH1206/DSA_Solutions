/**
 * Problem: Managers with at Least 5 Direct Reports (570)
 * Link: https://leetcode.com/problems/managers-with-at-least-5-direct-reports/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

# Write your MySQL query statement below
SELECT name
FROM
Employee
JOIN (
SELECT managerId AS id, COUNT(1) AS cnt
FROM Employee
GROUP BY 1
HAVING cnt >= 5
) AS t
USING (id);
