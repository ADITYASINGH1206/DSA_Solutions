# [3979. Maximum Valid Pair Sum](https://leetcode.com/problems/maximum-valid-pair-sum/)
**Difficulty:** `Medium` | **Tags:** `array`, `enumeration`

---

## Problem Description
You are given an integer array `nums` of length `n` and an integer `k`.

A pair of indices `(i, j)` is called **valid** if:

* `0 <= i < j < n`
* `j - i >= k`

Return the **maximum** value of `nums[i] + nums[j]` among all valid pairs.

**Example 1:**

**Input:** nums = [1,3,5,2,8], k = 2

**Output:** 13

**Explanation:**

The valid pairs are:

* `(0, 2)`: `nums[0] + nums[2] = 6`
* `(0, 3)`: `nums[0] + nums[3] = 3`
* `(0, 4)`: `nums[0] + nums[4] = 9`
* `(1, 3)`: `nums[1] + nums[3] = 5`
* `(1, 4)`: `nums[1] + nums[4] = 11`
* `(2, 4)`: `nums[2] + nums[4] = 13`

Thus, the answer is 13.​​​​​​​

**Example 2:**

**Input:** nums = [5,1,9], k = 1

**Output:** 14

**Explanation:**

* Since `k = 1`, every pair is valid.
* The maximum value is obtained from a pair `(0, 2)`​​​​​​​, which is `nums[0] + nums[2] = 5 + 9 = 14`.
* Thus, the answer is 14.

**Constraints:**

* `2 <= n == nums.length <= 105`
* `1 <= nums[i] <= 109`
* `1 <= k <= n - 1`

---

## Solution & Editorial
# Intuition
To maximize the sum `nums[i] + nums[j]` under the constraint `j - i >= k`, we observe that for a fixed index `j`, we need to find the maximum value of `nums[i]` where `0 <= i <= j - k`. Since `j` increases monotonically, the range of valid `i` indices expands by one element at each step. This allows us to maintain a running maximum of all elements encountered so far that satisfy the distance constraint.

# Approach
1. Initialize `max_left` to track the maximum value of `nums[i]` for all `i` such that `i <= j - k`.
2. Iterate `r` (representing index `j`) from `k` to `n - 1`.
3. At each step, update `max_left` by comparing it with `nums[r - k]`. This ensures `max_left` always holds the maximum value available for the current `r`.
4. Calculate the potential sum `max_left + nums[r]` and update the global `ans`.

### Visual Trace (Example 1: nums = [1, 3, 5, 2, 8], k = 2)
| r | r-k | nums[r-k] | max_left | nums[r] | Sum | ans |
|---|---|---|---|---|---|---|
| 2 | 0 | 1 | 1 | 5 | 6 | 6 |
| 3 | 1 | 3 | 3 | 2 | 5 | 6 |
| 4 | 2 | 5 | 5 | 8 | 13 | 13 |

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the length of the array. We perform a single pass through the array, and each update operation is $$O(1)$$.
- Space complexity: $$O(1)$$, as we only use a few integer variables to store the running maximum and the result.

# Code
```cpp
class Solution {
public:
    int maxValidPairSum(vector<int>& nums, int k) {
        int n = nums.size();
        if (n <= k) return 0; 
        
        int ans = 0; 
        int max_left = nums[0]; 

        for (int r = k; r < n; r++) {
            max_left = max(max_left, nums[r - k]);
            ans = max(ans, max_left + nums[r]);
        }

        return ans;
    }
};
```
