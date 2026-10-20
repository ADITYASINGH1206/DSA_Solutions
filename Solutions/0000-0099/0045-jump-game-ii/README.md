# [45. Jump Game II](https://leetcode.com/problems/jump-game-ii/)
**Difficulty:** `Medium` | **Tags:** `array`, `dynamic-programming`, `greedy`

---

## Problem Description
You are given a **0-indexed** array of integers `nums` of length `n`. You are initially positioned at index 0.

Each element `nums[i]` represents the maximum length of a forward jump from index `i`. In other words, if you are at index `i`, you can jump to any index `(i + j)` where:

* `0 <= j <= nums[i]` and
* `i + j < n`

Return *the minimum number of jumps to reach index* `n - 1`. The test cases are generated such that you can reach index `n - 1`.

**Example 1:**

```
Input: nums = [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.
```

**Example 2:**

```
Input: nums = [2,3,0,1,4]
Output: 2
```

**Constraints:**

* `1 <= nums.length <= 104`
* `0 <= nums[i] <= 1000`
* It's guaranteed that you can reach `nums[n - 1]`.

---

## Solution & Editorial
# Intuition
The problem asks for the minimum number of jumps to reach the last index of the array. This can be modeled as a Breadth-First Search (BFS) level-order traversal problem. Each "jump" corresponds to a level transition, where our current reachable window is defined by interval `[l, r]`. We want to expand this window greedily by finding the maximum reachable index (`farthest`) from all indices within the current window.

# Approach
1. Initialize pointers `l = 0`, `r = 0`, and the jump counter `ans = 0`.
2. Iterate through the array using a `while` loop as long as the right boundary `r` has not reached the last index (`nums.size() - 1`).
3. Inside the loop, find the maximum reachable index `farthest` by checking every index `i` from `l` to `r` inclusive.
4. Update the new window bounds: set `l = r + 1` and `r = farthest`, then increment the jump counter `ans` by 1.
5. Repeat until the right boundary covers or exceeds the last index, then return `ans`.

### Visual Trace (Example 1: nums = [2, 3, 1, 1, 4])
- Initial: `l = 0, r = 0, ans = 0`
- **Iteration 1:**
  - Scan `i` from `l = 0` to `r = 0`: `farthest = max(0, 0 + nums[0]) = max(0, 2) = 2`.
  - Update window: `l = 0 + 1 = 1`, `r = 2`, `ans = 1`.
- **Iteration 2:**
  - Scan `i` from `l = 1` to `r = 2`: 
    - `i = 1`: `max(2, 1 + nums[1]) = max(2, 1 + 3) = 4`
    - `i = 2`: `max(4, 2 + nums[2]) = max(4, 2 + 1) = 5`
    - `farthest = 4`
  - Update window: `l = 3`, `r = 4`, `ans = 2`.
- Loop terminates because `r (4) >= nums.size() - 1 (4)`.
- Final Answer: `2`.

# Complexity
- Time complexity: $$O(N)$$ — Every element is visited at most twice across all inner loop scans since the pointers `l` and `r` strictly move forward.
- Space complexity: $$O(1)$$ — Only a few primitive variables are used for pointers and bounds.

# Code
```cpp
class Solution {
public:
    int jump(vector<int>& nums) {
        int l = 0, r = 0, ans = 0;

        while (r < nums.size() - 1) {
            int farthest = 0;
            for (int i = l; i <= r; i++) {
                farthest = max(farthest, i + nums[i]);
            }
            l = r + 1;
            r = farthest;
            ans++;
        }

        return ans;        
    }
};
```
