/**
 * Problem: Not Boring Movies (620)
 * Link: https://leetcode.com/problems/not-boring-movies/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

# Write your MySQL query statement below
SELECT *
FROM Cinema
WHERE description != 'boring' AND id & 1 = 1
ORDER BY 4 DESC;
