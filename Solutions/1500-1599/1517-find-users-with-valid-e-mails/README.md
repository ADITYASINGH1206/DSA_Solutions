# [1517. Find Users With Valid E-Mails](https://leetcode.com/problems/find-users-with-valid-e-mails/)
**Difficulty:** `Easy` | **Tags:** `database`

---

## Problem Description
Table: `Users`

```
+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| user_id       | int     |
| name          | varchar |
| mail          | varchar |
+---------------+---------+
user_id is the primary key (column with unique values) for this table.
This table contains information of the users signed up in a website. Some e-mails are invalid.
```

Write a solution to find the users who have **valid emails**.

A valid e-mail has a prefix name and a domain where:

* **The prefix name** is a string that may contain letters (upper or lower case), digits, underscore `'_'`, period `'.'`, and/or dash `'-'`. The prefix name **must** start with a letter.
* **The domain** must be exactly `'@leetcode.com'` in lowercase.

Return the result table in **any order**.

The result format is in the following example.

**Example 1:**

```
Input: 
Users table:
+---------+-----------+-------------------------+
| user_id | name      | mail                    |
+---------+-----------+-------------------------+
| 1       | Winston   | winston@leetcode.com    |
| 2       | Jonathan  | jonathanisgreat         |
| 3       | Annabelle | bella-@leetcode.com     |
| 4       | Sally     | sally.come@leetcode.com |
| 5       | Marwan    | quarz#2020@leetcode.com |
| 6       | David     | david69@gmail.com       |
| 7       | Shapiro   | .shapo@leetcode.com     |
+---------+-----------+-------------------------+
Output: 
+---------+-----------+-------------------------+
| user_id | name      | mail                    |
+---------+-----------+-------------------------+
| 1       | Winston   | winston@leetcode.com    |
| 3       | Annabelle | bella-@leetcode.com     |
| 4       | Sally     | sally.come@leetcode.com |
+---------+-----------+-------------------------+
Explanation: 
The mail of user 2 does not have a domain.
The mail of user 5 has the # sign which is not allowed.
The mail of user 6 does not have the leetcode domain.
The mail of user 7 starts with a period.
```

---

## Solution & Editorial
# Intuition
The problem requires filtering rows based on a specific pattern for email addresses. Since the constraints involve character-level validation (prefix starting with a letter, specific allowed characters, and a fixed domain), Regular Expressions (Regex) provide the most concise and efficient way to express these rules in SQL.

# Approach
1. Use the `REGEXP` operator to define the pattern for a valid email.
2. The pattern `^[a-zA-Z][a-zA-Z0-9_.-]*@leetcode\.com$` breaks down as follows:
   - `^`: Start of the string.
   - `[a-zA-Z]`: The prefix must start with an uppercase or lowercase letter.
   - `[a-zA-Z0-9_.-]*`: The remainder of the prefix can contain letters, digits, underscores, dots, or dashes.
   - `@leetcode\.com`: The domain must be exactly '@leetcode.com'. The backslash escapes the dot, ensuring it is treated as a literal character.
   - `$`: End of the string.
3. The `LIKE BINARY` clause ensures case-sensitive matching for the domain, enforcing the requirement that the domain must be lowercase.

### Visual Trace (Example 1)
| Mail | Regex Match | Result |
| :--- | :--- | :--- |
| winston@leetcode.com | Matches `^[a-zA-Z]...` | Keep |
| jonathanisgreat | Missing `@` | Drop |
| .shapo@leetcode.com | Starts with `.` (invalid) | Drop |

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the number of rows in the `Users` table. Each row is scanned once to evaluate the regex pattern.
- Space complexity: $$O(1)$$, as we are filtering the existing table without creating auxiliary data structures.

# Code
```cpp
SELECT 
    user_id, 
    name, 
    mail
FROM 
    users
WHERE 
    mail REGEXP '^[a-zA-Z][a-zA-Z0-9_.-]*@leetcode\\.com$' 
    AND mail LIKE BINARY '%@leetcode.com';
```
