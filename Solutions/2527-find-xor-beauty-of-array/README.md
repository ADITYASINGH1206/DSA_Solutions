# [2527. Find Xor-Beauty of Array](https://leetcode.com/problems/find-xor-beauty-of-array/)
**Difficulty:** `Medium` | **Tags:** `array`, `math`, `bit-manipulation`

---

## Problem Description
You are given a **0-indexed** integer array `nums`.

The **effective value** of three indices `i`, `j`, and `k` is defined as `((nums[i] | nums[j]) & nums[k])`.

The **xor-beauty** of the array is the XORing of **the effective values of all the possible triplets** of indices `(i, j, k)` where `0 <= i, j, k < n`.

Return *the xor-beauty of* `nums`.

**Note** that:

* `val1 | val2` is bitwise OR of `val1` and `val2`.
* `val1 & val2` is bitwise AND of `val1` and `val2`.

**Example 1:**

```
Input: nums = [1,4]
Output: 5
Explanation: 
The triplets and their corresponding effective values are listed below:
- (0,0,0) with effective value ((1 | 1) & 1) = 1
- (0,0,1) with effective value ((1 | 1) & 4) = 0
- (0,1,0) with effective value ((1 | 4) & 1) = 1
- (0,1,1) with effective value ((1 | 4) & 4) = 4
- (1,0,0) with effective value ((4 | 1) & 1) = 1
- (1,0,1) with effective value ((4 | 1) & 4) = 4
- (1,1,0) with effective value ((4 | 4) & 1) = 0
- (1,1,1) with effective value ((4 | 4) & 4) = 4 
Xor-beauty of array will be bitwise XOR of all beauties = 1 ^ 0 ^ 1 ^ 4 ^ 1 ^ 4 ^ 0 ^ 4 = 5.
```

**Example 2:**

```
Input: nums = [15,45,20,2,34,35,5,44,32,30]
Output: 34
Explanation: The xor-beauty of the given array is 34.
```

**Constraints:**

* `1 <= nums.length <= 105`
* `1 <= nums[i] <= 109`

---

## Solution & Editorial
# Intuition
The problem asks us to compute the XOR sum of `((nums[i] | nums[j]) & nums[k])` for all possible triplets `(i, j, k)`. Expanding the expression using bitwise properties reveals that most terms cancel out due to the properties of XOR, leaving only the XOR sum of the array elements themselves.

# Approach
1. Expand the expression: `((nums[i] | nums[j]) & nums[k])` can be distributed as `(nums[i] & nums[k]) | (nums[j] & nums[k])`.
2. When we XOR over all `i, j, k`, consider the contribution of a specific bit position. If `i == j`, the term becomes `(nums[i] & nums[k])`. If `i != j`, the terms `(nums[i] & nums[k])` and `(nums[j] & nums[k])` appear symmetrically and cancel each other out in the XOR sum.
3. Consequently, the expression simplifies to the XOR sum of `nums[i] & nums[i]` for all `i`, which is simply the XOR sum of all elements in `nums`.

### Visual Trace (Example 1: nums = [1, 4])
- Triplets (i, j, k):
  - (0,0,0): (1|1)&1 = 1
  - (0,0,1): (1|1)&4 = 0
  - (0,1,0): (1|4)&1 = 1
  - (0,1,1): (1|4)&4 = 4
  - (1,0,0): (4|1)&1 = 1
  - (1,0,1): (4|1)&4 = 4
  - (1,1,0): (4|4)&1 = 0
  - (1,1,1): (4|4)&4 = 4
- XOR Sum: 1 ^ 0 ^ 1 ^ 4 ^ 1 ^ 4 ^ 0 ^ 4 = 5
- Simplified: 1 ^ 4 = 5

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the length of the array, as we iterate through the array exactly once.
- Space complexity: $$O(1)$$, as we only use a single integer variable to accumulate the XOR sum.

# Code
```cpp
class Solution {
public:
    int xorBeauty(vector<int>& nums) {
        int ans = 0;
        for (int& x : nums) {
            ans ^= x;
        }
        return ans;
    }
};
```
