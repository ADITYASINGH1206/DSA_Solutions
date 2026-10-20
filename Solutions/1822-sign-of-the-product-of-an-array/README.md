# [1822. Sign of the Product of an Array](https://leetcode.com/problems/sign-of-the-product-of-an-array/)
**Difficulty:** `Easy` | **Tags:** `array`, `math`

---

## Problem Description
Implement a function `signFunc(x)` that returns:

* `1` if `x` is positive.
* `-1` if `x` is negative.
* `0` if `x` is equal to `0`.

You are given an integer array `nums`. Let `product` be the product of all values in the array `nums`.

Return `signFunc(product)`.

**Example 1:**

```
Input: nums = [-1,-2,-3,-4,3,2,1]
Output: 1
Explanation: The product of all values in the array is 144, and signFunc(144) = 1
```

**Example 2:**

```
Input: nums = [1,5,0,2,-3]
Output: 0
Explanation: The product of all values in the array is 0, and signFunc(0) = 0
```

**Example 3:**

```
Input: nums = [-1,1,-1,1,-1]
Output: -1
Explanation: The product of all values in the array is -1, and signFunc(-1) = -1
```

**Constraints:**

* `1 <= nums.length <= 1000`
* `-100 <= nums[i] <= 100`

---

## Solution & Editorial
# Intuition
Calculating the actual product of the array elements is prone to integer overflow, even with 64-bit integers. Instead, we observe that the sign of a product is determined solely by the number of negative values and the presence of zero.

# Approach
1. Initialize a counter `ans` to track the number of negative integers encountered.
2. Iterate through each `num` in the array `nums`:
   - If `num` is `0`, the entire product is `0`, so return `0` immediately.
   - If `num` is negative, increment `ans`.
3. After the loop, if `ans` is even, the product is positive (`1`). If `ans` is odd, the product is negative (`-1`).

### Visual Trace (Example 1: [-1, -2, -3, -4, 3, 2, 1])
| Iteration | num | ans (count of negatives) | Status |
|-----------|-----|--------------------------|--------|
| 1         | -1  | 1                        | Cont.  |
| 2         | -2  | 2                        | Cont.  |
| 3         | -3  | 3                        | Cont.  |
| 4         | -4  | 4                        | Cont.  |
| 5         | 3   | 4                        | Cont.  |
| 6         | 2   | 4                        | Cont.  |
| 7         | 1   | 4                        | Done   |

Final `ans` = 4 (even), return 1.

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the length of the array, as we perform a single pass over the input.
- Space complexity: $$O(1)$$, as we only use a single integer variable to store the count.

# Code
```cpp
class Solution {
public:
    int arraySign(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        for(int num : nums){
            if(num == 0) return 0;
            else if(num < 0) ans++;
        }
        if(ans%2 == 0) return 1;
        return -1;
    }
};
```
