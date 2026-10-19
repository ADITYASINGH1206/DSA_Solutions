# [175. Combine Two Tables](https://leetcode.com/problems/combine-two-tables/)
**Difficulty:** `Easy` | **Tags:** `database`

---

## Problem Description
Table: `Person`

```
+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| personId    | int     |
| lastName    | varchar |
| firstName   | varchar |
+-------------+---------+
personId is the primary key (column with unique values) for this table.
This table contains information about the ID of some persons and their first and last names.
```

Table: `Address`

```
+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| addressId   | int     |
| personId    | int     |
| city        | varchar |
| state       | varchar |
+-------------+---------+
addressId is the primary key (column with unique values) for this table.
Each row of this table contains information about the city and state of one person with ID = PersonId.
```

Write a solution to report the first name, last name, city, and state of each person in the `Person` table. If the address of a `personId` is not present in the `Address` table, report `null` instead.

Return the result table in **any order**.

The result format is in the following example.

**Example 1:**

```
Input: 
Person table:
+----------+----------+-----------+
| personId | lastName | firstName |
+----------+----------+-----------+
| 1        | Wang     | Allen     |
| 2        | Alice    | Bob       |
+----------+----------+-----------+
Address table:
+-----------+----------+---------------+------------+
| addressId | personId | city          | state      |
+-----------+----------+---------------+------------+
| 1         | 2        | New York City | New York   |
| 2         | 3        | Leetcode      | California |
+-----------+----------+---------------+------------+
Output: 
+-----------+----------+---------------+----------+
| firstName | lastName | city          | state    |
+-----------+----------+---------------+----------+
| Allen     | Wang     | Null          | Null     |
| Bob       | Alice    | New York City | New York |
+-----------+----------+---------------+----------+
Explanation: 
There is no address in the address table for the personId = 1 so we return null in their city and state.
addressId = 1 contains information about the address of personId = 2.
```

---

## Solution & Editorial
# Intuition
The problem requires combining two tables (`Person` and `Address`) based on their common column `personId` such that all records from the `Person` table are preserved, and missing address matches are reported as `null`. In the provided user submission, Python's Pandas library is used to perform a left outer join.

# Approach
1. Use `pd.merge()` with `how='left'` on the `personId` column to merge the `person` DataFrame with the `address` DataFrame.
2. Filter and project the resulting DataFrame to retain only the required columns: `['firstName', 'lastName', 'city', 'state']`.
3. Return the resulting DataFrame.

# Complexity
- Time complexity: $$O(N + M)$$ where $$N$$ and $$M$$ are the number of rows in the `Person` and `Address` tables respectively, due to hashing and joining operations.
- Space complexity: $$O(N + M)$$ to store the merged DataFrame and resulting columns.

# Code
```cpp
import pandas as pd


def combine_two_tables(person: pd.DataFrame, address: pd.DataFrame) -> pd.DataFrame:
    return pd.merge(left=person, right=address, how="left", on="personId")[
        ["firstName", "lastName", "city", "state"]
    ]
```
