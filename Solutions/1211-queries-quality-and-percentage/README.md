# [1211. Queries Quality and Percentage](https://leetcode.com/problems/queries-quality-and-percentage/)
**Difficulty:** `Easy` | **Tags:** `database`

---

## Problem Description
Table: `Queries`

```
+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| query_name  | varchar |
| result      | varchar |
| position    | int     |
| rating      | int     |
+-------------+---------+
This table may have duplicate rows.
This table contains information collected from some queries on a database.
The position column has a value from 1 to 500.
The rating column has a value from 1 to 5. Query with rating less than 3 is a poor query.
```

We define query `quality` as:

> The average of the ratio between query rating and its position.

We also define `poor query percentage` as:

> The percentage of all queries with rating less than 3.

Write a solution to find each `query_name`, the `quality` and `poor_query_percentage`.

Both `quality` and `poor_query_percentage` should be **rounded to 2 decimal places**.

Return the result table in **any order**.

The result format is in the following example.

**Example 1:**

```
Input: 
Queries table:
+------------+-------------------+----------+--------+
| query_name | result            | position | rating |
+------------+-------------------+----------+--------+
| Dog        | Golden Retriever  | 1        | 5      |
| Dog        | German Shepherd   | 2        | 5      |
| Dog        | Mule              | 200      | 1      |
| Cat        | Shirazi           | 5        | 2      |
| Cat        | Siamese           | 3        | 3      |
| Cat        | Sphynx            | 7        | 4      |
+------------+-------------------+----------+--------+
Output: 
+------------+---------+-----------------------+
| query_name | quality | poor_query_percentage |
+------------+---------+-----------------------+
| Dog        | 2.50    | 33.33                 |
| Cat        | 0.66    | 33.33                 |
+------------+---------+-----------------------+
Explanation: 
Dog queries quality is ((5 / 1) + (5 / 2) + (1 / 200)) / 3 = 2.50
Dog queries poor_ query_percentage is (1 / 3) * 100 = 33.33

Cat queries quality equals ((2 / 5) + (3 / 3) + (4 / 7)) / 3 = 0.66
Cat queries poor_ query_percentage is (1 / 3) * 100 = 33.33
```

---

## Solution & Editorial
# Intuition
The problem requires calculating two statistical metrics grouped by `query_name`: `quality` (the average ratio of `rating` to `position`) and `poor_query_percentage` (the percentage of queries with `rating < 3`). Using standard SQL aggregation functions along with conditional expressions allows us to compute these metrics efficiently in a single pass over the grouped data.

# Approach
1. Filter out any rows where `query_name` is null using the `WHERE query_name IS NOT NULL` clause.
2. Group the rows by `query_name` using `GROUP BY 1`.
3. Calculate the `quality` by taking the average of `rating / position` and rounding the result to 2 decimal places using `ROUND(..., 2)`.
4. Calculate the `poor_query_percentage` by taking the average of boolean conditions `rating < 3` (which evaluates to 1 for true and 0 for false), multiplying by 100 to convert to a percentage, and rounding to 2 decimal places.

# Complexity
- Time complexity: $$O(N)$$ — where $$N$$ is the number of rows in the `Queries` table. The database engine scans the table, filters nulls, and aggregates by `query_name` in linear time with respect to the input size.
- Space complexity: $$O(U)$$ — where $$U$$ is the number of unique `query_names` stored in the aggregation hash table before returning the result.

# Code
```cpp
# Write your MySQL query statement below
SELECT
query_name,
ROUND(AVG(rating / position), 2) AS quality,
ROUND(AVG(rating < 3) * 100, 2) AS poor_query_percentage
FROM Queries
WHERE query_name IS NOT NULL
GROUP BY 1;
```
