# [1251. Average Selling Price](https://leetcode.com/problems/average-selling-price/)
**Difficulty:** `Easy` | **Tags:** `database`

---

## Problem Description
Table: `Prices`

```
+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| product_id    | int     |
| start_date    | date    |
| end_date      | date    |
| price         | int     |
+---------------+---------+
(product_id, start_date, end_date) is the primary key (combination of columns with unique values) for this table.
Each row of this table indicates the price of the product_id in the period from start_date to end_date.
For each product_id there will be no two overlapping periods. That means there will be no two intersecting periods for the same product_id.
```

Table: `UnitsSold`

```
+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| product_id    | int     |
| purchase_date | date    |
| units         | int     |
+---------------+---------+
This table may contain duplicate rows.
Each row of this table indicates the date, units, and product_id of each product sold.
```

Write a solution to find the average selling price for each product. `average_price` should be **rounded to 2 decimal places**. If a product does not have any sold units, its average selling price is assumed to be 0.

Return the result table in **any order**.

The result format is in the following example.

**Example 1:**

```
Input: 
Prices table:
+------------+------------+------------+--------+
| product_id | start_date | end_date   | price  |
+------------+------------+------------+--------+
| 1          | 2019-02-17 | 2019-02-28 | 5      |
| 1          | 2019-03-01 | 2019-03-22 | 20     |
| 2          | 2019-02-01 | 2019-02-20 | 15     |
| 2          | 2019-02-21 | 2019-03-31 | 30     |
+------------+------------+------------+--------+
UnitsSold table:
+------------+---------------+-------+
| product_id | purchase_date | units |
+------------+---------------+-------+
| 1          | 2019-02-25    | 100   |
| 1          | 2019-03-01    | 15    |
| 2          | 2019-02-10    | 200   |
| 2          | 2019-03-22    | 30    |
+------------+---------------+-------+
Output: 
+------------+---------------+
| product_id | average_price |
+------------+---------------+
| 1          | 6.96          |
| 2          | 16.96         |
+------------+---------------+
Explanation: 
Average selling price = Total Price of Product / Number of products sold.
Average selling price for product 1 = ((100 * 5) + (15 * 20)) / 115 = 6.96
Average selling price for product 2 = ((200 * 15) + (30 * 30)) / 230 = 16.96
```

---

## Solution & Editorial
# Intuition
The problem requires calculating the weighted average selling price of products based on time-bounded price intervals. The core challenge is matching each sale in the `UnitsSold` table with the correct active price period in the `Prices` table, while also ensuring that products with zero sales are included with an average price of `0`.

# Approach
1. Use a `LEFT JOIN` from the `Prices` table to the `UnitsSold` table on `product_id`.
2. Apply a conditional join predicate using `BETWEEN` to match `purchase_date` strictly within the active price window (`start_date` and `end_date`).
3. Group the joined rows by `product_id` to aggregate total revenue (`SUM(price * units)`) and total quantity sold (`SUM(units)`).
4. Compute the weighted average by dividing total revenue by total units, and wrap it inside `ROUND(..., 2)`.
5. Handle products with no sales by using `IFNULL(..., 0)` to default the division result to `0`.

### Visual Trace Walkthrough
For product `1`: 
- Sales are recorded on `2019-02-25` (100 units at price 5) and `2019-03-01` (15 units at price 20).
- Total Revenue = $(100 \times 5) + (15 \times 20) = 500 + 300 = 800$.
- Total Units = $100 + 15 = 115$.
- Average Price = $800 / 115 \approx 6.9565$, which rounds to `6.96`.

# Complexity
- Time complexity: $$O(N \log N + M)$$ where $$N$$ is the size of `Prices` and $$M$$ is the size of `UnitsSold` due to the join and hash aggregation operations.
- Space complexity: $$O(N + M)$$ for storing the temporary intermediate join and hash table groupings.

# Code
```cpp
# Write your MySQL query statement below
SELECT
p.product_id,
IFNULL(ROUND(SUM(price * units) / SUM(units), 2), 0) AS average_price
FROM
Prices AS p
LEFT JOIN UnitsSold AS u
    ON p.product_id = u.product_id AND purchase_date BETWEEN start_date AND end_date
GROUP BY 1;
```
