# [3950. Exactly One Consecutive Set Bits Pair](https://leetcode.com/problems/exactly-one-consecutive-set-bits-pair/)
**Difficulty:** `Easy` | **Tags:** `bit-manipulation`

---

## Problem Description
You are given an integer `n`.

Return `true` if its binary representation contains **exactly one adjacent pair** of set bits, and `false` otherwise.

**Example 1:**

**Input:** n = 6

**Output:** true

**Explanation:**

* Binary representation of 6 is `110`.
* There is exactly one adjacent pair of set bits (`"11"`). Thus, the answer is `true`​​​​​​​.

**Example 2:**

**Input:** n = 5

**Output:** false

**Explanation:**

* Binary representation of 5 is `101`.
* There is no adjacent pair of set bits. Thus, the answer is `false`​​​​​​​.

**Constraints:**

* `0 <= n <= 105`

---

## Solution & Editorial
# Intuition
To determine if an integer contains exactly one adjacent pair of set bits, we need to traverse its binary representation and track the state of consecutive bits. By maintaining the previous bit's value, we can identify every occurrence of the pattern "11".

# Approach
1. Initialize `count` to 0 to track the number of "11" occurrences and `prev` to 0 to store the bit processed in the previous iteration.
2. Iterate through the binary representation of `n` using a `while` loop that continues as long as `n > 0`.
3. In each iteration, extract the current bit `cur` using `n % 2`.
4. If both `cur` and `prev` are 1, increment `count`.
5. Update `prev` to `cur` and shift `n` right by dividing by 2.
6. After the loop, return `true` if `count == 1`, otherwise return `false`.

### Visual Trace (n = 6)
| Iteration | n | cur | prev | count | Condition (cur==1 && prev==1) |
|-----------|---|-----|------|-------|------------------------------|
| Start     | 6 | -   | 0    | 0     | -                            |
| 1         | 3 | 0   | 0    | 0     | False                        |
| 2         | 1 | 1   | 0    | 0     | False                        |
| 3         | 0 | 1   | 1    | 1     | True                         |

# Complexity
- Time complexity: $$O(\log n)$$, as we process each bit of the integer exactly once.
- Space complexity: $$O(1)$$, as we only use a constant amount of extra space for integer variables.

# Code
```cpp
class Solution {
public:
    bool consecutiveSetBits(int n) {
        int count = 0;
        int prev = 0;
        
        while (n > 0) {
            int cur = n % 2;
            
            if (cur == 1 && prev == 1) {
                count++;
            }
            
            prev = cur;
            n = n / 2;
        }
        
        return count == 1;
    }
};
```
