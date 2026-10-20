/**
 * Problem: Recyclable and Low Fat Products (1757)
 * Link: https://leetcode.com/problems/recyclable-and-low-fat-products/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

# Write your MySQL query statement below
SELECT product_id FROM Products
WHERE recyclable = 'Y' AND low_fats = 'Y';
