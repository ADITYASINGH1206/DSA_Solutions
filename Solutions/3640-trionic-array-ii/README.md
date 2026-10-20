# [3640. Trionic Array II](https://leetcode.com/problems/trionic-array-ii/)
**Difficulty:** `Hard` | **Tags:** `array`, `dynamic-programming`

---

## Problem Description
You are given an integer array `nums` of length `n`.

A **trionic subarray** is a contiguous subarray `nums[l...r]` (with `0 <= l < r < n`) for which there exist indices `l < p < q < r` such that:

* `nums[l...p]` is **strictly** increasing,
* `nums[p...q]` is **strictly** decreasing,
* `nums[q...r]` is **strictly** increasing.

Return the **maximum** sum of any trionic subarray in `nums`.

**Example 1:**

**Input:** nums = [0,-2,-1,-3,0,2,-1]

**Output:** -4

**Explanation:**

Pick `l = 1`, `p = 2`, `q = 3`, `r = 5`:

* `nums[l...p] = nums[1...2] = [-2, -1]` is strictly increasing (`-2 < -1`).
* `nums[p...q] = nums[2...3] = [-1, -3]` is strictly decreasing (`-1 > -3`)
* `nums[q...r] = nums[3...5] = [-3, 0, 2]` is strictly increasing (`-3 < 0 < 2`).
* Sum = `(-2) + (-1) + (-3) + 0 + 2 = -4`.

**Example 2:**

**Input:** nums = [1,4,2,7]

**Output:** 14

**Explanation:**

Pick `l = 0`, `p = 1`, `q = 2`, `r = 3`:

* `nums[l...p] = nums[0...1] = [1, 4]` is strictly increasing (`1 < 4`).
* `nums[p...q] = nums[1...2] = [4, 2]` is strictly decreasing (`4 > 2`).
* `nums[q...r] = nums[2...3] = [2, 7]` is strictly increasing (`2 < 7`).
* Sum = `1 + 4 + 2 + 7 = 14`.

**Constraints:**

* `4 <= n = nums.length <= 105`
* `-109 <= nums[i] <= 109`
* It is guaranteed that at least one trionic subarray exists.

---

## Solution & Editorial
# Intuition
To find the maximum sum of a trionic subarray, we observe that the structure is a sequence of three monotonic segments: increasing, decreasing, and increasing. Since we need to maximize the sum, we can greedily identify the boundaries of these segments. The core challenge is that the "peaks" and "valleys" (indices $p$ and $q$) are flexible; we can extend the segments as long as the monotonic property holds, and then optimize the start $l$ and end $r$ to include the maximum possible prefix and suffix sums.

# Approach
1. Iterate through the array to identify the first strictly increasing segment `nums[l...p]`.
2. Once a peak $p$ is found, continue to find the strictly decreasing segment `nums[p...q]`.
3. From $q$, continue to find the strictly increasing segment `nums[q...r]`.
4. To maximize the sum, we calculate the base sum of the core segments and then greedily expand $l$ backwards and $r$ forwards to capture additional positive contributions while maintaining the monotonic constraints.
5. Use a two-pointer approach to slide through the array, resetting the search window to $q$ to ensure we don't miss overlapping potential trionic structures.

### Visual Trace (Example 1: [0, -2, -1, -3, 0, 2, -1])
| Step | Segment | Indices | Sum Contribution |
| :--- | :--- | :--- | :--- |
| 1 | Inc | 1 to 2 | -2 + -1 = -3 |
| 2 | Dec | 2 to 3 | -3 |
| 3 | Inc | 3 to 5 | -3 + 0 + 2 = -1 |
| Total | - | 1 to 5 | -4 |

# Complexity
- Time complexity: $$O(N)$$, where $N$ is the length of the array. Each element is visited a constant number of times by the pointers $i$ and $j$.
- Space complexity: $$O(1)$$, as we only store a few scalar variables for sums and indices.

# Code
```cpp
class Solution {
public:
    long long maxSumTrionic(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        long long ans = LLONG_MIN;
        while (i < n) {
            int l = i;
            i += 1;
            while (i < n && nums[i - 1] < nums[i]) {
                i += 1;
            }
            if (i == l + 1) {
                continue;
            }

            int p = i - 1;
            long long s = nums[p - 1] + nums[p];
            while (i < n && nums[i - 1] > nums[i]) {
                s += nums[i];
                i += 1;
            }
            if (i == p + 1 || i == n || nums[i - 1] == nums[i]) {
                continue;
            }

            int q = i - 1;
            s += nums[i];
            i += 1;
            long long mx = 0, t = 0;
            while (i < n && nums[i - 1] < nums[i]) {
                t += nums[i];
                i += 1;
                mx = max(mx, t);
            }
            s += mx;

            mx = 0, t = 0;
            for (int j = p - 2; j >= l; j--) {
                t += nums[j];
                mx = max(mx, t);
            }
            s += mx;

            ans = max(ans, s);
            i = q;
        }
        return ans;
    }
};
```
