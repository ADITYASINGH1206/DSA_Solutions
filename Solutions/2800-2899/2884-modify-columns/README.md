# [2884. Modify Columns](https://leetcode.com/problems/modify-columns/)
**Difficulty:** `Easy` | **Tags:** `Algorithm`

---

## Problem Description
```
DataFrame employees
+-------------+--------+
| Column Name | Type   |
+-------------+--------+
| name        | object |
| salary      | int    |
+-------------+--------+
```

A company intends to give its employees a pay rise.

Write a solution to **modify** the `salary` column by multiplying each salary by 2.

The result format is in the following example.

**Example 1:**

```
Input:
DataFrame employees
+---------+--------+
| name    | salary |
+---------+--------+
| Jack    | 19666  |
| Piper   | 74754  |
| Mia     | 62509  |
| Ulysses | 54866  |
+---------+--------+
Output:
+---------+--------+
| name    | salary |
+---------+--------+
| Jack    | 39332  |
| Piper   | 149508 |
| Mia     | 125018 |
| Ulysses | 109732 |
+---------+--------+
Explanation:
Every salary has been doubled.
```

---

## Solution & Editorial
# Intuition
To modify a specific column in a pandas DataFrame, we can leverage pandas' vectorized operations. By applying a scalar multiplication directly to the Series object representing the column, we perform the operation efficiently across all rows without explicit iteration.

# Approach
1. Access the 'salary' column of the `employees` DataFrame using the bracket notation `employees['salary']`.
2. Apply the multiplication operator `* 2` to the entire Series. Pandas automatically broadcasts this operation to every element in the column.
3. Assign the resulting Series back to the original 'salary' column to update the DataFrame in place.
4. Return the modified `employees` DataFrame.

### Visual Trace (Example 1)
| Step | Operation | Resulting 'salary' Column |
| :--- | :--- | :--- |
| Initial | - | [19666, 74754, 62509, 54866] |
| Multiply | `* 2` | [39332, 149508, 125018, 109732] |

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the number of rows in the DataFrame. The operation iterates through the column once to perform the multiplication.
- Space complexity: $$O(1)$$, as the modification is performed in-place on the existing DataFrame structure.

# Code
```cpp
import pandas as pd

def modifySalaryColumn(employees: pd.DataFrame) -> pd.DataFrame: 
    employees['salary'] = employees['salary']*2
    return employees
```
