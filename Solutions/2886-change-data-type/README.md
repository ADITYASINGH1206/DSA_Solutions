# [2886. Change Data Type](https://leetcode.com/problems/change-data-type/)
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
| grade       | float  |
+-------------+--------+
```

Write a solution to correct the errors:

The `grade` column is stored as floats, convert it to integers.

The result format is in the following example.

```
Example 1:
Input:
DataFrame students:
+------------+------+-----+-------+
| student_id | name | age | grade |
+------------+------+-----+-------+
| 1          | Ava  | 6   | 73.0  |
| 2          | Kate | 15  | 87.0  |
+------------+------+-----+-------+
Output:
+------------+------+-----+-------+
| student_id | name | age | grade |
+------------+------+-----+-------+
| 1          | Ava  | 6   | 73    |
| 2          | Kate | 15  | 87    |
+------------+------+-----+-------+
Explanation: 
The data types of the column grade is converted to int.
```

---

## Solution & Editorial
# Intuition
In data manipulation tasks using Pandas, changing the data type of a column is a fundamental operation. The `astype()` method provides a direct and efficient way to cast series data into a specified type.

# Approach
1. Access the 'grade' column of the input DataFrame `students`.
2. Apply the `.astype(int)` method to the series. This converts the underlying float values to integers.
3. Assign the transformed series back to the 'grade' column of the original DataFrame.
4. Return the modified DataFrame.

### Visual Trace (Example 1)
| Step | Operation | grade column state |
| :--- | :--- | :--- |
| Initial | Input | [73.0, 87.0] |
| Casting | .astype(int) | [73, 87] |
| Final | Assignment | [73, 87] |

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the number of rows in the DataFrame, as we must iterate through each element in the 'grade' column to perform the type conversion.
- Space complexity: $$O(1)$$ (auxiliary), as the operation is performed in-place on the existing DataFrame structure.

# Code
```cpp
import pandas as pd


def changeDatatype(students: pd.DataFrame) -> pd.DataFrame:
    students['grade'] = students['grade'].astype(int)
    return students
```
