# [2770. Maximum Number of Jumps to Reach the Last Index](https://leetcode.com/problems/maximum-number-of-jumps-to-reach-the-last-index/)
**Difficulty:** `Medium` | **Tags:** `array`, `dynamic-programming`

---

## Problem Description
You are given a **0-indexed** array `nums` of `n` integers and an integer `target`.

You are initially positioned at index `0`. In one step, you can jump from index `i` to any index `j` such that:

* `0 <= i < j < n`
* `-target <= nums[j] - nums[i] <= target`

Return *the **maximum number of jumps** you can make to reach index* `n - 1`.

If there is no way to reach index `n - 1`, return `-1`.

**Example 1:**

```
Input: nums = [1,3,6,4,1,2], target = 2
Output: 3
Explanation: To go from index 0 to index n - 1 with the maximum number of jumps, you can perform the following jumping sequence:
- Jump from index 0 to index 1. 
- Jump from index 1 to index 3.
- Jump from index 3 to index 5.
It can be proven that there is no other jumping sequence that goes from 0 to n - 1 with more than 3 jumps. Hence, the answer is 3.
```

**Example 2:**

```
Input: nums = [1,3,6,4,1,2], target = 3
Output: 5
Explanation: To go from index 0 to index n - 1 with the maximum number of jumps, you can perform the following jumping sequence:
- Jump from index 0 to index 1.
- Jump from index 1 to index 2.
- Jump from index 2 to index 3.
- Jump from index 3 to index 4.
- Jump from index 4 to index 5.
It can be proven that there is no other jumping sequence that goes from 0 to n - 1 with more than 5 jumps. Hence, the answer is 5.
```

**Example 3:**

```
Input: nums = [1,3,6,4,1,2], target = 0
Output: -1
Explanation: It can be proven that there is no jumping sequence that goes from 0 to n - 1. Hence, the answer is -1.
```

**Constraints:**

* `2 <= nums.length == n <= 1000`
* `-109 <= nums[i] <= 109`
* `0 <= target <= 2 * 109`

---

## Solution & Editorial
# Intuition
To find the maximum number of jumps to reach the last index, we can model this as a longest path problem in a Directed Acyclic Graph (DAG). Since we can only jump from index `i` to `j` where `i < j`, the structure is inherently acyclic, making Dynamic Programming with memoization an ideal approach.

# Approach
1. Define a memoization array `f` of size `n`, initialized to `-1` to represent unvisited states.
2. Use a recursive function `dfs(i)` to calculate the maximum jumps from index `i` to `n-1`.
3. Base Case: If `i == n - 1`, return `0` (we have reached the destination).
4. Recursive Step: For each `j` from `i + 1` to `n - 1`, check if the jump condition `abs(nums[i] - nums[j]) <= target` is satisfied. If it is, recursively call `dfs(j)` and update `f[i]` with `max(f[i], 1 + dfs(j))`.
5. If no valid jump exists from `i`, store a very small negative value to indicate that this path is unreachable.
6. Finally, if the result at `f[0]` is negative, return `-1`; otherwise, return the calculated value.

### Visual Trace (Example 1: nums = [1,3,6,4,1,2], target = 2)
- `dfs(0)` checks indices 1, 2, 3, 4, 5.
- `dfs(1)` (value 3) can jump to 3 (value 4), 4 (value 1), 5 (value 2).
- `dfs(3)` (value 4) can jump to 5 (value 2).
- `dfs(5)` returns 0.
- Path: 0 -> 1 -> 3 -> 5 gives 1 + 1 + 1 = 3.

# Complexity
- Time complexity: $$O(N^2)$$ where $$N$$ is the length of `nums`. Each state `i` is computed once, and for each state, we iterate through all subsequent indices `j`.
- Space complexity: $$O(N)$$ for the memoization array `f` and the recursion stack depth.

# Code
```cpp
class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();
        int f[n];
        memset(f, -1, sizeof(f));
        auto dfs = [&](this auto&& dfs, int i) -> int {
            if (i == n - 1) {
                return 0;
            }
            if (f[i] != -1) {
                return f[i];
            }
            f[i] = -(1 << 30);
            for (int j = i + 1; j < n; ++j) {
                if (abs(nums[i] - nums[j]) <= target) {
                    f[i] = max(f[i], 1 + dfs(j));
                }
            }
            return f[i];
        };
        int ans = dfs(0);
        return ans < 0 ? -1 : ans;
    }
};
```
