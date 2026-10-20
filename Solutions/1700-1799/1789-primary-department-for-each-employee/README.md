# [1789. Primary Department for Each Employee](https://leetcode.com/problems/primary-department-for-each-employee/)
**Difficulty:** `Easy` | **Tags:** `database`

---

## Problem Description
Table: `Employee`

```
+---------------+---------+
| Column Name   |  Type   |
+---------------+---------+
| employee_id   | int     |
| department_id | int     |
| primary_flag  | varchar |
+---------------+---------+
(employee_id, department_id) is the primary key (combination of columns with unique values) for this table.
employee_id is the id of the employee.
department_id is the id of the department to which the employee belongs.
primary_flag is an ENUM (category) of type ('Y', 'N'). If the flag is 'Y', the department is the primary department for the employee. If the flag is 'N', the department is not the primary.
```

Employees can belong to multiple departments. When the employee joins other departments, they need to decide which department is their primary department. Note that when an employee belongs to only one department, their primary column is `'N'`.

Write a solution to report all the employees with their primary department. For employees who belong to one department, report their only department.

Return the result table in **any order**.

The result format is in the following example.

**Example 1:**

```
Input: 
Employee table:
+-------------+---------------+--------------+
| employee_id | department_id | primary_flag |
+-------------+---------------+--------------+
| 1           | 1             | N            |
| 2           | 1             | Y            |
| 2           | 2             | N            |
| 3           | 3             | N            |
| 4           | 2             | N            |
| 4           | 3             | Y            |
| 4           | 4             | N            |
+-------------+---------------+--------------+
Output: 
+-------------+---------------+
| employee_id | department_id |
+-------------+---------------+
| 1           | 1             |
| 2           | 1             |
| 3           | 3             |
| 4           | 3             |
+-------------+---------------+
Explanation: 
- The Primary department for employee 1 is 1.
- The Primary department for employee 2 is 1.
- The Primary department for employee 3 is 3.
- The Primary department for employee 4 is 3.
```

---

## Solution & Editorial
# Intuition
To identify the primary department for each employee, we must handle two distinct cases: employees who have explicitly marked a department as primary ('Y') and employees who belong to only one department (where the flag is 'N' by default). Combining these two sets covers all employees exactly once.

# Approach
1. **Case 1 (Explicit Primary)**: Select all `employee_id` and `department_id` pairs where `primary_flag = 'Y'`. This captures all employees who have explicitly designated a primary department.
2. **Case 2 (Single Department)**: Select all `employee_id` and `department_id` pairs where the employee belongs to exactly one department. We achieve this by grouping by `employee_id` and using `HAVING COUNT(1) = 1`.
3. **Union**: Use the `UNION` operator to combine these two result sets. Since the sets are mutually exclusive (an employee with a 'Y' flag cannot have only one department unless that department is the one marked 'Y'), `UNION` effectively merges the results without duplicates.

### Visual Trace (Example 1)
| employee_id | department_id | primary_flag | Logic Path |
| :--- | :--- | :--- | :--- |
| 1 | 1 | N | Case 2 (Count=1) |
| 2 | 1 | Y | Case 1 (Flag='Y') |
| 3 | 3 | N | Case 2 (Count=1) |
| 4 | 3 | Y | Case 1 (Flag='Y') |

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the number of rows in the `Employee` table. The query performs a full table scan for the `WHERE` clause and a grouping operation, both of which are linear.
- Space complexity: $$O(N)$$ to store the intermediate result sets before the union operation.

# Code
```cpp
# Write your MySQL query statement below
SELECT employee_id, department_id
FROM Employee
WHERE primary_flag = 'Y'
UNION
SELECT employee_id, department_id
FROM Employee
GROUP BY 1
HAVING COUNT(1) = 1;
```
