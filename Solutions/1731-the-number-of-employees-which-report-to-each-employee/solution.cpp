/**
 * Problem: The Number of Employees Which Report to Each Employee (1731)
 * Link: https://leetcode.com/problems/the-number-of-employees-which-report-to-each-employee/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

# Write your MySQL query statement below
SELECT
    e2.employee_id,
    e2.name,
    COUNT(1) AS reports_count,
    ROUND(AVG(e1.age)) AS average_age
FROM
    Employees AS e1
    JOIN Employees AS e2 ON e1.reports_to = e2.employee_id
GROUP BY 1
ORDER BY 1;
