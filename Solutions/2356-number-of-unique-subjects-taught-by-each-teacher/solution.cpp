/**
 * Problem: Number of Unique Subjects Taught by Each Teacher (2356)
 * Link: https://leetcode.com/problems/number-of-unique-subjects-taught-by-each-teacher/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

# Write your MySQL query statement below
SELECT teacher_id, COUNT(DISTINCT subject_id) AS cnt
FROM Teacher
GROUP BY 1;
