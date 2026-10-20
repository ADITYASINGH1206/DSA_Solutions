# [2882. Drop Duplicate Rows](https://leetcode.com/problems/drop-duplicate-rows/)
**Difficulty:** `Easy` | **Tags:** `Algorithm`

---

## Problem Description
```
DataFrame customers
+-------------+--------+
| Column Name | Type   |
+-------------+--------+
| customer_id | int    |
| name        | object |
| email       | object |
+-------------+--------+
```

There are some duplicate rows in the DataFrame based on the `email` column.

Write a solution to remove these duplicate rows and keep only the **first** occurrence.

The result format is in the following example.

```
Example 1:
Input:
+-------------+---------+---------------------+
| customer_id | name    | email               |
+-------------+---------+---------------------+
| 1           | Ella    | emily@example.com   |
| 2           | David   | michael@example.com |
| 3           | Zachary | sarah@example.com   |
| 4           | Alice   | john@example.com    |
| 5           | Finn    | john@example.com    |
| 6           | Violet  | alice@example.com   |
+-------------+---------+---------------------+
Output:  
+-------------+---------+---------------------+
| customer_id | name    | email               |
+-------------+---------+---------------------+
| 1           | Ella    | emily@example.com   |
| 2           | David   | michael@example.com |
| 3           | Zachary | sarah@example.com   |
| 4           | Alice   | john@example.com    |
| 6           | Violet  | alice@example.com   |
+-------------+---------+---------------------+
Explanation:
Alic (customer_id = 4) and Finn (customer_id = 5) both use john@example.com, so only the first occurrence of this email is retained.
```

---

## Solution & Editorial
# Intuition
To remove duplicate rows based on a specific column in a pandas DataFrame, the built-in `drop_duplicates` method is the most efficient and idiomatic approach. It allows us to specify the subset of columns to consider for identifying duplicates while preserving the first occurrence by default.

# Approach
1. Use the `drop_duplicates` method on the `customers` DataFrame.
2. Pass the `subset=['email']` argument to explicitly target the column containing potential duplicates.
3. Since the default behavior of `drop_duplicates` is `keep='first'`, it automatically retains the first occurrence of each unique email and discards subsequent ones.

### Visual Trace (Example 1)
| Step | Action | Resulting DataFrame Subset |
| :--- | :--- | :--- |
| 1 | Input | {1: emily, 2: michael, 3: sarah, 4: john, 5: john, 6: alice} |
| 2 | drop_duplicates(subset=['email']) | {1: emily, 2: michael, 3: sarah, 4: john, 6: alice} |

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the number of rows in the DataFrame. The method iterates through the rows once to hash the email values and identify duplicates.
- Space complexity: $$O(N)$$, as the method creates a new DataFrame (or a view) to store the filtered result.

# Code
```cpp
import pandas as pd


def dropDuplicateEmails(customers: pd.DataFrame) -> pd.DataFrame:
    return customers.drop_duplicates(subset=['email'])
```
