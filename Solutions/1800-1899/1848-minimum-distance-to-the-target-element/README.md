# [1848. Minimum Distance to the Target Element](https://leetcode.com/problems/minimum-distance-to-the-target-element/)
**Difficulty:** `Easy` | **Tags:** `array`

---

## Problem Description
Given an integer array `nums` **(0-indexed)** and two integers `target` and `start`, find an index `i` such that `nums[i] == target` and `abs(i - start)` is **minimized**. Note that `abs(x)` is the absolute value of `x`.

Return `abs(i - start)`.

It is **guaranteed** that `target` exists in `nums`.

**Example 1:**

```
Input: nums = [1,2,3,4,5], target = 5, start = 3
Output: 1
Explanation: nums[4] = 5 is the only value equal to target, so the answer is abs(4 - 3) = 1.
```

**Example 2:**

```
Input: nums = [1], target = 1, start = 0
Output: 0
Explanation: nums[0] = 1 is the only value equal to target, so the answer is abs(0 - 0) = 0.
```

**Example 3:**

```
Input: nums = [1,1,1,1,1,1,1,1,1,1], target = 1, start = 0
Output: 0
Explanation: Every value of nums is 1, but nums[0] minimizes abs(i - start), which is abs(0 - 0) = 0.
```

**Constraints:**

* `1 <= nums.length <= 1000`
* `1 <= nums[i] <= 104`
* `0 <= start < nums.length`
* `target` is in `nums`.

---

## Solution & Editorial
# Intuition
To minimize the absolute difference `abs(i - start)` for all indices `i` where `nums[i] == target`, we simply need to iterate through the array and track the minimum distance found so far.

# Approach
1. Initialize a variable `ans` with a value larger than any possible distance (e.g., the size of the array `n`).
2. Iterate through the array `nums` using an index `i` from `0` to `n-1`.
3. Whenever `nums[i]` matches the `target`, calculate the absolute difference `abs(i - start)`.
4. Update `ans` with the minimum of its current value and the newly calculated distance.
5. Return `ans` after the loop completes.

### Visual Trace (Example 1: nums = [1,2,3,4,5], target = 5, start = 3)
| i | nums[i] | Match? | abs(i - start) | ans (min) |
|---|---|---|---|---|
| 0 | 1 | No | - | 5 |
| 1 | 2 | No | - | 5 |
| 2 | 3 | No | - | 5 |
| 3 | 4 | No | - | 5 |
| 4 | 5 | Yes | abs(4-3)=1 | 1 |

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the length of the array. We perform a single pass through the input vector.
- Space complexity: $$O(1)$$, as we only use a constant amount of extra space for variables `n`, `ans`, and `i`.

# Code
```cpp
class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int n = nums.size();
        int ans = n;
        for (int i = 0; i < n; i++) {
            if (nums[i] == target) {
                ans = min(ans, abs(i - start));
            }
        }
        return ans;
    }
};
```
