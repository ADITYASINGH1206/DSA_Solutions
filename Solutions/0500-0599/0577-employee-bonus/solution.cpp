/**
 * Problem: Employee Bonus (577)
 * Link: https://leetcode.com/problems/employee-bonus/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

# Write your MySQL query statement below
SELECT name, bonus
FROM
Employee
LEFT JOIN Bonus USING (empId)
WHERE IFNULL(bonus, 0) < 1000;
