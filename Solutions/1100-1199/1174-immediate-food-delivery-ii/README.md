# [1174. Immediate Food Delivery II](https://leetcode.com/problems/immediate-food-delivery-ii/)
**Difficulty:** `Medium` | **Tags:** `database`

---

## Problem Description
Table: `Delivery`

```
+-----------------------------+---------+
| Column Name                 | Type    |
+-----------------------------+---------+
| delivery_id                 | int     |
| customer_id                 | int     |
| order_date                  | date    |
| customer_pref_delivery_date | date    |
+-----------------------------+---------+
delivery_id is the column of unique values of this table.
The table holds information about food delivery to customers that make orders at some date and specify a preferred delivery date (on the same order date or after it).
```

If the customer's preferred delivery date is the same as the order date, then the order is called **immediate;** otherwise, it is called **scheduled**.

The **first order** of a customer is the order with the earliest order date that the customer made. It is guaranteed that a customer has precisely one first order.

Write a solution to find the percentage of immediate orders in the first orders of all customers, **rounded to 2 decimal places**.

The result format is in the following example.

**Example 1:**

```
Input: 
Delivery table:
+-------------+-------------+------------+-----------------------------+
| delivery_id | customer_id | order_date | customer_pref_delivery_date |
+-------------+-------------+------------+-----------------------------+
| 1           | 1           | 2019-08-01 | 2019-08-02                  |
| 2           | 2           | 2019-08-02 | 2019-08-02                  |
| 3           | 1           | 2019-08-11 | 2019-08-12                  |
| 4           | 3           | 2019-08-24 | 2019-08-24                  |
| 5           | 3           | 2019-08-21 | 2019-08-22                  |
| 6           | 2           | 2019-08-11 | 2019-08-13                  |
| 7           | 4           | 2019-08-09 | 2019-08-09                  |
+-------------+-------------+------------+-----------------------------+
Output: 
+----------------------+
| immediate_percentage |
+----------------------+
| 50.00                |
+----------------------+
Explanation: 
The customer id 1 has a first order with delivery id 1 and it is scheduled.
The customer id 2 has a first order with delivery id 2 and it is immediate.
The customer id 3 has a first order with delivery id 5 and it is scheduled.
The customer id 4 has a first order with delivery id 7 and it is immediate.
Hence, half the customers have immediate first orders.
```

---

## Solution & Editorial
# Intuition
The problem requires us to calculate the percentage of immediate orders specifically considering only the **first order** of each customer. To achieve this, we first need to identify the minimum order date for each customer and then evaluate whether that specific order was immediate or scheduled.

# Approach
1. Use a subquery to find the earliest order date for each unique `customer_id` using `MIN(order_date)` grouped by `customer_id`.
2. Filter the main `Delivery` table using a composite `IN` clause `(customer_id, order_date)` to retain only the rows corresponding to each customer's first order.
3. Evaluate whether `order_date = customer_pref_delivery_date` for these filtered rows, which evaluates to 1 (true) or 0 (false).
4. Compute the average of these boolean conditions using `AVG()`, multiply by 100 to get a percentage, and round the final result to two decimal places using `ROUND(..., 2)`.

## Visual Trace Walkthrough
For Example 1:
- **Subquery Extraction (First Orders):**
  - Customer 1: `2019-08-01` (Delivery ID 1, Scheduled)
  - Customer 2: `2019-08-02` (Delivery ID 2, Immediate)
  - Customer 3: `2019-08-21` (Delivery ID 5, Scheduled)
  - Customer 4: `2019-08-09` (Delivery ID 7, Immediate)
- **Evaluation:**
  - Delivery 1: `0`
  - Delivery 2: `1`
  - Delivery 5: `0`
  - Delivery 7: `1`
- **Aggregation:** `AVG(0, 1, 0, 1) = 0.50` -> `50.00`

# Complexity
- Time complexity: $$O(N \log N)$$ or $$O(N)$$ depending on the database engine's indexing and join optimization for evaluating the correlated subquery / grouping.
- Space complexity: $$O(N)$$ for storing intermediate temporary tables or hash tables during the grouping and filtering phase.

# Code
```cpp
# Write your MySQL query statement below
SELECT
ROUND(AVG(order_date = customer_pref_delivery_date) * 100, 2) AS immediate_percentage
FROM Delivery
WHERE
(customer_id, order_date) IN (
SELECT customer_id, MIN(order_date)
FROM Delivery
GROUP BY 1
);
```
