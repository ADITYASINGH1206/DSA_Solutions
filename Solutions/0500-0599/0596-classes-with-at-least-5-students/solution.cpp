/**
 * Problem: Classes With at Least 5 Students (596)
 * Link: https://leetcode.com/problems/classes-with-at-least-5-students/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

# Write your MySQL query statement below
SELECT class
FROM Courses
GROUP BY 1
HAVING COUNT(1) >= 5;
