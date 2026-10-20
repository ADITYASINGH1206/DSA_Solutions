# [2356. Number of Unique Subjects Taught by Each Teacher](https://leetcode.com/problems/number-of-unique-subjects-taught-by-each-teacher/)
**Difficulty:** `Easy` | **Tags:** `database`

---

## Problem Description
Table: `Teacher`

```
+-------------+------+
| Column Name | Type |
+-------------+------+
| teacher_id  | int  |
| subject_id  | int  |
| dept_id     | int  |
+-------------+------+
(subject_id, dept_id) is the primary key (combinations of columns with unique values) of this table.
Each row in this table indicates that the teacher with teacher_id teaches the subject subject_id in the department dept_id.
```

Write a solution to calculate the number of unique subjects each teacher teaches in the university.

Return the result table in **any order**.

The result format is shown in the following example.

**Example 1:**

```
Input: 
Teacher table:
+------------+------------+---------+
| teacher_id | subject_id | dept_id |
+------------+------------+---------+
| 1          | 2          | 3       |
| 1          | 2          | 4       |
| 1          | 3          | 3       |
| 2          | 1          | 1       |
| 2          | 2          | 1       |
| 2          | 3          | 1       |
| 2          | 4          | 1       |
+------------+------------+---------+
Output:  
+------------+-----+
| teacher_id | cnt |
+------------+-----+
| 1          | 2   |
| 2          | 4   |
+------------+-----+
Explanation: 
Teacher 1:
  - They teach subject 2 in departments 3 and 4.
  - They teach subject 3 in department 3.
Teacher 2:
  - They teach subject 1 in department 1.
  - They teach subject 2 in department 1.
  - They teach subject 3 in department 1.
  - They teach subject 4 in department 1.
```

---

## Solution & Editorial
# Intuition
To determine the number of unique subjects taught by each teacher, we need to group the data by the `teacher_id` and count the distinct `subject_id` values associated with each group. The `DISTINCT` keyword ensures that even if a teacher teaches the same subject in multiple departments, it is only counted once.

# Approach
1. Use the `SELECT` clause to retrieve the `teacher_id`.
2. Apply the `COUNT(DISTINCT subject_id)` aggregate function to calculate the number of unique subjects per teacher.
3. Use the `GROUP BY` clause on `teacher_id` to aggregate the rows for each individual teacher.

### Visual Trace (Example 1)
| teacher_id | subject_id | dept_id | Grouping | Distinct Subjects |
| :--- | :--- | :--- | :--- | :--- |
| 1 | 2 | 3 | Group 1 | {2, 3} -> Count: 2 |
| 1 | 2 | 4 | Group 1 | {2, 3} -> Count: 2 |
| 1 | 3 | 3 | Group 1 | {2, 3} -> Count: 2 |
| 2 | 1 | 1 | Group 2 | {1, 2, 3, 4} -> Count: 4 |
| 2 | 2 | 1 | Group 2 | {1, 2, 3, 4} -> Count: 4 |
| 2 | 3 | 1 | Group 2 | {1, 2, 3, 4} -> Count: 4 |
| 2 | 4 | 1 | Group 2 | {1, 2, 3, 4} -> Count: 4 |

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the number of rows in the `Teacher` table, as we must scan the table once to group and count.
- Space complexity: $$O(N)$$, required to store the intermediate hash map or sorted structure for the `GROUP BY` operation.

# Code
```cpp
# Write your MySQL query statement below
SELECT teacher_id, COUNT(DISTINCT subject_id) AS cnt
FROM Teacher
GROUP BY 1;
```
