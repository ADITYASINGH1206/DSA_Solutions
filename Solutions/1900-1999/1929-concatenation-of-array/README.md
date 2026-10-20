# [1929. Concatenation of Array](https://leetcode.com/problems/concatenation-of-array/)
**Difficulty:** `Easy` | **Tags:** `array`, `simulation`

---

## Problem Description
Given an integer array `nums` of length `n`, you want to create an array `ans` of length `2n` where `ans[i] == nums[i]` and `ans[i + n] == nums[i]` for `0 <= i < n` (**0-indexed**).

Specifically, `ans` is the **concatenation** of two `nums` arrays.

Return *the array* `ans`.

**Example 1:**

```
Input: nums = [1,2,1]
Output: [1,2,1,1,2,1]
Explanation: The array ans is formed as follows:
- ans = [nums[0],nums[1],nums[2],nums[0],nums[1],nums[2]]
- ans = [1,2,1,1,2,1]
```

**Example 2:**

```
Input: nums = [1,3,2,1]
Output: [1,3,2,1,1,3,2,1]
Explanation: The array ans is formed as follows:
- ans = [nums[0],nums[1],nums[2],nums[3],nums[0],nums[1],nums[2],nums[3]]
- ans = [1,3,2,1,1,3,2,1]
```

**Constraints:**

* `n == nums.length`
* `1 <= n <= 1000`
* `1 <= nums[i] <= 1000`

---

## Solution & Editorial
# Intuition
The problem requires creating a new array of size 2n by repeating the input array twice. Since we need to append the original elements to the end of the existing sequence, we can initialize a result vector with the original data and then iterate through the input to append the elements again.

# Approach
1. Initialize a vector `ans` with the contents of the input `nums`. This effectively handles the first half of the concatenation.
2. Iterate through the input `nums` using a loop from index `i = 0` to `n - 1`.
3. In each iteration, use `push_back` to append `nums[i]` to the end of `ans`.
4. Return the resulting `ans` vector.

### Visual Trace (Example 1: nums = [1, 2, 1])
| Iteration | i | nums[i] | ans (before) | ans (after) |
| :--- | :--- | :--- | :--- | :--- |
| Init | - | - | [1, 2, 1] | [1, 2, 1] |
| 1 | 0 | 1 | [1, 2, 1] | [1, 2, 1, 1] |
| 2 | 1 | 2 | [1, 2, 1, 1] | [1, 2, 1, 1, 2] |
| 3 | 2 | 1 | [1, 2, 1, 1, 2] | [1, 2, 1, 1, 2, 1] |

# Complexity
- Time complexity: $$O(n)$$, where $$n$$ is the length of the input array. We perform a single pass over the array to copy elements.
- Space complexity: $$O(n)$$, as we create a new array of size $$2n$$ to store the concatenated result.

# Code
```cpp
class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int>ans=nums;
        for(int i = 0 ; i<nums.size() ; i++){
            ans.push_back(nums[i]);
        }
        return ans;
    }
};
```
