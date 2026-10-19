# [620. Not Boring Movies](https://leetcode.com/problems/not-boring-movies/)
**Difficulty:** `Easy` | **Tags:** `database`

---

## Problem Description
Table: `Cinema`

```
+----------------+----------+
| Column Name    | Type     |
+----------------+----------+
| id             | int      |
| movie          | varchar  |
| description    | varchar  |
| rating         | float    |
+----------------+----------+
id is the primary key (column with unique values) for this table.
Each row contains information about the name of a movie, its genre, and its rating.
rating is a 2 decimal places float in the range [0, 10]
```

Write a solution to report the movies with an odd-numbered ID and a description that is not `"boring"`.

Return the result table ordered by `rating` **in descending order**.

The result format is in the following example.

**Example 1:**

```
Input: 
Cinema table:
+----+------------+-------------+--------+
| id | movie      | description | rating |
+----+------------+-------------+--------+
| 1  | War        | great 3D    | 8.9    |
| 2  | Science    | fiction     | 8.5    |
| 3  | irish      | boring      | 6.2    |
| 4  | Ice song   | Fantacy     | 8.6    |
| 5  | House card | Interesting | 9.1    |
+----+------------+-------------+--------+
Output: 
+----+------------+-------------+--------+
| id | movie      | description | rating |
+----+------------+-------------+--------+
| 5  | House card | Interesting | 9.1    |
| 1  | War        | great 3D    | 8.9    |
+----+------------+-------------+--------+
Explanation: 
We have three movies with odd-numbered IDs: 1, 3, and 5. The movie with ID = 3 is boring so we do not include it in the answer.
```

---

## Solution & Editorial
# Intuition
The problem requires filtering a relational table based on parity conditions on the primary key, exclusion criteria on string columns, and sorting the resulting rows by a specific column in descending order. This is a standard declarative data retrieval task best solved using relational database management primitives.

# Approach
1. Select all columns from the `Cinema` table using `SELECT *`.
2. Apply a row-level filter using the `WHERE` clause: ensure that the `description` is not equal to `'boring'` and the `id` is an odd number. The bitwise condition `id & 1 = 1` efficiently tests for odd integers.
3. Sort the filtered output rows in descending order based on the `rating` column (referenced positionally via `ORDER BY 4 DESC`).

### Example 1 Trace
| id | movie | description | rating | id & 1 == 1 | desc != 'boring' | Included | rating DESC Order |
|---|---|---|---|---|---|---|---|
| 1 | War | great 3D | 8.9 | True | True | Yes | 2 |
| 2 | Science | fiction | 8.5 | False | True | No | - |
| 3 | irish | boring | 6.2 | True | False | No | - |
| 4 | Ice song | Fantacy | 8.6 | False | True | No | - |
| 5 | House card | Interesting | 9.1 | True | True | Yes | 1 |

# Complexity
- Time complexity: $$O(N \log N)$$ where $$N$$ is the number of rows in the `Cinema` table. Filtering takes $$O(N)$$ time, while sorting the matching records by rating requires $$O(K \log K)$$ time where $$K \le N$$.
- Space complexity: $$O(K)$$ where $$K$$ is the number of result rows stored or buffered during execution.

# Code
```cpp
# Write your MySQL query statement below
SELECT *
FROM Cinema
WHERE description != 'boring' AND id & 1 = 1
ORDER BY 4 DESC;
```
