/**
 * Problem: Customers Who Bought All Products (1045)
 * Link: https://leetcode.com/problems/customers-who-bought-all-products/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

# Write your MySQL query statement below
SELECT customer_id
FROM Customer
GROUP BY 1
HAVING COUNT(DISTINCT product_key) = (SELECT COUNT(1) FROM Product);
