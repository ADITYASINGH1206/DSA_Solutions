# [1732. Find the Highest Altitude](https://leetcode.com/problems/find-the-highest-altitude/)
**Difficulty:** `Easy` | **Tags:** `array`, `prefix-sum`

---

## Problem Description
There is a biker going on a road trip. The road trip consists of `n + 1` points at various altitudes. The biker starts his trip on point `0` with altitude equal `0`.

You are given an integer array `gain` of length `n` where `gain[i]` is the **net gain in altitude** between points `i`​​​​​​ and `i + 1` for all (`0 <= i < n)`. Return *the **highest altitude** of a point.*

**Example 1:**

```
Input: gain = [-5,1,5,0,-7]
Output: 1
Explanation: The altitudes are [0,-5,-4,1,1,-6]. The highest is 1.
```

**Example 2:**

```
Input: gain = [-4,-3,-2,-1,4,3,2]
Output: 0
Explanation: The altitudes are [0,-4,-7,-9,-10,-6,-3,-1]. The highest is 0.
```

**Constraints:**

* `n == gain.length`
* `1 <= n <= 100`
* `-100 <= gain[i] <= 100`

---

## Solution & Editorial
# Intuition
The problem asks us to track the altitude of a biker starting at 0. Since each element in the `gain` array represents the relative change from the previous point, the current altitude is simply the prefix sum of the `gain` array. We need to maintain the maximum value encountered during this cumulative summation.

# Approach
1. Initialize two variables: `x` to track the current altitude (starting at 0) and `ans` to store the maximum altitude found so far (also starting at 0).
2. Iterate through the `gain` array. For each element `gain[i]`, update `x` by adding `gain[i]` to it.
3. After updating `x`, update `ans` using `max(ans, x)` to ensure we capture the highest point reached.
4. Return `ans` after the loop completes.

### Visual Trace (Example 1: gain = [-5, 1, 5, 0, -7])
| Step | gain[i] | x (Current) | ans (Max) |
| :--- | :--- | :--- | :--- |
| Start | - | 0 | 0 |
| 1 | -5 | -5 | 0 |
| 2 | 1 | -4 | 0 |
| 3 | 5 | 1 | 1 |
| 4 | 0 | 1 | 1 |
| 5 | -7 | -6 | 1 |

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the length of the `gain` array, as we perform a single pass over the input.
- Space complexity: $$O(1)$$, as we only use two integer variables regardless of the input size.

# Code
```cpp
class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int x =0, ans =0;
        for (int i=0;i<gain.size();i++){
            x+=gain[i];
            ans =max(ans,x);
        }
        return ans;
    }
};
```
