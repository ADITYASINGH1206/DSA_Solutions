# [1464. Maximum Product of Two Elements in an Array](https://leetcode.com/problems/maximum-product-of-two-elements-in-an-array/)
**Difficulty:** `Easy` | **Tags:** `array`, `sorting`, `heap-priority-queue`

---

## Problem Description
You are given an array of integers `nums`.

Choose two **different** indices `i` and `j` of that array.

Return the **maximum** value of `(nums[i] - 1) * (nums[j] - 1)`.

**Example 1:**

```
Input: nums = [3,4,5,2]
Output: 12 
Explanation: If you choose the indices i=1 and j=2 (indexed from 0), you will get the maximum value, that is, (nums[1]-1)*(nums[2]-1) = (4-1)*(5-1) = 3*4 = 12.
```

**Example 2:**

```
Input: nums = [1,5,4,5]
Output: 16
Explanation: Choosing the indices i=1 and j=3 (indexed from 0), you will get the maximum value of (5-1)*(5-1) = 16.
```

**Example 3:**

```
Input: nums = [3,7]
Output: 12
```

**Constraints:**

* `2 <= nums.length <= 500`
* `1 <= nums[i] <= 10^3`

---

## Solution & Editorial
# Intuition
To maximize the product `(nums[i] - 1) * (nums[j] - 1)`, we need to identify the two largest values in the array. Since the expression is monotonically increasing with respect to `nums[i]` and `nums[j]`, selecting the two largest elements guarantees the maximum possible product.

# Approach
1. Initialize two variables, `maxi1` and `maxi2`, to `INT_MIN` to track the largest and second-largest values found so far.
2. Iterate through the array `nums` exactly once.
3. For each element `nums[i]`:
   - If `nums[i]` is greater than `maxi1`, update `maxi2` to the old `maxi1` and set `maxi1` to `nums[i]`.
   - Otherwise, if `nums[i]` is greater than `maxi2`, update `maxi2` to `nums[i]`.
4. Return the result of `(maxi1 - 1) * (maxi2 - 1)`.

### Visual Trace (Example 1: [3, 4, 5, 2])
| Iteration | Current Element | maxi1 | maxi2 |
|-----------|-----------------|-------|-------|
| Start     | -               | -inf  | -inf  |
| 1         | 3               | 3     | -inf  |
| 2         | 4               | 4     | 3     |
| 3         | 5               | 5     | 4     |
| 4         | 2               | 5     | 4     |

Result: (5-1) * (4-1) = 4 * 3 = 12.

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the length of the array, as we perform a single pass over the input.
- Space complexity: $$O(1)$$, as we only use two integer variables regardless of the input size.

# Code
```cpp
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxi1 = INT_MIN;
        int maxi2 = INT_MIN;
        int n = nums.size();
        for(int i =0;i<n;i++){
            if(nums[i]>maxi1){
                maxi2 = maxi1;
                maxi1 = nums[i];
            }else if(nums[i] > maxi2){
                maxi2 = nums[i];
            }
        }

        return (maxi1-1)*(maxi2-1);
    }
};
```
