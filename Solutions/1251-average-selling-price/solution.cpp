/**
 * Problem: Average Selling Price (1251)
 * Link: https://leetcode.com/problems/average-selling-price/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

# Write your MySQL query statement below
SELECT
p.product_id,
IFNULL(ROUND(SUM(price * units) / SUM(units), 2), 0) AS average_price
FROM
Prices AS p
LEFT JOIN UnitsSold AS u
    ON p.product_id = u.product_id AND purchase_date BETWEEN start_date AND end_date
GROUP BY 1;
