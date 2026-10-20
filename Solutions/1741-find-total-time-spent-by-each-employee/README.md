# [1741. Find Total Time Spent by Each Employee](https://leetcode.com/problems/find-total-time-spent-by-each-employee/)
**Difficulty:** `Easy` | **Tags:** `database`

---

## Problem Description
Table: `Employees`

```
+-------------+------+
| Column Name | Type |
+-------------+------+
| emp_id      | int  |
| event_day   | date |
| in_time     | int  |
| out_time    | int  |
+-------------+------+
(emp_id, event_day, in_time) is the primary key (combinations of columns with unique values) of this table.
The table shows the employees' entries and exits in an office.
event_day is the day at which this event happened, in_time is the minute at which the employee entered the office, and out_time is the minute at which they left the office.
in_time and out_time are between 1 and 1440.
It is guaranteed that no two events on the same day intersect in time, and in_time < out_time.
```

Write a solution to calculate the total time **in minutes** spent by each employee on each day at the office. Note that within one day, an employee can enter and leave more than once. The time spent in the office for a single entry is `out_time - in_time`.

Return the result table in **any order**.

The result format is in the following example.

**Example 1:**

```
Input: 
Employees table:
+--------+------------+---------+----------+
| emp_id | event_day  | in_time | out_time |
+--------+------------+---------+----------+
| 1      | 2020-11-28 | 4       | 32       |
| 1      | 2020-11-28 | 55      | 200      |
| 1      | 2020-12-03 | 1       | 42       |
| 2      | 2020-11-28 | 3       | 33       |
| 2      | 2020-12-09 | 47      | 74       |
+--------+------------+---------+----------+
Output: 
+------------+--------+------------+
| day        | emp_id | total_time |
+------------+--------+------------+
| 2020-11-28 | 1      | 173        |
| 2020-11-28 | 2      | 30         |
| 2020-12-03 | 1      | 41         |
| 2020-12-09 | 2      | 27         |
+------------+--------+------------+
Explanation: 
Employee 1 has three events: two on day 2020-11-28 with a total of (32 - 4) + (200 - 55) = 173, and one on day 2020-12-03 with a total of (42 - 1) = 41.
Employee 2 has two events: one on day 2020-11-28 with a total of (33 - 3) = 30, and one on day 2020-12-09 with a total of (74 - 47) = 27.
```

---

## Solution & Editorial
# Intuition
To calculate the total time spent by each employee per day, we need to aggregate the duration of individual office visits. Since the duration of a single visit is defined as `out_time - in_time`, we can compute this for every row and then group the results by the unique combination of `event_day` and `emp_id`.

# Approach
1. Calculate the duration for each entry by subtracting `in_time` from `out_time`.
2. Use the `GROUP BY` clause on both `event_day` and `emp_id` to partition the data into buckets representing unique employee-day pairs.
3. Apply the `SUM()` aggregate function to the calculated durations within each group to obtain the `total_time`.
4. Rename `event_day` to `day` using an alias to match the required output format.

### Visual Trace (Example 1)
| emp_id | event_day | duration (out - in) |
| :--- | :--- | :--- |
| 1 | 2020-11-28 | 28 |
| 1 | 2020-11-28 | 145 |
| 1 | 2020-12-03 | 41 |
| 2 | 2020-11-28 | 30 |
| 2 | 2020-12-09 | 27 |

**Grouping by (event_day, emp_id):**
- (2020-11-28, 1): 28 + 145 = 173
- (2020-11-28, 2): 30
- (2020-12-03, 1): 41
- (2020-12-09, 2): 27

# Complexity
- Time complexity: $$O(N \log N)$$ where $$N$$ is the number of rows in the `Employees` table, due to the sorting required for the `GROUP BY` operation.
- Space complexity: $$O(N)$$ to store the intermediate grouped results before aggregation.

# Code
```cpp
SELECT 
    event_day AS day, 
    emp_id, 
    SUM(out_time - in_time) AS total_time
FROM Employees
GROUP BY emp_id, event_day;
```
