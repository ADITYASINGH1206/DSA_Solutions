# [2235. Add Two Integers](https://leetcode.com/problems/add-two-integers/)
**Difficulty:** `Easy` | **Tags:** `math`

---

## Problem Description
Given two integers `num1` and `num2`, return *the **sum** of the two integers*.

**Example 1:**

```
Input: num1 = 12, num2 = 5
Output: 17
Explanation: num1 is 12, num2 is 5, and their sum is 12 + 5 = 17, so 17 is returned.
```

**Example 2:**

```
Input: num1 = -10, num2 = 4
Output: -6
Explanation: num1 + num2 = -6, so -6 is returned.
```

**Constraints:**

* `-100 <= num1, num2 <= 100`

---

## Solution & Editorial
# Intuition
The problem asks for the sum of two integers. Since the constraints are small (-100 to 100), standard integer addition is sufficient and optimal.

# Approach
1. The function `sum` takes two integers `num1` and `num2` as input.
2. It returns the result of the expression `num1 + num2`.

### Visual Trace (Example 1)
| Step | num1 | num2 | Operation | Result |
| :--- | :--- | :--- | :--- | :--- |
| 1 | 12 | 5 | 12 + 5 | 17 |

# Complexity
- Time complexity: $$O(1)$$. The addition operation is performed in constant time.
- Space complexity: $$O(1)$$. No additional data structures are used.

# Code
```cpp
class Solution {
public:
    int sum(int num1, int num2) {
        return num1+num2;
    }
};
```
