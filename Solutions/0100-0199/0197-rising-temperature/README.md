# [197. Rising Temperature](https://leetcode.com/problems/rising-temperature/)
**Difficulty:** `Easy` | **Tags:** `database`

---

## Problem Description
Table: `Weather`

```
+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| id            | int     |
| recordDate    | date    |
| temperature   | int     |
+---------------+---------+
id is the column with unique values for this table.
There are no different rows with the same recordDate.
This table contains information about the temperature on a certain day.
```

Write a solution to find all dates' `id` with higher temperatures compared to its previous dates (yesterday).

Return the result table in **any order**.

The result format is in the following example.

**Example 1:**

```
Input: 
Weather table:
+----+------------+-------------+
| id | recordDate | temperature |
+----+------------+-------------+
| 1  | 2015-01-01 | 10          |
| 2  | 2015-01-02 | 25          |
| 3  | 2015-01-03 | 20          |
| 4  | 2015-01-04 | 30          |
+----+------------+-------------+
Output: 
+----+
| id |
+----+
| 2  |
| 4  |
+----+
Explanation: 
In 2015-01-02, the temperature was higher than the previous day (10 -> 25).
In 2015-01-04, the temperature was higher than the previous day (20 -> 30).
```

---

## Solution & Editorial
# Intuition
To find all dates with a higher temperature compared to their previous day, we need to compare each record in the `Weather` table with the record corresponding to the exact preceding calendar day. A self-join on the `Weather` table paired with date arithmetic accomplishes this comparison efficiently.

# Approach
1. Alias the `Weather` table as `w1` (representing the current day) and perform an inner join with another instance of the `Weather` table aliased as `w2` (representing the previous day).
2. Use the `DATEDIFF(w1.recordDate, w2.recordDate) = 1` condition to ensure that `w2`'s date is precisely one day prior to `w1`'s date.
3. Add the temperature comparison condition `w1.temperature > w2.temperature` to filter only the rows where the current day's temperature exceeds the previous day's temperature.
4. Project the `id` column from `w1` as the final output result.

### Visual Trace Walkthrough
Given the example table:

| id | recordDate | temperature |
|----|------------|-------------|
| 1  | 2015-01-01 | 10          |
| 2  | 2015-01-02 | 25          |
| 3  | 2015-01-03 | 20          |
| 4  | 2015-01-04 | 30          |

- Pair `(w1.id = 2, w2.id = 1)`: `DATEDIFF('2015-01-02', '2015-01-01') = 1` and `25 > 10` is TRUE. Select `w1.id` (2).
- Pair `(w1.id = 3, w2.id = 2)`: `DATEDIFF('2015-01-03', '2015-01-02') = 1` but `20 > 25` is FALSE.
- Pair `(w1.id = 4, w2.id = 3)`: `DATEDIFF('2015-01-04', '2015-01-03') = 1` and `30 > 20` is TRUE. Select `w1.id` (4).

# Complexity
- Time complexity: $$O(N^2)$$ in the worst-case depending on the database engine join implementation, where $$N$$ is the number of rows in the `Weather` table, optimized with indexes on `recordDate`.
- Space complexity: $$O(N)$$ for storing intermediate join results and execution context.

# Code
```cpp
# Write your MySQL query statement below
SELECT w1.id
FROM
Weather AS w1
JOIN Weather AS w2
ON DATEDIFF(w1.recordDate, w2.recordDate) = 1 AND w1.temperature > w2.temperature;
```
