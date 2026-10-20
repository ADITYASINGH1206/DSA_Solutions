# [2885. Rename Columns](https://leetcode.com/problems/rename-columns/)
**Difficulty:** `Easy` | **Tags:** `Algorithm`

---

## Problem Description
```
DataFrame students
+-------------+--------+
| Column Name | Type   |
+-------------+--------+
| id          | int    |
| first       | object |
| last        | object |
| age         | int    |
+-------------+--------+
```

Write a solution to rename the columns as follows:

* `id` to `student_id`
* `first` to `first_name`
* `last` to `last_name`
* `age` to `age_in_years`

The result format is in the following example.

```
Example 1:
Input:
+----+---------+----------+-----+
| id | first   | last     | age |
+----+---------+----------+-----+
| 1  | Mason   | King     | 6   |
| 2  | Ava     | Wright   | 7   |
| 3  | Taylor  | Hall     | 16  |
| 4  | Georgia | Thompson | 18  |
| 5  | Thomas  | Moore    | 10  |
+----+---------+----------+-----+
Output:
+------------+------------+-----------+--------------+
| student_id | first_name | last_name | age_in_years |
+------------+------------+-----------+--------------+
| 1          | Mason      | King      | 6            |
| 2          | Ava        | Wright    | 7            |
| 3          | Taylor     | Hall      | 16           |
| 4          | Georgia    | Thompson  | 18           |
| 5          | Thomas     | Moore     | 10           |
+------------+------------+-----------+--------------+
Explanation: 
The column names are changed accordingly.
```

---

## Solution & Editorial
# Intuition
Renaming columns in a Pandas DataFrame is a fundamental operation that maps existing column labels to new identifiers. The `rename` method provides an efficient way to perform this transformation in-place.

# Approach
1. Utilize the `rename` method on the `students` DataFrame.
2. Pass a dictionary to the `columns` parameter where keys represent the original column names (`id`, `first`, `last`, `age`) and values represent the target names (`student_id`, `first_name`, `last_name`, `age_in_years`).
3. Set `inplace=True` to modify the existing DataFrame object directly rather than creating a copy, optimizing memory usage.

### Visual Trace
| Original | Target |
| :--- | :--- |
| id | student_id |
| first | first_name |
| last | last_name |
| age | age_in_years |

# Complexity
- Time complexity: $$O(C)$$, where $$C$$ is the number of columns. Since the number of columns is constant (4), this is effectively $$O(1)$$.
- Space complexity: $$O(1)$$, as the operation is performed in-place without allocating additional data structures proportional to the input size.

# Code
```cpp
import pandas as pd


def renameColumns(students: pd.DataFrame) -> pd.DataFrame:
    students.rename(
        columns={
            'id': 'student_id',
            'first': 'first_name',
            'last': 'last_name',
            'age': 'age_in_years',
        },
        inplace=True,
    )
    return students
```
