# [2859. Sum of Values at Indices With K Set Bits](https://leetcode.com/problems/sum-of-values-at-indices-with-k-set-bits/)
**Difficulty:** `Easy` | **Tags:** `array`, `bit-manipulation`

---

## Problem Description
You are given a **0-indexed** integer array `nums` and an integer `k`.

Return *an integer that denotes the **sum** of elements in* `nums` *whose corresponding **indices** have **exactly*** `k` *set bits in their binary representation.*

The **set bits** in an integer are the `1`'s present when it is written in binary.

* For example, the binary representation of `21` is `10101`, which has `3` set bits.

**Example 1:**

```
Input: nums = [5,10,1,5,2], k = 1
Output: 13
Explanation: The binary representation of the indices are: 
0 = 0002
1 = 0012
2 = 0102
3 = 0112
4 = 1002 
Indices 1, 2, and 4 have k = 1 set bits in their binary representation.
Hence, the answer is nums[1] + nums[2] + nums[4] = 13.
```

**Example 2:**

```
Input: nums = [4,3,2,1], k = 2
Output: 1
Explanation: The binary representation of the indices are:
0 = 002
1 = 012
2 = 102
3 = 112
Only index 3 has k = 2 set bits in its binary representation.
Hence, the answer is nums[3] = 1.
```

**Constraints:**

* `1 <= nums.length <= 1000`
* `1 <= nums[i] <= 105`
* `0 <= k <= 10`

---

## Solution & Editorial
# Intuition
The problem asks us to filter elements based on the number of set bits (1s) in their index. Since the number of set bits can be efficiently calculated using built-in CPU instructions, we can iterate through the array and accumulate values where the popcount of the index matches `k`.

# Approach
1. Initialize an integer `ans` to 0 to store the running sum.
2. Iterate through the array `nums` using a loop index `i` from 0 to `nums.size() - 1`.
3. For each index `i`, use the compiler intrinsic `__builtin_popcount(i)` to count the number of set bits in its binary representation.
4. If the count equals `k`, add `nums[i]` to `ans`.
5. Return `ans` after the loop completes.

### Visual Trace (Example 1: nums = [5, 10, 1, 5, 2], k = 1)
| Index (i) | Binary | Popcount | Match (k=1)? | Action |
| :--- | :--- | :--- | :--- | :--- |
| 0 | 000 | 0 | No | - |
| 1 | 001 | 1 | Yes | ans += 10 (10) |
| 2 | 010 | 1 | Yes | ans += 1 (11) |
| 3 | 011 | 2 | No | - |
| 4 | 100 | 1 | Yes | ans += 2 (13) |

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the length of the array. We perform a single pass, and `__builtin_popcount` operates in constant time $$O(1)$$ on modern hardware.
- Space complexity: $$O(1)$$, as we only use a single integer variable for the accumulator.

# Code
```cpp
class Solution {
public:
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        int ans = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (__builtin_popcount(i) == k) {
                ans += nums[i];
            }
        }
        return ans;
    }
};
```
