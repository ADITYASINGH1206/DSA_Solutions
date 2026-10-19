# [1204. Last Person to Fit in the Bus](https://leetcode.com/problems/last-person-to-fit-in-the-bus/)
**Difficulty:** `Medium` | **Tags:** `database`

---

## Problem Description
Table: `Queue`

```
+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| person_id   | int     |
| person_name | varchar |
| weight      | int     |
| turn        | int     |
+-------------+---------+
person_id column contains unique values.
This table has the information about all people waiting for a bus.
The person_id and turn columns will contain all numbers from 1 to n, where n is the number of rows in the table.
turn determines the order of which the people will board the bus, where turn=1 denotes the first person to board and turn=n denotes the last person to board.
weight is the weight of the person in kilograms.
```

There is a queue of people waiting to board a bus. However, the bus has a weight limit of `1000` **kilograms**, so there may be some people who cannot board.

Write a solution to find the `person_name` of the **last person** that can fit on the bus without exceeding the weight limit. The test cases are generated such that the first person does not exceed the weight limit.

**Note** that *only one* person can board the bus at any given turn.

The result format is in the following example.

**Example 1:**

```
Input: 
Queue table:
+-----------+-------------+--------+------+
| person_id | person_name | weight | turn |
+-----------+-------------+--------+------+
| 5         | Alice       | 250    | 1    |
| 4         | Bob         | 175    | 5    |
| 3         | Alex        | 350    | 2    |
| 6         | John Cena   | 400    | 3    |
| 1         | Winston     | 500    | 6    |
| 2         | Marie       | 200    | 4    |
+-----------+-------------+--------+------+
Output: 
+-------------+
| person_name |
+-------------+
| John Cena   |
+-------------+
Explanation: The folowing table is ordered by the turn for simplicity.
+------+----+-----------+--------+--------------+
| Turn | ID | Name      | Weight | Total Weight |
+------+----+-----------+--------+--------------+
| 1    | 5  | Alice     | 250    | 250          |
| 2    | 3  | Alex      | 350    | 600          |
| 3    | 6  | John Cena | 400    | 1000         | (last person to board)
| 4    | 2  | Marie     | 200    | 1200         | (cannot board)
| 5    | 4  | Bob       | 175    | ___          |
| 6    | 1  | Winston   | 500    | ___          |
+------+----+-----------+--------+--------------+
```

---

## Solution & Editorial
# Intuition
To find the last person who can board the bus without exceeding the 1000 kg weight limit, we need to calculate the cumulative weight of people who board up to and including each person's turn. We can efficiently compute this running total using a self-join where each person's row is joined with all preceding or current turns.

# Approach
1. Perform a self-join on the `Queue` table (`a` and `b`) using the condition `a.turn >= b.turn` to associate each person `a` with all people `b` who boarded at an earlier or equal turn.
2. Group the result by `a.person_id` so we can aggregate the weights of all preceding and current boarders for each person.
3. Filter the groups using the `HAVING` clause to keep only those where the cumulative sum of weights (`SUM(b.weight)`) is less than or equal to `1000`.
4. Order the filtered results by `a.turn DESC` to put the latest valid person first, then use `LIMIT 1` to return only the name of the last person to fit.

### Visual Walkthrough (Example 1)

| Turn (a) | Name (a) | Joined Turns (b) | Cumulative Weight | Valid (<= 1000)? |
| :--- | :--- | :--- | :--- | :--- |
| 1 | Alice | 1 | 250 | Yes |
| 2 | Alex | 1, 2 | 600 | Yes |
| 3 | John Cena | 1, 2, 3 | 1000 | Yes (Selected) |
| 4 | Marie | 1, 2, 3, 4 | 1200 | No |
| 5 | Bob | 1..5 | 1375 | No |
| 6 | Winston | 1..6 | 1875 | No |

# Complexity
- Time complexity: $$O(N^2)$$ — The self-join pairs up rows where $N$ is the number of rows in the `Queue` table, leading to quadratic comparisons before grouping and aggregation.
- Space complexity: $$O(1)$$ — Auxiliary space used is constant beyond the database engine's internal execution buffers.

# Code
```cpp
# Write your MySQL query statement below
SELECT a.person_name
FROM
    Queue AS a,
    Queue AS b
WHERE a.turn >= b.turn
GROUP BY a.person_id
HAVING SUM(b.weight) <= 1000
ORDER BY a.turn DESC
LIMIT 1;
```
