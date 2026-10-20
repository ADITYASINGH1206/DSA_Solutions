# [3880. Minimum Absolute Difference Between Two Values](https://leetcode.com/problems/minimum-absolute-difference-between-two-values/)
**Difficulty:** `Easy` | **Tags:** `array`, `enumeration`

---

## Problem Description
You are given an integer array `nums` consisting only of 0, 1, and 2.

A pair of indices `(i, j)` is called **valid** if `nums[i] == 1` and `nums[j] == 2`.

Return the **minimum** absolute difference between `i` and `j` among all valid pairs. If no valid pair exists, return -1.

The absolute difference between indices `i` and `j` is defined as `abs(i - j)`.

**Example 1:**

**Input:** nums = [1,0,0,2,0,1]

**Output:** 2

**Explanation:**

The valid pairs are:

* (0, 3) which has absolute difference of `abs(0 - 3) = 3`.
* (5, 3) which has absolute difference of `abs(5 - 3) = 2`.

Thus, the answer is 2.

**Example 2:**

**Input:** nums = [1,0,1,0]

**Output:** -1

**Explanation:**

There are no valid pairs in the array, thus the answer is -1.

**Constraints:**

* `1 <= nums.length <= 100`
* `0 <= nums[i] <= 2`

---

## Solution & Editorial
# Intuition
To find the minimum absolute difference between indices of 1s and 2s, we need to track the most recent occurrences of both values as we traverse the array. Since we want to minimize $|i - j|$, whenever we encounter a 1 or a 2, we compare its current index with the last seen index of the other target value.

# Approach
1. Initialize two variables, `one` and `two`, to -1 to store the most recent indices of 1 and 2 respectively. Initialize `ans` to `INT_MAX` to track the minimum difference.
2. Iterate through the array `nums` using index `i`:
   - If `nums[i] == 1`, update `one = i`. If `two` has been previously set, calculate `i - two` and update `ans` if this difference is smaller.
   - If `nums[i] == 2`, update `two = i`. If `one` has been previously set, calculate `i - one` and update `ans` if this difference is smaller.
3. After the loop, if `ans` remains `INT_MAX`, return -1; otherwise, return `ans`.

### Visual Trace (Example 1: [1, 0, 0, 2, 0, 1])
| Index | Value | one | two | ans | Update |
|-------|-------|-----|-----|-----|--------|
| 0     | 1     | 0   | -1  | INF | -      |
| 1     | 0     | 0   | -1  | INF | -      |
| 2     | 0     | 0   | -1  | INF | -      |
| 3     | 2     | 0   | 3   | 3   | 3-0=3  |
| 4     | 0     | 0   | 3   | 3   | -      |
| 5     | 1     | 5   | 3   | 2   | 5-3=2  |

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the length of the array, as we perform a single pass through the input.
- Space complexity: $$O(1)$$, as we only use a constant amount of extra space for tracking indices and the minimum difference.

# Code
```cpp
class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums) {
        int one = -1;
        int two = -1;
        int ans = INT_MAX;

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 1) {
                one = i;
                if (two != -1) {
                    ans = min(ans, i - two);
                }
            } else if (nums[i] == 2) {
                two = i;
                if (one != -1) {
                    ans = min(ans, i - one);
                }
            }
        }
        return (ans == INT_MAX) ? -1 : ans;
    }
};
```
