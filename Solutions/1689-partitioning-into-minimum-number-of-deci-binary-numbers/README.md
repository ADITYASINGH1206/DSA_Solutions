# [1689. Partitioning Into Minimum Number Of Deci-Binary Numbers](https://leetcode.com/problems/partitioning-into-minimum-number-of-deci-binary-numbers/)
**Difficulty:** `Medium` | **Tags:** `string`, `greedy`

---

## Problem Description
A decimal number is called **deci-binary** if each of its digits is either `0` or `1` without any leading zeros. For example, `101` and `1100` are **deci-binary**, while `112` and `3001` are not.

Given a string `n` that represents a positive decimal integer, return *the **minimum** number of positive **deci-binary** numbers needed so that they sum up to* `n`*.*

**Example 1:**

```
Input: n = "32"
Output: 3
Explanation: 10 + 11 + 11 = 32
```

**Example 2:**

```
Input: n = "82734"
Output: 8
```

**Example 3:**

```
Input: n = "27346209830709182346"
Output: 9
```

**Constraints:**

* `1 <= n.length <= 105`
* `n` consists of only digits.
* `n` does not contain any leading zeros and represents a positive integer.

---

## Solution & Editorial
# Intuition
A deci-binary number consists only of 0s and 1s. To represent a digit $d$ in the input string $n$ using a sum of deci-binary numbers, we need at least $d$ such numbers, because each deci-binary number can contribute at most 1 to any specific decimal position. Since we want to minimize the total count, the answer is simply the maximum digit present in the string.

# Approach
1. Initialize a variable `ans` to 0 to track the maximum digit encountered.
2. Iterate through each character `c` in the string `n`.
3. Convert the character to its integer value using `c - '0'`.
4. Update `ans` with the maximum of its current value and the current digit.
5. Return `ans` after the loop completes.

### Visual Trace (Example 1: n = "32")
| Iteration | Character | Digit | `ans` (max) |
|-----------|-----------|-------|-------------|
| 1         | '3'       | 3     | 3           |
| 2         | '2'       | 2     | 3           |

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the length of the string, as we perform a single pass over the input.
- Space complexity: $$O(1)$$, as we only use a single integer variable for tracking the maximum.

# Code
```cpp
class Solution {
public:
    int minPartitions(string n) {
        int ans = 0;
        for (char& c : n) {
            ans = max(ans, c - '0');
        }
        return ans;
    }
};
```
