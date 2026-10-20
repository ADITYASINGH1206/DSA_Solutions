# [2877. Create a DataFrame from List](https://leetcode.com/problems/create-a-dataframe-from-list/)
**Difficulty:** `Easy` | **Tags:** `Algorithm`

---

## Problem Description
Write a solution to **create** a DataFrame from a 2D list called `student_data`. This 2D list contains the IDs and ages of some students.

The DataFrame should have two columns, `student_id` and `age`, and be in the same order as the original 2D list.

The result format is in the following example.

**Example 1:**

```
Input:
student_data:
[
  [1, 15],
  [2, 11],
  [3, 11],
  [4, 20]
]
Output:
+------------+-----+
| student_id | age |
+------------+-----+
| 1          | 15  |
| 2          | 11  |
| 3          | 11  |
| 4          | 20  |
+------------+-----+
Explanation:
A DataFrame was created on top of student_data, with two columns named student_id and age.
```

---

## Solution & Editorial
# Intuition
To construct a pandas DataFrame from a nested list, we leverage the built-in `pd.DataFrame` constructor. This constructor is optimized to map list-of-lists structures directly into tabular formats by specifying column labels.

# Approach
1. Use the `pd.DataFrame` constructor, passing the `student_data` list as the primary data source.
2. Define the `columns` parameter as a list of strings: `['student_id', 'age']` to ensure the resulting DataFrame adheres to the required schema.
3. Return the resulting object.

### Visual Trace (Example 1)
Input: `[[1, 15], [2, 11], [3, 11], [4, 20]]`

| Step | Action | Resulting DataFrame |
| :--- | :--- | :--- |
| 1 | Initialize `pd.DataFrame` | `student_id` | `age` |
| 2 | Map row 0 | 1 | 15 |
| 3 | Map row 1 | 2 | 11 |
| 4 | Map row 2 | 3 | 11 |
| 5 | Map row 3 | 4 | 20 |

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the number of rows in `student_data`. Each element must be visited to populate the DataFrame structure.
- Space complexity: $$O(N)$$, as the DataFrame stores all $$N \times 2$$ elements in memory.

# Code
```cpp
import pandas as pd


def createDataframe(student_data: List[List[int]]) -> pd.DataFrame:
    return pd.DataFrame(student_data, columns=['student_id', 'age'])
```
