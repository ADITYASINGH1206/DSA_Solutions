# [2888. Reshape Data: Concatenate](https://leetcode.com/problems/reshape-data-concatenate/)
**Difficulty:** `Easy` | **Tags:** `Algorithm`

---

## Problem Description
```
DataFrame df1
+-------------+--------+
| Column Name | Type   |
+-------------+--------+
| student_id  | int    |
| name        | object |
| age         | int    |
+-------------+--------+

DataFrame df2
+-------------+--------+
| Column Name | Type   |
+-------------+--------+
| student_id  | int    |
| name        | object |
| age         | int    |
+-------------+--------+
```

Write a solution to concatenate these two DataFrames **vertically** into one DataFrame.

The result format is in the following example.

**Example 1:**

```
Input:
df1
+------------+---------+-----+
| student_id | name    | age |
+------------+---------+-----+
| 1          | Mason   | 8   |
| 2          | Ava     | 6   |
| 3          | Taylor  | 15  |
| 4          | Georgia | 17  |
+------------+---------+-----+
df2
+------------+------+-----+
| student_id | name | age |
+------------+------+-----+
| 5          | Leo  | 7   |
| 6          | Alex | 7   |
+------------+------+-----+
Output:
+------------+---------+-----+
| student_id | name    | age |
+------------+---------+-----+
| 1          | Mason   | 8   |
| 2          | Ava     | 6   |
| 3          | Taylor  | 15  |
| 4          | Georgia | 17  |
| 5          | Leo     | 7   |
| 6          | Alex    | 7   |
+------------+---------+-----+
Explanation:
The two DataFramess are stacked vertically, and their rows are combined.
```

---

## Solution & Editorial
# Intuition
To combine two DataFrames vertically, we need to stack the rows of the second DataFrame onto the first. The `pandas` library provides a highly optimized utility for this specific operation.

# Approach
1. Use the `pd.concat` function, which is designed to concatenate pandas objects along a particular axis.
2. Pass a list containing the two DataFrames `[df1, df2]` to the function.
3. Set `ignore_index=True` to ensure the resulting DataFrame has a continuous index (0 to N+M-1) rather than repeating indices from the original DataFrames.

### Visual Trace (Example 1)
| Step | Operation | Resulting DataFrame Rows |
| :--- | :--- | :--- |
| 1 | Input df1 | [1, 2, 3, 4] |
| 2 | Input df2 | [5, 6] |
| 3 | concat([df1, df2]) | [1, 2, 3, 4, 5, 6] |

# Complexity
- Time complexity: $$O(N + M)$$, where $$N$$ and $$M$$ are the number of rows in `df1` and `df2` respectively. The operation must iterate through all rows to construct the new DataFrame.
- Space complexity: $$O(N + M)$$, as a new DataFrame is created to store the combined data.

# Code
```cpp
import pandas as pd


def concatenateTables(df1: pd.DataFrame, df2: pd.DataFrame) -> pd.DataFrame:
    return pd.concat([df1, df2], ignore_index=True)
```
