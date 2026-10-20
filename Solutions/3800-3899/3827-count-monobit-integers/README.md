# [3827. Count Monobit Integers](https://leetcode.com/problems/count-monobit-integers/)
**Difficulty:** `Easy` | **Tags:** `bit-manipulation`, `enumeration`

---

## Problem Description
You are given an integer `n`.

An integer is called **Monobit** if all bits in its binary representation are the same.

Return the count of **Monobit** integers in the range `[0, n]` (inclusive).

**Example 1:**

**Input:** n = 1

**Output:** 2

**Explanation:**

* The integers in the range `[0, 1]` have binary representations `"0"` and `"1"`.
* Each representation consists of identical bits. Thus, the answer is 2.

**Example 2:**

**Input:** n = 4

**Output:** 3

**Explanation:**

* The integers in the range `[0, 4]` include binaries `"0"`, `"1"`, `"10"`, `"11"`, and `"100"`.
* Only 0, 1 and 3 satisfy the Monobit condition. Thus, the answer is 3.

**Constraints:**

* `0 <= n <= 1000`

---

## Solution & Editorial
# Intuition
A number is "Monobit" if its binary representation consists entirely of 0s or entirely of 1s. Since 0 is always monobit, we start our count at 1. For 1s, the sequence of monobit integers follows the pattern 1, 3, 7, 15, ..., which are numbers of the form $2^k - 1$.

# Approach
1. Initialize `ans = 1` to account for the number 0.
2. Initialize `num = 1` to represent the first non-zero monobit integer.
3. Use a `while` loop to check if `num <= n`. If it is, increment `ans` and update `num` by shifting it left by 1 and setting the least significant bit to 1 (`(num << 1) | 1`). This effectively generates the next number in the sequence $2^k - 1$.

### Visual Trace (n = 4)
| Iteration | `num` | `ans` | Condition `num <= 4` |
| :--- | :--- | :--- | :--- |
| Start | 1 | 1 | True |
| 1 | 3 | 2 | True |
| 2 | 7 | 3 | False (Loop ends) |

# Complexity
- Time complexity: $$O(\log n)$$ — The loop runs once for each bit in the binary representation of $n$, which is logarithmic relative to the input value.
- Space complexity: $$O(1)$$ — Only a constant amount of extra space is used.

# Code
```cpp
class Solution {
public:
    int countMonobit(int n) {
        int ans = 1;
        int num = 1;
        while (num <= n){
            ans++;
            num = (num<<1) | 1;
        }
        return ans;
    }
};
```
