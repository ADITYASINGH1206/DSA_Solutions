/**
 * Problem: Primary Department for Each Employee (1789)
 * Link: https://leetcode.com/problems/primary-department-for-each-employee/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

# Write your MySQL query statement below
SELECT employee_id, department_id
FROM Employee
WHERE primary_flag = 'Y'
UNION
SELECT employee_id, department_id
FROM Employee
GROUP BY 1
HAVING COUNT(1) = 1;
