/**
 * Problem: Find Customer Referee (584)
 * Link: https://leetcode.com/problems/find-customer-referee/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

# Write your MySQL query statement below
SELECT name from Customer
WHERE referee_id != 2 or referee_id IS NULL;
