# [1280. Students and Examinations](https://leetcode.com/problems/students-and-examinations/)
**Difficulty:** `Easy` | **Tags:** `database`

---

## Problem Description
Table: `Students`

```
+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| student_id    | int     |
| student_name  | varchar |
+---------------+---------+
student_id is the primary key (column with unique values) for this table.
Each row of this table contains the ID and the name of one student in the school.
```

Table: `Subjects`

```
+--------------+---------+
| Column Name  | Type    |
+--------------+---------+
| subject_name | varchar |
+--------------+---------+
subject_name is the primary key (column with unique values) for this table.
Each row of this table contains the name of one subject in the school.
```

Table: `Examinations`

```
+--------------+---------+
| Column Name  | Type    |
+--------------+---------+
| student_id   | int     |
| subject_name | varchar |
+--------------+---------+
There is no primary key (column with unique values) for this table. It may contain duplicates.
Each student from the Students table takes every course from the Subjects table.
Each row of this table indicates that a student with ID student_id attended the exam of subject_name.
```

Write a solution to find the number of times each student attended each exam.

Return the result table ordered by `student_id` and `subject_name`.

The result format is in the following example.

**Example 1:**

```
Input: 
Students table:
+------------+--------------+
| student_id | student_name |
+------------+--------------+
| 1          | Alice        |
| 2          | Bob          |
| 13         | John         |
| 6          | Alex         |
+------------+--------------+
Subjects table:
+--------------+
| subject_name |
+--------------+
| Math         |
| Physics      |
| Programming  |
+--------------+
Examinations table:
+------------+--------------+
| student_id | subject_name |
+------------+--------------+
| 1          | Math         |
| 1          | Physics      |
| 1          | Programming  |
| 2          | Programming  |
| 1          | Physics      |
| 1          | Math         |
| 13         | Math         |
| 13         | Programming  |
| 13         | Physics      |
| 2          | Math         |
| 1          | Math         |
+------------+--------------+
Output: 
+------------+--------------+--------------+----------------+
| student_id | student_name | subject_name | attended_exams |
+------------+--------------+--------------+----------------+
| 1          | Alice        | Math         | 3              |
| 1          | Alice        | Physics      | 2              |
| 1          | Alice        | Programming  | 1              |
| 2          | Bob          | Math         | 1              |
| 2          | Bob          | Physics      | 0              |
| 2          | Bob          | Programming  | 1              |
| 6          | Alex         | Math         | 0              |
| 6          | Alex         | Physics      | 0              |
| 6          | Alex         | Programming  | 0              |
| 13         | John         | Math         | 1              |
| 13         | John         | Physics      | 1              |
| 13         | John         | Programming  | 1              |
+------------+--------------+--------------+----------------+
Explanation: 
The result table should contain all students and all subjects.
Alice attended the Math exam 3 times, the Physics exam 2 times, and the Programming exam 1 time.
Bob attended the Math exam 1 time, the Programming exam 1 time, and did not attend the Physics exam.
Alex did not attend any exams.
John attended the Math exam 1 time, the Physics exam 1 time, and the Programming exam 1 time.
```

---

## Solution & Editorial
# Intuition
To find the number of times every student attended each exam, including cases where a student attended zero times, we need a complete combination of all students and all subjects. This is achieved via a cross join or a full outer combination, followed by a left join with the examinations table and aggregation.

# Approach
1. Generate the cartesian product between `Students` and `Subjects` by performing a cross join (`JOIN Subjects` without explicit condition on `Students` creates the full student-subject matrix).
2. Perform a `LEFT JOIN` with the `Examinations` table matching both `student_id` and `subject_name` using `USING (student_id, subject_name)`.
3. Group the result by `student_id` (and implicitly `student_name`) and `subject_name` to aggregate attendance counts.
4. Use `COUNT(e.student_id)` to count matching examination rows; this correctly evaluates to `0` for combinations that never occurred due to the `LEFT JOIN`.
5. Order the final output by `student_id` and `subject_name` as required.

# Complexity
- Time complexity: $$O(N \times M + K)$$, where $$N$$ is the number of students, $$M$$ is the number of subjects, and $$K$$ is the number of rows in the examinations table. The cross join generates $$N \times M$$ rows, and aggregation processes these rows alongside the join.
- Space complexity: $$O(N \times M)$$ for storing the intermediate joined table and result set.

# Code
```cpp
# Write your MySQL query statement below
SELECT student_id, student_name, subject_name, COUNT(e.student_id) AS attended_exams
FROM
Students
JOIN Subjects
LEFT JOIN Examinations AS e USING (student_id, subject_name)
GROUP BY 1, 3
ORDER BY 1, 3;
```
