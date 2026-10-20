# [3285. Find Indices of Stable Mountains](https://leetcode.com/problems/find-indices-of-stable-mountains/)
**Difficulty:** `Easy` | **Tags:** `array`

---

## Problem Description
There are `n` mountains in a row, and each mountain has a height. You are given an integer array `height` where `height[i]` represents the height of mountain `i`, and an integer `threshold`.

A mountain is called **stable** if the mountain just before it (**if it exists**) has a height **strictly greater** than `threshold`. **Note** that mountain 0 is **not** stable.

Return an array containing the indices of *all* **stable** mountains in **any** order.

**Example 1:**

**Input:** height = [1,2,3,4,5], threshold = 2

**Output:** [3,4]

**Explanation:**

* Mountain 3 is stable because `height[2] == 3` is greater than `threshold == 2`.
* Mountain 4 is stable because `height[3] == 4` is greater than `threshold == 2`.

**Example 2:**

**Input:** height = [10,1,10,1,10], threshold = 3

**Output:** [1,3]

**Example 3:**

**Input:** height = [10,1,10,1,10], threshold = 10

**Output:** []

**Constraints:**

* `2 <= n == height.length <= 100`
* `1 <= height[i] <= 100`
* `1 <= threshold <= 100`

---

## Solution & Editorial
# Intuition
The problem defines a "stable" mountain based solely on the height of its immediate predecessor. Since we only need to check the condition `height[i-1] > threshold` for every mountain starting from index 1, a single linear pass is sufficient to identify all such indices.

# Approach
1. Initialize an empty vector `ans` to store the indices of stable mountains.
2. Iterate through the `height` array starting from index `i = 1` up to `n - 1`.
3. For each index `i`, check if the previous mountain's height, `height[i-1]`, is strictly greater than the given `threshold`.
4. If the condition holds, append the current index `i` to `ans`.
5. Return the `ans` vector.

### Visual Trace (Example 1: height = [1, 2, 3, 4, 5], threshold = 2)
| Index (i) | height[i-1] | Condition (height[i-1] > 2) | Action |
| :--- | :--- | :--- | :--- |
| 1 | 1 | 1 > 2 (False) | Skip |
| 2 | 2 | 2 > 2 (False) | Skip |
| 3 | 3 | 3 > 2 (True) | Add 3 |
| 4 | 4 | 4 > 2 (True) | Add 4 |

# Complexity
- Time complexity: $$O(n)$$, where $$n$$ is the number of mountains. We perform a single pass through the array, executing a constant-time comparison at each step.
- Space complexity: $$O(k)$$, where $$k$$ is the number of stable mountains found, to store the result indices. In the worst case, this is $$O(n)$$.

# Code
```cpp
class Solution {
public:
    vector<int> stableMountains(vector<int>& height, int threshold) {
        vector<int> ans;
        for(int i=1;i<height.size();i++){
            if(height[i-1]>threshold){
                ans.push_back(i);
            }
        }
        return ans;
    }
};
```
