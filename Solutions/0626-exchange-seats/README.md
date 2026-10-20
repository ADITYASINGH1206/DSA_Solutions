# [626. Exchange Seats](https://leetcode.com/problems/exchange-seats/)
**Difficulty:** `Medium` | **Tags:** `database`

---

## Problem Description
Table: `Seat`

```
+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| id          | int     |
| student     | varchar |
+-------------+---------+
id is the primary key (unique value) column for this table.
Each row of this table indicates the name and the ID of a student.
The ID sequence always starts from 1 and increments continuously.
```

Write a solution to swap the seat id of every two consecutive students. If the number of students is odd, the id of the last student is not swapped.

Return the result table ordered by `id` **in ascending order**.

The result format is in the following example.

**Example 1:**

```
Input: 
Seat table:
+----+---------+
| id | student |
+----+---------+
| 1  | Abbot   |
| 2  | Doris   |
| 3  | Emerson |
| 4  | Green   |
| 5  | Jeames  |
+----+---------+
Output: 
+----+---------+
| id | student |
+----+---------+
| 1  | Doris   |
| 2  | Abbot   |
| 3  | Green   |
| 4  | Emerson |
| 5  | Jeames  |
+----+---------+
Explanation: 
Note that if the number of students is odd, there is no need to change the last one's seat.
```

---

## Solution & Editorial
# Intuition
The problem requires swapping the seat IDs of every two consecutive students while keeping the last student's ID unchanged if the total number of students is odd. We can achieve this directly in SQL using a `CASE` expression combined with a subquery to check the existence of the next adjacent seat.

# Approach
1. Use a `SELECT` statement on the `Seat` table.
2. Apply a `CASE` expression on the `id` column:
   - Condition 1: If `id % 2 = 1` (odd ID) AND `id + 1` exists in the table (checked via `id + 1 in (select id from Seat)`), return `id + 1` so that odd IDs swap with the next even ID.
   - Condition 2: If `id % 2 = 0` (even ID), return `id - 1` so that even IDs swap with the previous odd ID.
   - Else: Return `id` unchanged (handles the case where an odd ID is the last row and has no subsequent neighbor).
3. Alias the computed column as `id`, select the `student` column, and order the final result set by the new `id` in ascending order.

### Visual Walkthrough (Example 1)

| Original id | student | id % 2 == 1? | id + 1 exists? | CASE evaluates to new id | Output student |
| :---: | :---: | :---: | :---: | :---: | :---: |
| 1 | Abbot | Yes | Yes (2 exists) | 2 | Abbot |
| 2 | Doris | No (Even) | - | 1 | Doris |
| 3 | Emerson | Yes | Yes (4 exists) | 4 | Emerson |
| 4 | Green | No (Even) | - | 3 | Green |
| 5 | Jeames | Yes | No (6 missing) | 5 | Jeames |

# Complexity
- Time complexity: $$O(N \log N)$$ due to the ordering (`order by id`) of the result set of size $$N$$, where $$N$$ is the number of rows in the `Seat` table.
- Space complexity: $$O(N)$$ for storing the temporary result set and handling internal sorting memory buffers.

# Code
```cpp
# Write your MySQL query statement below
select case when id % 2 =1 and id+1 in (select id from Seat) then id+1
            when id % 2 =0 then id-1
            else id
        end as id, student
        from Seat
        order by id;
```
