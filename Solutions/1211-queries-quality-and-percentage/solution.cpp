/**
 * Problem: Queries Quality and Percentage (1211)
 * Link: https://leetcode.com/problems/queries-quality-and-percentage/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

# Write your MySQL query statement below
SELECT
query_name,
ROUND(AVG(rating / position), 2) AS quality,
ROUND(AVG(rating < 3) * 100, 2) AS poor_query_percentage
FROM Queries
WHERE query_name IS NOT NULL
GROUP BY 1;
