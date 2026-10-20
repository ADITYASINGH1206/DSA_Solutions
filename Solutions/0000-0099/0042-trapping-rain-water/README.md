# [42. Trapping Rain Water](https://leetcode.com/problems/trapping-rain-water/)
**Difficulty:** `Hard` | **Tags:** `array`, `two-pointers`, `dynamic-programming`, `stack`, `monotonic-stack`

---

## Problem Description
Given `n` non-negative integers representing an elevation map where the width of each bar is `1`, compute how much water it can trap after raining.

**Example 1:**

```
Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.
```

**Example 2:**

```
Input: height = [4,2,0,3,2,5]
Output: 9
```

**Constraints:**

* `n == height.length`
* `1 <= n <= 2 * 104`
* `0 <= height[i] <= 105`

---

## Solution & Editorial
# Intuition
The amount of water trapped above any bar at index `i` is determined by the minimum of the maximum height to its left and the maximum height to its right, minus its own height. By precalculating prefix and suffix maximum arrays, we can evaluate each bar independently in constant time.

# Code
```cpp
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n == 0) return 0;
        
        vector<int> leftMax(n);
        vector<int> rightMax(n);

        leftMax[0] = height[0];
        for(int i = 1; i < n; i++){
            leftMax[i] = max(leftMax[i - 1], height[i]);
        }

        rightMax[n - 1] = height[n - 1];
        for(int i = n - 2; i >= 0; i--){
            rightMax[i] = max(rightMax[i + 1], height[i]);
        }
        
        int ans = 0;
        for(int i = 0; i < n; i++){
            ans += min(leftMax[i], rightMax[i]) - height[i];
        }
        
        return ans;
    }
};
```
