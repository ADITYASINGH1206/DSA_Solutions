# [4075. Longest Resilient Subarray I](https://leetcode.com/problems/longest-resilient-subarray-i/)
**Difficulty:** `Medium` | **Tags:** `Algorithm`

---

## Problem Description
You are given an integer array `nums` and an integer `k`.

A subarray is **resilient** if, for **every** position in it, deleting the element at that position leaves the **remaining** elements with a **sum divisible** by `k`.

For a subarray of length 1, the remaining sum is 0, which is divisible by `k`.

Return the length of the **longest resilient subarray**.

**Example 1:**

**Input:** nums = [2,4,6,3], k = 2

**Output:** 3

**Explanation:**

The subarray `[2, 4, 6]` sums to 12. Deleting 2, 4, or 6 leaves a sum of 10, 8, or 6, respectively, each of which is divisible by 2. Therefore, the answer is 3.

**Example 2:**

**Input:** nums = [1,4,7,1], k = 3

**Output:** 4

**Explanation:**

The subarray `[1, 4, 7, 1]` sums to 13. Deleting the first 1, the 4, the 7, or the last 1 leaves a sum of 12, 9, 6, or 12, respectively, each of which is divisible by 3. Therefore, the answer is 4.

**Example 3:**

**Input:** nums = [5,5,4,8], k = 4

**Output:** 2

**Explanation:**

The subarray `[5, 5]` is not resilient, since deleting either 5 leaves a sum of 5, which is not divisible by 4.

The subarray `[4, 8]` sums to 12. Deleting 4 or 8 leaves a sum of 8 or 4, respectively, each of which is divisible by 4. Therefore, the answer is 2.

**Constraints:**

* `1 <= nums.length <= 2500`
* `1 <= nums[i] <= 105`
* `1 <= k <= 105`

---

## Solution & Editorial
# Intuition
For a subarray to be resilient, removing any element $x$ must result in a sum $S - x$ that is divisible by $k$, where $S$ is the total sum of the subarray. This implies $S \equiv x \pmod k$ for every element $x$ in the subarray. Consequently, all elements in a resilient subarray must be congruent to the same value modulo $k$.

# Approach
1. Since all elements in a resilient subarray must have the same remainder modulo $k$, we can partition the array into contiguous segments where each segment contains elements with identical remainders modulo $k$.
2. For each segment of length $L$ where every element $x \equiv m \pmod k$, we check if a subarray of length $j$ (where $1 \le j \le L$) is resilient. The condition for resilience is $(j-1) \cdot m \equiv 0 \pmod k$.
3. We iterate through these segments, find the longest $j$ satisfying the condition, and update the global maximum `ans`.

### Visual Trace (Example 1: nums=[2,4,6,3], k=2)
- Modulo array: `[0, 0, 0, 1]`
- Segment 1: `[2, 4, 6]` (remainder 0), length 3. 
  - Check $j=3$: $(3-1) \cdot 0 = 0 \equiv 0 \pmod 2$. Valid. `ans = 3`.
- Segment 2: `[3]` (remainder 1), length 1.
  - Check $j=1$: $(1-1) \cdot 1 = 0 \equiv 0 \pmod 2$. Valid. `ans` remains 3.

# Complexity
- Time complexity: $$O(N)$$, where $N$ is the length of `nums`. We traverse the array once to identify segments, and the inner loop runs at most $N$ times in total across all segments.
- Space complexity: $$O(1)$$, as we only use a few integer variables for tracking indices and remainders.

# Code
```cpp
class Solution {
public:
    int resilientSubarray(vector<int>& nums, int k) {
        int ans = 1;
        int n = nums.size();
        int i = 0;
        while (i < n) {
            int st = i;
            long long m = nums[i] % k;
            while (i < n && nums[i] % k == m) {
                i++;
            }
            int len = i - st;
            for (int j= len; j>= 1; j--) {
                if (((j- 1) * m) % k == 0) {
                    if (j> ans) {
                        ans = j;
                    }
                    break; 
                }
            }
        }
        
        return ans;
    }
};
```
