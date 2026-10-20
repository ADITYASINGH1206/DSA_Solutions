# [3660. Jump Game IX](https://leetcode.com/problems/jump-game-ix/)
**Difficulty:** `Medium` | **Tags:** `array`, `dynamic-programming`

---

## Problem Description
You are given an integer array `nums`.

From any index `i`, you can jump to another index `j` under the following rules:

* Jump to index `j` where `j > i` is allowed only if `nums[j] < nums[i]`.
* Jump to index `j` where `j < i` is allowed only if `nums[j] > nums[i]`.

For each index `i`, find the **maximum** **value** in `nums` that can be reached by following **any** sequence of valid jumps starting at `i`.

Return an array `ans` where `ans[i]` is the **maximum** **value** reachable starting from index `i`.

**Example 1:**

**Input:** nums = [2,1,3]

**Output:** [2,2,3]

**Explanation:**

* For `i = 0`: No jump increases the value.
* For `i = 1`: Jump to `j = 0` as `nums[j] = 2` is greater than `nums[i]`.
* For `i = 2`: Since `nums[2] = 3` is the maximum value in `nums`, no jump increases the value.

Thus, `ans = [2, 2, 3]`.

**Example 2:**

**Input:** nums = [2,3,1]

**Output:** [3,3,3]

**Explanation:**

* For `i = 0`: Jump forward to `j = 2` as `nums[j] = 1` is less than `nums[i] = 2`, then from `i = 2` jump to `j = 1` as `nums[j] = 3` is greater than `nums[2]`.
* For `i = 1`: Since `nums[1] = 3` is the maximum value in `nums`, no jump increases the value.
* For `i = 2`: Jump to `j = 1` as `nums[j] = 3` is greater than `nums[2] = 1`.

Thus, `ans = [3, 3, 3]`.

**Constraints:**

* `1 <= nums.length <= 105`
* `1 <= nums[i] <= 109​​​​​​​`

---

## Solution & Editorial
# Intuition
The problem asks for the maximum reachable value from each index under specific jump constraints. Notice that the jump rules allow us to move to a smaller value if we move forward, or a larger value if we move backward. This implies that if we can reach a value $V$ from index $i$, we can effectively "climb" to the global maximum reachable from that component. By analyzing the prefix maximums and suffix minimums, we can determine the reachability of the maximum value for each index.

# Approach
1. Precompute `preMax[i]`, which stores the maximum value in the range `[0, i]`. This represents the best value we can "reach" if we are forced to move backward.
2. Iterate backwards from `n-1` to `0` to maintain a `sufMin` variable, which tracks the minimum value encountered in the range `[i, n-1]`. 
3. For each index `i`, if `preMax[i]` is greater than `sufMin`, it implies that there exists a path to a larger value (specifically, the maximum reachable from the right side). Otherwise, the best we can achieve is the current `preMax[i]`.

### Visual Trace (Example 2: [2, 3, 1])
| Index | nums[i] | preMax[i] | sufMin (at step) | ans[i] |
|-------|---------|-----------|------------------|--------|
| 0     | 2       | 2         | 1                | 3      |
| 1     | 3       | 3         | 1                | 3      |
| 2     | 1       | 3         | 1                | 3      |

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the length of `nums`. We perform two linear passes over the array.
- Space complexity: $$O(N)$$ to store the `preMax` array and the result `ans`.

# Code
```cpp
class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        vector<int> preMax(n, nums[0]);
        for (int i = 1; i < n; ++i) {
            preMax[i] = max(preMax[i - 1], nums[i]);
        }
        int sufMin = 1 << 30;
        for (int i = n - 1; i >= 0; --i) {
            ans[i] = preMax[i] > sufMin ? ans[i + 1] : preMax[i];
            sufMin = min(sufMin, nums[i]);
        }
        return ans;
    }
};
```
