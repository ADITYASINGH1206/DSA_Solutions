# [1529. Minimum Suffix Flips](https://leetcode.com/problems/minimum-suffix-flips/)
**Difficulty:** `Medium` | **Tags:** `string`, `greedy`

---

## Problem Description
You are given a **0-indexed** binary string `target` of length `n`. You have another binary string `s` of length `n` that is initially set to all zeros. You want to make `s` equal to `target`.

In one operation, you can pick an index `i` where `0 <= i < n` and flip all bits in the **inclusive** range `[i, n - 1]`. Flip means changing `'0'` to `'1'` and `'1'` to `'0'`.

Return *the minimum number of operations needed to make* `s` *equal to* `target`.

**Example 1:**

```
Input: target = "10111"
Output: 3
Explanation: Initially, s = "00000".
Choose index i = 2: "00000" -> "00111"
Choose index i = 0: "00111" -> "11000"
Choose index i = 1: "11000" -> "10111"
We need at least 3 flip operations to form target.
```

**Example 2:**

```
Input: target = "101"
Output: 3
Explanation: Initially, s = "000".
Choose index i = 0: "000" -> "111"
Choose index i = 1: "111" -> "100"
Choose index i = 2: "100" -> "101"
We need at least 3 flip operations to form target.
```

**Example 3:**

```
Input: target = "00000"
Output: 0
Explanation: We do not need any operations since the initial s already equals target.
```

**Constraints:**

* `n == target.length`
* `1 <= n <= 105`
* `target[i]` is either `'0'` or `'1'`.

---

## Solution & Editorial
# Intuition
Since every operation at index `i` flips all bits from `i` to `n-1`, the state of the bit at index `i` is determined by the cumulative number of flips performed at indices `0` through `i`. To transform the initial string of all zeros to the `target`, we only need to perform a flip whenever the required bit at the current position differs from the bit at the previous position.

# Approach
1. Initialize a counter `ans` to 0. This will track the total number of flips.
2. Check the first character of `target`. If `target[0] == '1'`, we must perform at least one flip at index 0 to change the initial '0' to '1'. Increment `ans`.
3. Iterate through the string from index `0` to `n-2`. If `target[i]` is not equal to `target[i+1]`, it implies a transition in the target pattern. This transition necessitates a new flip operation to correct the suffix starting at `i+1`.
4. Return `ans`.

### Visual Trace (target = "10111")
| Index | target[i] | target[i+1] | Change? | ans |
|-------|-----------|-------------|---------|-----|
| Start | - | - | - | 1 (due to '1') |
| 0 | '1' | '0' | Yes | 2 |
| 1 | '0' | '1' | Yes | 3 |
| 2 | '1' | '1' | No | 3 |
| 3 | '1' | '1' | No | 3 |

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the length of the string, as we perform a single linear scan.
- Space complexity: $$O(1)$$, as we only use a single integer variable for the counter.

# Code
```cpp
class Solution {
public:
    int minFlips(string target) {
        int n = target.size();
        int ans = 0;
        if (target[0] == '1') ans++;
        for (int i = 0; i < n - 1; i++) {
            if (target[i] != target[i+1]) {
                ans++;
            }
        }

        return ans;
    }
};
```
