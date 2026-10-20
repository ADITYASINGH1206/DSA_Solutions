# [1693. Daily Leads and Partners](https://leetcode.com/problems/daily-leads-and-partners/)
**Difficulty:** `Easy` | **Tags:** `database`

---

## Problem Description
Table: `DailySales`

```
+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| date_id     | date    |
| make_name   | varchar |
| lead_id     | int     |
| partner_id  | int     |
+-------------+---------+
There is no primary key (column with unique values) for this table. It may contain duplicates.
This table contains the date and the name of the product sold and the IDs of the lead and partner it was sold to.
The name consists of only lowercase English letters.
```

For each `date_id` and `make_name`, find the number of **distinct** `lead_id`'s and **distinct** `partner_id`'s.

Return the result table in **any order**.

The result format is in the following example.

**Example 1:**

```
Input: 
DailySales table:
+-----------+-----------+---------+------------+
| date_id   | make_name | lead_id | partner_id |
+-----------+-----------+---------+------------+
| 2020-12-8 | toyota    | 0       | 1          |
| 2020-12-8 | toyota    | 1       | 0          |
| 2020-12-8 | toyota    | 1       | 2          |
| 2020-12-7 | toyota    | 0       | 2          |
| 2020-12-7 | toyota    | 0       | 1          |
| 2020-12-8 | honda     | 1       | 2          |
| 2020-12-8 | honda     | 2       | 1          |
| 2020-12-7 | honda     | 0       | 1          |
| 2020-12-7 | honda     | 1       | 2          |
| 2020-12-7 | honda     | 2       | 1          |
+-----------+-----------+---------+------------+
Output: 
+-----------+-----------+--------------+-----------------+
| date_id   | make_name | unique_leads | unique_partners |
+-----------+-----------+--------------+-----------------+
| 2020-12-8 | toyota    | 2            | 3               |
| 2020-12-7 | toyota    | 1            | 2               |
| 2020-12-8 | honda     | 2            | 2               |
| 2020-12-7 | honda     | 3            | 2               |
+-----------+-----------+--------------+-----------------+
Explanation: 
For 2020-12-8, toyota gets leads = [0, 1] and partners = [0, 1, 2] while honda gets leads = [1, 2] and partners = [1, 2].
For 2020-12-7, toyota gets leads = [0] and partners = [1, 2] while honda gets leads = [0, 1, 2] and partners = [1, 2].
```

---

## Solution & Editorial
# Intuition
To solve this problem, we need to aggregate data based on two dimensions: `date_id` and `make_name`. Since we are tasked with finding the count of *distinct* IDs for both leads and partners within these groups, the standard SQL `GROUP BY` clause combined with the `COUNT(DISTINCT ...)` aggregation function is the most efficient and idiomatic approach.

# Approach
1. **Grouping**: Use `GROUP BY date_id, make_name` to create buckets for every unique combination of date and product manufacturer.
2. **Aggregation**: Within each bucket, apply `COUNT(DISTINCT lead_id)` to calculate the number of unique leads and `COUNT(DISTINCT partner_id)` to calculate the number of unique partners.
3. **Projection**: Select the grouping columns and the two calculated aggregate columns, aliasing them as `unique_leads` and `unique_partners` respectively.

### Visual Trace (Example 1)
| date_id | make_name | lead_id | partner_id | Grouping Key | Distinct Leads | Distinct Partners |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| 2020-12-8 | toyota | 0, 1, 1 | 1, 0, 2 | (2020-12-8, toyota) | {0, 1} -> 2 | {0, 1, 2} -> 3 |
| 2020-12-7 | toyota | 0, 0 | 2, 1 | (2020-12-7, toyota) | {0} -> 1 | {1, 2} -> 2 |

# Complexity
- Time complexity: $$O(N \log N)$$ or $$O(N)$$ depending on the database engine's implementation of `GROUP BY` (typically hash-based aggregation is $$O(N)$$).
- Space complexity: $$O(N)$$ to store the intermediate hash table or sorted structure required for grouping the input rows.

# Code
```cpp
# Write your MySQL query statement below
select date_id, make_name, count(distinct lead_id) as unique_leads, count(distinct partner_id) as unique_partners
from DailySales
group by date_id, make_name;
```
