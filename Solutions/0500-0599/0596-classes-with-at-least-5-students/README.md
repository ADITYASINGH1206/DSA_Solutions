# [596. Classes With at Least 5 Students](https://leetcode.com/problems/classes-with-at-least-5-students/)
**Difficulty:** `Easy` | **Tags:** `database`

---

## Problem Description
Table: `Courses`

```
+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| student     | varchar |
| class       | varchar |
+-------------+---------+
(student, class) is the primary key (combination of columns with unique values) for this table.
Each row of this table indicates the name of a student and the class in which they are enrolled.
```

Write a solution to find all the classes that have **at least five students**.

Return the result table in **any order**.

The result format is in the following example.

**Example 1:**

```
Input: 
Courses table:
+---------+----------+
| student | class    |
+---------+----------+
| A       | Math     |
| B       | English  |
| C       | Math     |
| D       | Biology  |
| E       | Math     |
| F       | Computer |
| G       | Math     |
| H       | Math     |
| I       | Math     |
+---------+----------+
Output: 
+---------+
| class   |
+---------+
| Math    |
+---------+
Explanation: 
- Math has 6 students, so we include it.
- English has 1 student, so we do not include it.
- Biology has 1 student, so we do not include it.
- Computer has 1 student, so we do not include it.
```

---

## Solution & Editorial
# Intuition
The problem requires finding all classes that contain at least 5 distinct students. Since we need to aggregate rows by class and filter based on aggregate counts, the standard SQL grouping and filtering construct (`GROUP BY` and `HAVING`) is the optimal approach.

# Approach
1. Use the `SELECT class` clause to project the class names.
2. Apply `FROM Courses` to query the source table.
3. Group the records by the class column using `GROUP BY 1` (grouping by the first selected column).
4. Filter the grouped results using `HAVING COUNT(1) >= 5` to retain only classes with 5 or more rows/students.

# Complexity
- Time complexity: $$O(N)$$ where $$N$$ is the number of rows in the `Courses` table, as the database engine must scan all rows to group and count them.
- Space complexity: $$O(U)$$ where $$U$$ is the number of unique classes stored in the hash or sorting structures during aggregation.

# Code
```cpp
# Write your MySQL query statement below
SELECT class
FROM Courses
GROUP BY 1
HAVING COUNT(1) >= 5;
```
