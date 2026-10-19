/**
 * Problem: Project Employees I (1075)
 * Link: https://leetcode.com/problems/project-employees-i/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

# Write your MySQL query statement
SELECT project_id, ROUND(AVG(experience_years), 2) AS average_years
FROM
Project
JOIN Employee USING (employee_id)
GROUP BY 1;
