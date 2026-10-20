# [3840. House Robber V](https://leetcode.com/problems/house-robber-v/)
**Difficulty:** `Medium` | **Tags:** `array`, `dynamic-programming`

---

## Problem Description
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed and is protected by a security system with a color code.

You are given two integer arrays `nums` and `colors`, both of length `n`, where `nums[i]` is the amount of money in the `ith` house and `colors[i]` is the color code of that house.

You **cannot rob two adjacent** houses if they share the **same color** code.

Return the **maximum** amount of money you can rob.

**Example 1:**

**Input:** nums = [1,4,3,5], colors = [1,1,2,2]

**Output:** 9

**Explanation:**

* Choose houses `i = 1` with `nums[1] = 4` and `i = 3` with `nums[3] = 5` because they are non-adjacent.
* Thus, the total amount robbed is `4 + 5 = 9`.

**Example 2:**

**Input:** nums = [3,1,2,4], colors = [2,3,2,2]

**Output:** 8

**Explanation:**

* Choose houses `i = 0` with `nums[0] = 3`, `i = 1` with `nums[1] = 1`, and `i = 3` with `nums[3] = 4`.
* This selection is valid because houses `i = 0` and `i = 1` have different colors, and house `i = 3` is non-adjacent to `i = 1`.
* Thus, the total amount robbed is `3 + 1 + 4 = 8`.

**Example 3:**

**Input:** nums = [10,1,3,9], colors = [1,1,1,2]

**Output:** 22

**Explanation:**

* Choose houses `i = 0` with `nums[0] = 10`, `i = 2` with `nums[2] = 3`, and `i = 3` with `nums[3] = 9`.
* This selection is valid because houses `i = 0` and `i = 2` are non-adjacent, and houses `i = 2` and `i = 3` have different colors.
* Thus, the total amount robbed is `10 + 3 + 9 = 22`.

**Constraints:**

* `1 <= n == nums.length == colors.length <= 105`
* `1 <= nums[i], colors[i] <= 105`

---

## Solution & Editorial
# Intuition
The problem is a variation of the classic House Robber problem with an added constraint: we cannot rob two adjacent houses if they share the same color. This implies that if we decide to rob house `i`, we must consider the state of the previous house `i-1`. If `colors[i] == colors[i-1]`, we cannot rob `i-1`, effectively forcing us to skip it. If `colors[i] != colors[i-1]`, we can potentially rob both, provided they are not adjacent in the standard sense.

# Approach
1. We maintain two variables: `ans` (the maximum money robbed up to the current house) and `prev` (the maximum money robbed up to the house before the previous one, or the previous state if we skipped the immediate neighbor).
2. Iterate through the houses starting from index 1:
   - If `colors[i] == colors[i-1]`: We cannot rob both. The new `ans` becomes `max(ans, prev + nums[i])`, where `prev` represents the best we could do before the current house's predecessor.
   - If `colors[i] != colors[i-1]`: We can safely add `nums[i]` to the current `ans`. We update `prev` to the old `ans` and update `ans` to `ans + nums[i]`.
3. Update the `cls` tracker to the current color.

### Visual Trace (Example 1: nums=[1,4,3,5], colors=[1,1,2,2])
| i | nums[i] | colors[i] | ans | prev | Action |
|---|---|---|---|---|---|
| 0 | 1 | 1 | 1 | 0 | Init |
| 1 | 4 | 1 | 4 | 1 | Same color: max(1, 0+4) = 4 |
| 2 | 3 | 2 | 7 | 4 | Diff color: 4+3 = 7 |
| 3 | 5 | 2 | 9 | 7 | Same color: max(7, 4+5) = 9 |

# Complexity
- Time complexity: $$O(N)$$ where $$N$$ is the number of houses. We perform a single pass through the input arrays.
- Space complexity: $$O(1)$$ as we only use a few variables to track the state, regardless of input size.

# Code
```cpp
class Solution {
public:
    long long rob(vector<int>& nums, vector<int>& colors) {
        long long ans = nums[0];  
        long long prev = 0;       
        int cls = colors[0];
        int n = nums.size();
        
        for(int i = 1; i < n; i++) {
            if(colors[i] == cls) {
                long long temp = ans;
                ans = max(ans, prev + nums[i]);
                prev = temp; 
            }
            else {
                prev = ans; 
                ans += nums[i];
                cls = colors[i];
            }
        }
        return ans;
    }
};
```
