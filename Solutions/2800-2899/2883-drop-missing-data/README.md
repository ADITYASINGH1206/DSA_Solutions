# [2883. Drop Missing Data](https://leetcode.com/problems/drop-missing-data/)
**Difficulty:** `Easy` | **Tags:** `Algorithm`

---

## Problem Description
```
DataFrame students
+-------------+--------+
| Column Name | Type   |
+-------------+--------+
| student_id  | int    |
| name        | object |
| age         | int    |
+-------------+--------+
```

There are some rows having missing values in the `name` column.

Write a solution to remove the rows with missing values.

The result format is in the following example.

**Example 1:**

```
Input:
+------------+---------+-----+
| student_id | name    | age |
+------------+---------+-----+
| 32         | Piper   | 5   |
| 217        | None    | 19  |
| 779        | Georgia | 20  |
| 849        | Willow  | 14  |
+------------+---------+-----+
Output:
+------------+---------+-----+
| student_id | name    | age |
+------------+---------+-----+
| 32         | Piper   | 5   |
| 779        | Georgia | 20  | 
| 849        | Willow  | 14  | 
+------------+---------+-----+
Explanation: 
Student with id 217 havs empty value in the name column, so it will be removed.
```

---

## Solution & Editorial
# Intuition
To remove rows with missing values in a specific column, we can utilize the built-in filtering capabilities of the pandas library. The goal is to retain only those rows where the 'name' column contains a valid, non-null entry.

# Approach
1. Access the 'name' column of the input DataFrame `students`.
2. Apply the `.notnull()` method to generate a boolean mask, which identifies rows where the 'name' value is not missing (i.e., not None/NaN).
3. Use this boolean mask to index the original `students` DataFrame, effectively filtering out the rows where the condition is false.

### Visual Trace (Example 1)
| student_id | name | age | .notnull() |
| :--- | :--- | :--- | :--- |
| 32 | Piper | 5 | True |
| 217 | None | 19 | False |
| 779 | Georgia | 20 | True |
| 849 | Willow | 14 | True |

Result: Rows with True are kept.

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the number of rows in the DataFrame, as we must inspect each entry in the 'name' column once.
- Space complexity: $$O(N)$$, as the operation returns a new DataFrame containing the filtered subset of the original data.

# Code
```cpp
import pandas as pd


def dropMissingData(students: pd.DataFrame) -> pd.DataFrame:
    return students[students['name'].notnull()]
```
