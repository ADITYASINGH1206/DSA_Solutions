# [2012. Sum of Beauty in the Array](https://leetcode.com/problems/sum-of-beauty-in-the-array/)
**Difficulty:** `Medium` | **Tags:** `array`

---

## Problem Description
You are given a **0-indexed** integer array `nums`. For each index `i` (`1 <= i <= nums.length - 2`) the **beauty** of `nums[i]` equals:

* `2`, if `nums[j] < nums[i] < nums[k]`, for **all** `0 <= j < i` and for **all** `i < k <= nums.length - 1`.
* `1`, if `nums[i - 1] < nums[i] < nums[i + 1]`, and the previous condition is not satisfied.
* `0`, if none of the previous conditions holds.

Return *the **sum of beauty** of all* `nums[i]` *where* `1 <= i <= nums.length - 2`.

**Example 1:**

```
Input: nums = [1,2,3]
Output: 2
Explanation: For each index i in the range 1 <= i <= 1:
- The beauty of nums[1] equals 2.
```

**Example 2:**

```
Input: nums = [2,4,6,4]
Output: 1
Explanation: For each index i in the range 1 <= i <= 2:
- The beauty of nums[1] equals 1.
- The beauty of nums[2] equals 0.
```

**Example 3:**

```
Input: nums = [3,2,1]
Output: 0
Explanation: For each index i in the range 1 <= i <= 1:
- The beauty of nums[1] equals 0.
```

**Constraints:**

* `3 <= nums.length <= 105`
* `1 <= nums[i] <= 105`

---

## Solution & Editorial
# Intuition
To determine if an element `nums[i]` has a beauty of 2, we must verify that it is strictly greater than all elements to its left and strictly smaller than all elements to its right. A naive check for every index would result in $O(N^2)$ complexity. By precomputing the minimum values to the right and maintaining the maximum value encountered so far from the left, we can reduce the check to $O(1)$ per index.

# Approach
1. **Precompute Suffix Minimums**: Create an array `rightMin` where `rightMin[i]` stores the minimum value in the subarray `nums[i...n-1]`. This allows us to check the condition `nums[i] < all elements to the right` in constant time using `rightMin[i+1]`.
2. **Iterate and Track Prefix Maximums**: Traverse the array from index `1` to `n-2`. Maintain a variable `leftMax` that tracks the maximum value seen in `nums[0...i-1]`.
3. **Evaluate Beauty**:
   - If `nums[i] > leftMax` and `nums[i] < rightMin[i+1]`, the beauty is 2.
   - Else if `nums[i-1] < nums[i] < nums[i+1]`, the beauty is 1.
   - Otherwise, the beauty is 0.
4. **Update State**: After each check, update `leftMax` with `max(leftMax, nums[i])`.

### Visual Trace (Example 2: [2, 4, 6, 4])
| Index | nums[i] | leftMax | rightMin[i+1] | Condition | Beauty |
|-------|---------|---------|---------------|-----------|--------|
| 1     | 4       | 2       | 4             | 2 < 4 < 4 (F) -> 2 < 4 < 6 (T) | 1 |
| 2     | 6       | 4       | 4             | 4 < 6 < 4 (F) -> 4 < 6 < 4 (F) | 0 |

# Complexity
- Time complexity: $$O(N)$$, where $N$ is the length of the array. We perform one pass to build `rightMin` and one pass to calculate the total beauty.
- Space complexity: $$O(N)$$ to store the `rightMin` array.

# Code
```cpp
class Solution {
public:
    int sumOfBeauties(vector<int>& nums) {
        int n = nums.size();
        vector<int> rightMin(n);
        rightMin[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            rightMin[i] = min(rightMin[i + 1], nums[i]);
        }
        int ans = 0;
        int leftMax = nums[0]; 
        for (int i = 1; i < n - 1; i++) {
            if (nums[i] > leftMax && nums[i] < rightMin[i + 1]) {
                ans += 2;
            } 
            else if (nums[i] > nums[i - 1] && nums[i] < nums[i + 1]) {
                ans += 1;
            }
            leftMax = max(leftMax, nums[i]);
        }
        
        return ans;
    }
};
```
