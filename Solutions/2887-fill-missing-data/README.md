# [2887. Fill Missing Data](https://leetcode.com/problems/fill-missing-data/)
**Difficulty:** `Easy` | **Tags:** `Algorithm`

---

## Problem Description
```
DataFrame products
+-------------+--------+
| Column Name | Type   |
+-------------+--------+
| name        | object |
| quantity    | int    |
| price       | int    |
+-------------+--------+
```

Write a solution to fill in the missing value as `0` in the `quantity` column.

The result format is in the following example.

```
Example 1:
Input:+-----------------+----------+-------+
| name            | quantity | price |
+-----------------+----------+-------+
| Wristwatch      | None     | 135   |
| WirelessEarbuds | None     | 821   |
| GolfClubs       | 779      | 9319  |
| Printer         | 849      | 3051  |
+-----------------+----------+-------+
Output:
+-----------------+----------+-------+
| name            | quantity | price |
+-----------------+----------+-------+
| Wristwatch      | 0        | 135   |
| WirelessEarbuds | 0        | 821   |
| GolfClubs       | 779      | 9319  |
| Printer         | 849      | 3051  |
+-----------------+----------+-------+
Explanation: 
The quantity for Wristwatch and WirelessEarbuds are filled by 0.
```

---

## Solution & Editorial
# Intuition
In data manipulation tasks involving missing values, the standard approach is to identify the target column and apply a fill operation. Pandas provides a built-in method specifically designed to handle null or missing entries efficiently.

# Approach
1. Access the `quantity` column of the `products` DataFrame.
2. Utilize the `fillna(0)` method, which scans the column for `None` or `NaN` values and replaces them with the integer `0`.
3. Assign the modified series back to the `quantity` column of the original DataFrame.
4. Return the updated DataFrame.

### Visual Trace (Example 1)
| Index | name | quantity (Before) | quantity (After) |
| :--- | :--- | :--- | :--- |
| 0 | Wristwatch | None | 0 |
| 1 | WirelessEarbuds | None | 0 |
| 2 | GolfClubs | 779 | 779 |
| 3 | Printer | 849 | 849 |

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the number of rows in the DataFrame, as we must traverse the `quantity` column once to identify and replace missing values.
- Space complexity: $$O(1)$$, as the operation is performed in-place on the existing column structure.

# Code
```cpp
import pandas as pd


def fillMissingValues(products: pd.DataFrame) -> pd.DataFrame:
    products['quantity'] = products['quantity'].fillna(0)
    return products
```
