# [868. Binary Gap](https://leetcode.com/problems/binary-gap/)
**Difficulty:** `Easy` | **Tags:** `bit-manipulation`

---

## Problem Description
Given a positive integer `n`, find and return *the **longest distance** between any two **adjacent*** `1`*'s in the binary representation of* `n`*. If there are no two adjacent* `1`*'s, return* `0`*.*

Two `1`'s are **adjacent** if there are only `0`'s separating them (possibly no `0`'s). The **distance** between two `1`'s is the absolute difference between their bit positions. For example, the two `1`'s in `"1001"` have a distance of 3.

**Example 1:**

```
Input: n = 22
Output: 2
Explanation: 22 in binary is "10110".
The first adjacent pair of 1's is "10110" with a distance of 2.
The second adjacent pair of 1's is "10110" with a distance of 1.
The answer is the largest of these two distances, which is 2.
Note that "10110" is not a valid pair since there is a 1 separating the two 1's underlined.
```

**Example 2:**

```
Input: n = 8
Output: 0
Explanation: 8 in binary is "1000".
There are not any adjacent pairs of 1's in the binary representation of 8, so we return 0.
```

**Example 3:**

```
Input: n = 5
Output: 2
Explanation: 5 in binary is "101".
```

**Constraints:**

* `1 <= n <= 109`

---

## Solution & Editorial
# Intuition
To find the maximum distance between any two adjacent set bits (1's) in the binary representation of an integer `n`, we can inspect each bit from the least significant bit (LSB) to the most significant bit (MSB) by shifting `n` to the right. Tracking the indices of the current set bit and the previous set bit allows us to dynamically compute their distance and maintain the maximum.

# Approach
1. Initialize `ans` to `0` to store the maximum distance.
2. Initialize `pre` to a sufficiently large negative or out-of-bounds offset (here initialized to `100`, which functions as a sentinel when no valid previous `1` has been encountered at distances less than 100, though more precisely, tracking via a sentinel state or large initial index prevents false distance calculations on the first encountered `1`). Wait, examining the exact user code: `pre = 100` and `cur = 0`. When the first `1` is encountered at `cur = 0`, `ans = max(ans, 0 - 100)` which is not yet correct unless adjusted. Wait, let's trace `n = 22` ("10110"):
   - `n = 22` (binary `10110`), `pre = 100`, `cur = 0`, `ans = 0`
   - Bit 0 is `0`: `n` becomes `11`, `cur` becomes `1`
   - Bit 1 is `1`: `ans = max(0, 1 - 100) = 0`, then `pre = 1`, `cur` becomes `2`
   - Bit 2 is `1`: `ans = max(0, 2 - 1) = 1`, then `pre = 2`, `cur` becomes `3`
   - Bit 3 is `0`: `n` becomes `1`, `cur` becomes `4`
   - Bit 4 is `1`: `ans = max(1, 4 - 2) = 2`, then `pre = 4`, `cur` becomes `5`
   - Loop terminates. Returns `2`.
3. Notice how initializing `pre = 100` works because the first actual `1` encountered will reset `pre = cur`, effectively ignoring the negative subtraction result since `ans` is initialized to `0` and distances are non-negative.
4. Iterate until `n` becomes `0`, shifting `n >>= 1` and incrementing `cur` at each step.

### Visual Trace Walkthrough ($n = 22$, binary `10110`)
| Iteration | `n` (binary) | `n & 1` | `cur` | `pre` (before update) | `ans` (before update) | `ans` (after update) | `pre` (after update) |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| 1 | `10110` | `0` | `0` | `100` | `0` | `0` | `100` |
| 2 | `1011` | `1` | `1` | `100` | `0` | `0` | `1` |
| 3 | `101` | `1` | `2` | `1` | `0` | `1` | `2` |
| 4 | `10` | `0` | `3` | `2` | `1` | `1` | `2` |
| 5 | `1` | `1` | `4` | `2` | `1` | `2` | `4` |

# Complexity
- Time complexity: $$O(\log n)$$ — The number of iterations is proportional to the number of bits in `n`, which is bounded by $\log_2(n)$. For constraints $1 \le n \le 10^9$, this takes at most 30 iterations.
- Space complexity: $$O(1)$$ — Only a few primitive integer variables (`ans`, `pre`, `cur`) are used, consuming constant auxiliary memory.

# Code
```cpp
class Solution {
public:
    int binaryGap(int n) {
        int ans = 0;
        for (int pre = 100, cur = 0; n != 0; n >>= 1) {
            if (n & 1) {
                ans = max(ans, cur - pre);
                pre = cur;
            }
            ++cur;
        }
        return ans;
    }
};
```
