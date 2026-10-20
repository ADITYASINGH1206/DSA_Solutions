# [152. Maximum Product Subarray](https://leetcode.com/problems/maximum-product-subarray/)
**Difficulty:** `Medium` | **Tags:** `array`, `dynamic-programming`

---

## Problem Description
Given an integer array `nums`, find a subarray that has the largest product, and return *the product*.

The test cases are generated so that the answer will fit in a **32-bit** integer.

**Note** that the product of an array with a single element is the value of that element.

**​​​​​​​Example 1:**

```
Input: nums = [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.
```

**Example 2:**

```
Input: nums = [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
```

**Constraints:**

* `1 <= nums.length <= 2 * 104`
* `-10 <= nums[i] <= 10`
* The product of any subarray of `nums` is **guaranteed** to fit in a **32-bit** integer.

---

## Solution & Editorial
# Intuition
The problem asks us to find the contiguous subarray within an array with the largest product. Unlike the maximum subarray sum problem, multiplying by a negative number can flip a minimum product into a maximum product and vice versa. Therefore, at each step, we must track both the maximum (`currentMax`) and the minimum (`currentMin`) product ending at the current position.

# Approach
1. Handle edge cases by checking if `nums` is empty. Initialize `ans` to `INT_MIN`, along with `currentMax` and `currentMin` to `1`.
2. Iterate through each element `n` in `nums`. If the current number `n` is negative, swap `currentMax` and `currentMin` because multiplying by a negative number inverts the sign and flips their relative magnitudes.
3. Update `currentMax` to be the maximum of `n` and `currentMax * n` (either starting a new subarray at `n` or extending the previous maximum product).
4. Update `currentMin` to be the minimum of `n` and `currentMin * n` (either starting a new subarray at `n` or extending the previous minimum product).
5. Update `ans` with the maximum value between `ans` and `currentMax`.
6. Return `ans` after the loop completes.

### Visual Trace (Example 1: nums = [2, 3, -2, 4])

| Step | `n` | Action / State Change | `currentMax` | `currentMin` | `ans` |
| :--- | :--- | :--- | :--- | :--- | :--- |
| Init | - | Start | 1 | 1 | `INT_MIN` |
| 1 | 2 | `n >= 0`, no swap. `max(2, 1*2)`, `min(2, 1*2)` | 2 | 2 | 2 |
| 2 | 3 | `n >= 0`, no swap. `max(3, 2*3)`, `min(3, 2*3)` | 6 | 2 | 6 |
| 3 | -2 | `n < 0`, swap `currentMax` and `currentMin` (both become 2, 6). `max(-2, 2*-2)`, `min(-2, 6*-2)` | -2 | -12 | 6 |
| 4 | 4 | `n >= 0`, no swap. `max(4, -2*4)`, `min(4, -12*4)` | 4 | -48 | 6 |

# Complexity
- Time complexity: $$O(N)$$ — We iterate through the input vector `nums` of size $$N$$ exactly once, performing constant-time arithmetic operations at each step.
- Space complexity: $$O(1)$$ — We only use a few scalar variables (`ans`, `currentMax`, `currentMin`), requiring constant auxiliary memory regardless of input size.

# Code
```cpp
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.empty()) return 0;
        int ans = INT_MIN;
        int currentMax = 1;
        int currentMin = 1;
        for (int n : nums) {
            if (n < 0) {
                swap(currentMax, currentMin);
            }
            currentMax = max(n, currentMax * n);
            currentMin = min(n, currentMin * n);

            ans = max(ans, currentMax);
        }
        
        return ans;
    }
};
```
