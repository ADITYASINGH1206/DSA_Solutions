# [3825. Longest Strictly Increasing Subsequence With Non-Zero Bitwise AND](https://leetcode.com/problems/longest-strictly-increasing-subsequence-with-non-zero-bitwise-and/)
**Difficulty:** `Medium` | **Tags:** `array`, `binary-search`, `bit-manipulation`, `enumeration`

---

## Problem Description
You are given an integer array `nums`.

Return the length of the **longest strictly increasing subsequence** in `nums` whose bitwise **AND** is **non-zero**. If no such **subsequence** exists, return 0.

**Example 1:**

**Input:** nums = [5,4,7]

**Output:** 2

**Explanation:**

One longest strictly increasing subsequence is `[5, 7]`. The bitwise AND is `5 AND 7 = 5`, which is non-zero.

**Example 2:**

**Input:** nums = [2,3,6]

**Output:** 3

**Explanation:**

The longest strictly increasing subsequence is `[2, 3, 6]`. The bitwise AND is `2 AND 3 AND 6 = 2`, which is non-zero.

**Example 3:**

**Input:** nums = [0,1]

**Output:** 1

**Explanation:**

One longest strictly increasing subsequence is `[1]`. The bitwise AND is 1, which is non-zero.

**Constraints:**

* `1 <= nums.length <= 105`
* `0 <= nums[i] <= 109`​​​​​​​

---

## Solution & Editorial
# Intuition
The problem asks for the longest strictly increasing subsequence (LIS) where the bitwise AND of all elements is non-zero. A non-zero bitwise AND implies that there exists at least one bit position $k$ (where $0 \le k \le 30$) such that every element in the subsequence has the $k$-th bit set to 1.

# Approach
1. Since the bitwise AND must be non-zero, we can iterate through each bit position $k$ from 0 to 30.
2. For a fixed bit $k$, we filter the original array `nums` to include only those elements where the $k$-th bit is set.
3. For this filtered subset, we compute the standard LIS using the classic $O(N \log N)$ patience sorting algorithm (using `std::lower_bound` on a `tails` vector).
4. The global answer is the maximum LIS length found across all 31 bit positions.

### Visual Trace (Example 1: nums = [5, 4, 7])
- Bit 0 (Value 1): Filtered [5, 7]. LIS of [5, 7] is 2.
- Bit 1 (Value 2): Filtered []. LIS is 0.
- Bit 2 (Value 4): Filtered [5, 4, 7]. LIS of [5, 7] is 2.
- Result: max(2, 0, 2) = 2.

# Complexity
- Time complexity: $$O(31 \cdot N \log N)$$, where $N$ is the length of the array. We iterate through 31 bits, and for each bit, we perform an $O(N \log N)$ LIS calculation.
- Space complexity: $$O(N)$$, as we store the `tails` vector which can grow up to size $N$ in the worst case.

# Code
```cpp
class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        vector<int> copy = nums;
        int n = copy.size();
        if (n == 0) return 0;
        
        int ans = 0;
        for (int bit = 0; bit <= 30; ++bit) {
            
           vector<int> tails;
            for (int x : copy) {
                if ((x >> bit) & 1) {
                    auto it = lower_bound(tails.begin(), tails.end(), x);
                    
                    if (it == tails.end()) {
                        tails.push_back(x);
                    } else {
                        *it = x;
                    }
                }
            }
            
            ans = max(ans, (int)tails.size());
        }
        
        return ans;
    }
};
```
