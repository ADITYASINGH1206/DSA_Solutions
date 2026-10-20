# [1757. Recyclable and Low Fat Products](https://leetcode.com/problems/recyclable-and-low-fat-products/)
**Difficulty:** `Easy` | **Tags:** `database`

---

## Problem Description
Table: `Products`

```
+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| product_id  | int     |
| low_fats    | enum    |
| recyclable  | enum    |
+-------------+---------+
product_id is the primary key (column with unique values) for this table.
low_fats is an ENUM (category) of type ('Y', 'N') where 'Y' means this product is low fat and 'N' means it is not.
recyclable is an ENUM (category) of types ('Y', 'N') where 'Y' means this product is recyclable and 'N' means it is not.
```

Write a solution to find the ids of products that are both low fat and recyclable.

Return the result table in **any order**.

The result format is in the following example.

**Example 1:**

```
Input: 
Products table:
+-------------+----------+------------+
| product_id  | low_fats | recyclable |
+-------------+----------+------------+
| 0           | Y        | N          |
| 1           | Y        | Y          |
| 2           | N        | Y          |
| 3           | Y        | Y          |
| 4           | N        | N          |
+-------------+----------+------------+
Output: 
+-------------+
| product_id  |
+-------------+
| 1           |
| 3           |
+-------------+
Explanation: Only products 1 and 3 are both low fat and recyclable.
```

---

## Solution & Editorial
# Intuition
To identify products that meet multiple criteria, we must filter the dataset based on the intersection of those conditions. Since we need products that are both 'low fat' and 'recyclable', we apply a logical AND operator on the respective columns.

# Approach
1. Select the `product_id` column from the `Products` table.
2. Apply a `WHERE` clause to filter rows where `low_fats` is equal to 'Y'.
3. Further restrict the result set by adding an `AND` condition where `recyclable` is also equal to 'Y'.

### Visual Trace (Example 1)
| product_id | low_fats | recyclable | Condition (low_fats='Y' AND recyclable='Y') | Include? |
|------------|----------|------------|-------------------------------------------|----------|
| 0          | Y        | N          | Y AND N = False                           | No       |
| 1          | Y        | Y          | Y AND Y = True                            | Yes      |
| 2          | N        | Y          | N AND Y = False                           | No       |
| 3          | Y        | Y          | Y AND Y = True                            | Yes      |
| 4          | N        | N          | N AND N = False                           | No       |

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the number of rows in the `Products` table, as we must perform a full table scan to evaluate the conditions for each row.
- Space complexity: $$O(1)$$, as we are returning the result set directly without allocating additional memory proportional to the input size.

# Code
```cpp
# Write your MySQL query statement below
SELECT product_id FROM Products
WHERE recyclable = 'Y' AND low_fats = 'Y';
```
