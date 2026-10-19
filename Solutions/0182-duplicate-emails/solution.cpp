/**
 * Problem: Duplicate Emails (182)
 * Link: https://leetcode.com/problems/duplicate-emails/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

# Write your MySQL query statement below
SELECT email FROM Person
GROUP BY email
HAVING COUNT(email)>1
