# [1164. Product Price at a Given Date](https://leetcode.com/problems/product-price-at-a-given-date/)
**Difficulty:** `Medium` | **Tags:** `database`

---

## Problem Description
Table: `Products`

```
+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| product_id    | int     |
| new_price     | int     |
| change_date   | date    |
+---------------+---------+
(product_id, change_date) is the primary key (combination of columns with unique values) of this table.
Each row of this table indicates that the price of some product was changed to a new price at some date.
```

Initially, all products have price 10.

Write a solution to find the prices of all products on the date `2019-08-16`.

Return the result table in **any order**.

The result format is in the following example.

**Example 1:**

```
Input: 
Products table:
+------------+-----------+-------------+
| product_id | new_price | change_date |
+------------+-----------+-------------+
| 1          | 20        | 2019-08-14  |
| 2          | 50        | 2019-08-14  |
| 1          | 30        | 2019-08-15  |
| 1          | 35        | 2019-08-16  |
| 2          | 65        | 2019-08-17  |
| 3          | 20        | 2019-08-18  |
+------------+-----------+-------------+
Output: 
+------------+-------+
| product_id | price |
+------------+-------+
| 2          | 50    |
| 1          | 35    |
| 3          | 10    |
+------------+-------+
```

---

## Solution & Editorial
# Intuition
To find the price of each product on a specific date (`2019-08-16`), we need to identify the latest price change date for each product that is less than or equal to the target date. If a product has no price changes on or before the target date, its price defaults to 10.

# Approach
1. **Extract Distinct Products (`T`)**: Create a common table expression (CTE) `T` containing all unique `product_id`s from the `Products` table to ensure every product is represented in the final output.
2. **Find Latest Prices (`P`)**: Create a second CTE `P` that filters price changes on or before `2019-08-16`, groups by `product_id`, and uses `MAX(change_date)` to find the most recent update for each product up to that date.
3. **Join and Default (`SELECT`)**: Perform a `LEFT JOIN` from the distinct products `T` to the filtered prices `P`, replacing `NULL` prices with the default value of `10` using `IFNULL`.

### Visual Walkthrough for Example 1

Given the `Products` table:
- Product 1 changes: `2019-08-14` (20), `2019-08-15` (30), `2019-08-16` (35).
- Product 2 changes: `2019-08-14` (50), `2019-08-17` (65).
- Product 3 changes: `2019-08-18` (20).

Filtering for `change_date <= '2019-08-16' `:
- Product 1 max valid date: `2019-08-16` -> price `35`
- Product 2 max valid date: `2019-08-14` -> price `50`
- Product 3 has no records $\le$ `2019-08-16` -> price defaults to `10` via `LEFT JOIN` and `IFNULL`.

# Complexity
- Time complexity: $$O(N \log N)$$ where $$N$$ is the number of rows in the `Products` table, due to grouping and indexing operations.
- Space complexity: $$O(N)$$ to store temporary intermediate tables `T` and `P` in memory.

# Code
```cpp
# Write your MySQL query statement below
WITH
    T AS (SELECT DISTINCT product_id FROM Products),
    P AS (
        SELECT product_id, new_price AS price
        FROM Products
        WHERE
            (product_id, change_date) IN (
                SELECT product_id, MAX(change_date) AS change_date
                FROM Products
                WHERE change_date <= '2019-08-16'
                GROUP BY 1
            )
    )
SELECT product_id, IFNULL(price, 10) AS price
FROM
    T
    LEFT JOIN P USING (product_id);
```
