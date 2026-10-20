# [1920. Build Array from Permutation](https://leetcode.com/problems/build-array-from-permutation/)
**Difficulty:** `Easy` | **Tags:** `array`, `simulation`

---

## Problem Description
Given a **zero-based permutation** `nums` (**0-indexed**), build an array `ans` of the **same length** where `ans[i] = nums[nums[i]]` for each `0 <= i < nums.length` and return it.

A **zero-based permutation** `nums` is an array of **distinct** integers from `0` to `nums.length - 1` (**inclusive**).

**Example 1:**

```
Input: nums = [0,2,1,5,3,4]
Output: [0,1,2,4,5,3]
Explanation: The array ans is built as follows: 
ans = [nums[nums[0]], nums[nums[1]], nums[nums[2]], nums[nums[3]], nums[nums[4]], nums[nums[5]]]
    = [nums[0], nums[2], nums[1], nums[5], nums[3], nums[4]]
    = [0,1,2,4,5,3]
```

**Example 2:**

```
Input: nums = [5,0,1,2,3,4]
Output: [4,5,0,1,2,3]
Explanation: The array ans is built as follows:
ans = [nums[nums[0]], nums[nums[1]], nums[nums[2]], nums[nums[3]], nums[nums[4]], nums[nums[5]]]
    = [nums[5], nums[0], nums[1], nums[2], nums[3], nums[4]]
    = [4,5,0,1,2,3]
```

**Constraints:**

* `1 <= nums.length <= 1000`
* `0 <= nums[i] < nums.length`
* The elements in `nums` are **distinct**.

**Follow-up:** Can you solve it without using an extra space (i.e., `O(1)` memory)?

---

## Solution & Editorial
# Intuition
The problem asks us to construct a new array where each element at index `i` is determined by the value at the index specified by `nums[i]`. Since the mapping is direct and defined by the input array itself, we can compute the result in a single pass.

# Approach
1. Initialize a result vector `ans` of the same size as `nums`.
2. Iterate through the input array `nums` using an index `i` from `0` to `n-1`.
3. For each index `i`, assign `ans[i] = nums[nums[i]]`.
4. Return the populated `ans` vector.

### Visual Trace (Example 1: nums = [0, 2, 1, 5, 3, 4])
| i | nums[i] | nums[nums[i]] | ans[i] |
|---|---------|---------------|--------|
| 0 | 0       | nums[0] = 0   | 0      |
| 1 | 2       | nums[2] = 1   | 1      |
| 2 | 1       | nums[1] = 2   | 2      |
| 3 | 5       | nums[5] = 4   | 4      |
| 4 | 3       | nums[3] = 5   | 5      |
| 5 | 4       | nums[4] = 3   | 3      |

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the length of the input array. We perform a single linear scan over the input.
- Space complexity: $$O(N)$$, as we allocate a new vector `ans` of size $$N$$ to store the result.

# Code
```cpp
class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        vector<int> ans(nums.size(),0);
        for(int i=0;i<nums.size();i++){
            ans[i] = nums[nums[i]];
        }
        return ans;
    }
};
```
