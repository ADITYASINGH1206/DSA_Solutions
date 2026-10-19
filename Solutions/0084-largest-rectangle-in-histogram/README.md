# [84. Largest Rectangle in Histogram](https://leetcode.com/problems/largest-rectangle-in-histogram/)
**Difficulty:** `Hard` | **Tags:** `array`, `stack`, `monotonic-stack`, `range-minimum-maximum-query`

---

## Problem Description
Given an array of integers `heights` representing the histogram's bar height where the width of each bar is `1`, return *the area of the largest rectangle in the histogram*.

**Example 1:**

```
Input: heights = [2,1,5,6,2,3]
Output: 10
Explanation: The above is a histogram where width of each bar is 1.
The largest rectangle is shown in the red area, which has an area = 10 units.
```

**Example 2:**

```
Input: heights = [2,4]
Output: 4
```

**Constraints:**

* `1 <= heights.length <= 105`
* `0 <= heights[i] <= 104`

---

## Solution & Editorial
# Intuition
To find the largest rectangle in a histogram, we need to determine the maximum possible area with each bar acting as the shortest bar (height determinant). For every bar at index `i`, we can expand outwards to the left and right as long as the neighboring bars are taller or equal. This translates to finding the nearest smaller bar to the left and the nearest smaller bar to the right for each element.

# Approach
1. Maintain two auxiliary arrays, `left` and `right`, of size `n` to store the indices of the previous smaller element and the next smaller element for each bar respectively.
2. Use a monotonic increasing stack `stk` to compute the `left` boundaries in a single left-to-right pass. For each element `i`, pop elements from the stack while they are greater than or equal to `heights[i]`. If the stack becomes empty, the left boundary is `-1`, else it is the index at `stk.top()`.
3. Clear the stack and perform a right-to-left pass to compute the `right` boundaries. For each element `i`, pop elements greater than or equal to `heights[i]`. If the stack is empty, the right boundary is `n`, else it is `stk.top()`.
4. Iterate through all bars, compute the valid width as `right[i] - left[i] - 1`, compute the area as `width * heights[i]`, and track the maximum area found in `ans`.

### Visual Trace Walkthrough (Example 1: heights = [2, 1, 5, 6, 2, 3])
- **Left Pass (Previous Smaller Element indices):**
  - `i = 0 (height 2)`: stk empty $ightarrow$ `left[0] = -1`, push `0`. Stack: `[0]`
  - `i = 1 (height 1)`: pop `0` ($2 
ot< 1$), stk empty $ightarrow$ `left[1] = -1`, push `1`. Stack: `[1]`
  - `i = 2 (height 5)`: top `1` ($1 < 5$) $ightarrow$ `left[2] = 1`, push `2`. Stack: `[1, 2]`
  - `i = 3 (height 6)`: top `2` ($5 < 6$) $ightarrow$ `left[3] = 2`, push `3`. Stack: `[1, 2, 3]`
  - `i = 4 (height 2)`: pop `3` ($6 
ot< 2$), pop `2` ($5 
ot< 2$), top `1` ($1 < 2$) $ightarrow$ `left[4] = 1`, push `4`. Stack: `[1, 4]`
  - `i = 5 (height 3)`: top `4` ($2 < 3$) $ightarrow$ `left[5] = 4`, push `5`. Stack: `[1, 4, 5]`
  - Result `left` array: `[-1, -1, 1, 2, 1, 4]`

- **Right Pass (Next Smaller Element indices):**
  - Result `right` array: `[1, 6, 4, 4, 6, 6]`

- **Max Area Calculation:**
  - `i = 0`: width = `1 - (-1) - 1 = 1`, area = `1 * 2 = 2`
  - `i = 1`: width = `6 - (-1) - 1 = 6`, area = `6 * 1 = 6`
  - `i = 2`: width = `4 - 1 - 1 = 2`, area = `2 * 5 = 10` (Maximum)
  - `i = 3`: width = `4 - 2 - 1 = 1`, area = `1 * 6 = 6`
  - `i = 4`: width = `6 - 1 - 1 = 4`, area = `4 * 2 = 8`
  - `i = 5`: width = `6 - 4 - 1 = 1`, area = `1 * 3 = 3`
  - Final Answer: `10`

# Complexity
- Time complexity: $$O(N)$$ — Each element is pushed and popped from the stack at most once during the left pass and once during the right pass. The final area computation takes linear time, resulting in an optimal overall time complexity of $$O(N)$$.
- Space complexity: $$O(N)$$ — Auxiliary storage is required for the `left` array, `right` array, and the monotonic stack, each taking up to $$O(N)$$ space.

# Code
```cpp
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> left(n),right(n);
        stack<int> stk;

        for(int i = 0;i<n;i++){
            while(!stk.empty() && heights[stk.top()] >= heights[i]) stk.pop();
            left[i] = stk.empty() ? -1 : stk.top();
            stk.push(i);
        }

        while(!stk.empty()) stk.pop();

        for(int i = n-1;i>-1;i--){
            while(!stk.empty() && heights[stk.top()] >= heights[i]) stk.pop();
            right[i] = stk.empty() ? n : stk.top();
            stk.push(i);
        }

        int ans = 0;
        for(int i = 0;i<n;i++){
            int width = right[i]- left[i] - 1;
            int area = width * heights[i];
            ans = max(ans,area);
        }

        return ans;
    }
};
```
