# [628. Maximum Product of Three Numbers](https://leetcode.com/problems/maximum-product-of-three-numbers/)
**Difficulty:** `Easy` | **Tags:** `array`, `math`, `sorting`

---

## Problem Description
You are given an integer array `nums`.

Find three numbers whose product is **maximum** and return the **maximum** product.

**Example 1:**

**Input:** nums = [1,2,-3]

**Output:** -6

**Explanation:**

The only three numbers are 1, 2, and -3, so the maximum product is `1 * 2 * -3 = -6`.

**Example 2:**

**Input:** nums = [1,2,3,4]

**Output:** 24

**Explanation:**

The largest product comes from the three greatest numbers: `2 * 3 * 4 = 24`.

**Example 3:**

**Input:** nums = [-1,-2,-3]

**Output:** -6

**Explanation:**

The only three numbers are -1, -2, and -3, so the maximum product is `(-1) * (-2) * (-3) = -6`.

**Constraints:**

* `3 <= nums.length <= 104`
* `-1000 <= nums[i] <= 1000`

---

## Solution & Editorial
# Intuition
The maximum product of three numbers in an array can come from either the three largest positive numbers or the product of the two smallest negative numbers and the largest positive number. By sorting the array, we can evaluate potential candidates efficiently.

# Approach
1. Sort the given vector `nums` in ascending order using `std::sort`.
2. Handle the base case where the array size `n` is exactly 3 by returning the product of all three elements.
3. Iterate through possible starting positions `i` up to `n - 2`, extracting three consecutive elements `n1`, `n2`, and `n3`.
4. Optimize the third factor `n3` to be the maximum element `nums[n - 1]` whenever the product of the first two elements `n1 * n2` is positive, as multiplying two negatives yields a positive that scales with large positive numbers.
5. Keep track of the maximum product encountered in `ans` and return it.

### Visual Walkthrough (Example 1: nums = [1, 2, -3])
- Sorted `nums`: `[-3, 1, 2]`
- `n = 3`, triggers direct return: `(-3) * 1 * 2 = -6`.

# Complexity
- Time complexity: $$O(N \log N)$$ due to sorting the array of size $$N$$.
- Space complexity: $$O(1)$$ auxiliary space, operating entirely in-place.

# Code
```cpp
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans = INT_MIN;
        int n = nums.size();
        if(n==3){
            return ans = nums[0]*nums[1]*nums[2];
        } 
        for(int i = 0 ; i < n-2 ; i++){
            int n1 = nums[i];
            int n2 = nums[i+1];
            int n3 = nums[i+2];
            if(n1*n2 > 0){
                n3 = nums[n-1];
            }
            ans = max(ans,n1*n2*n3);
        }

        return ans;
    }
};
```
