# [905. Sort Array By Parity](https://leetcode.com/problems/sort-array-by-parity/)
**Difficulty:** `Easy` | **Tags:** `array`, `two-pointers`, `sorting`

---

## Problem Description
Given an integer array `nums`, move all the even integers at the beginning of the array followed by all the odd integers.

Return ***any array** that satisfies this condition*.

**Example 1:**

```
Input: nums = [3,1,2,4]
Output: [2,4,3,1]
Explanation: The outputs [4,2,3,1], [2,4,1,3], and [4,2,1,3] would also be accepted.
```

**Example 2:**

```
Input: nums = [0]
Output: [0]
```

**Constraints:**

* `1 <= nums.length <= 5000`
* `0 <= nums[i] <= 5000`

---

## Solution & Editorial
# Intuition
The problem requires us to rearrange the array such that all even integers appear before all odd integers. We can achieve this efficiently in a single pass using a two-pointer approach where one pointer scans the array and another pointer marks the boundary for even numbers.

# Approach
1. Initialize two pointers, `i` and `j`, both starting at index 0. The variable `n` stores the size of `nums`.
2. Iterate through the array using pointer `i` from `0` to `n - 1`.
3. At each iteration, check if `nums[i]` is even (`nums[i] % 2 == 0`). If it is, swap `nums[i]` with `nums[j]` and then increment `j` by 1. If it is odd, simply leave `j` in place and increment `i`.
4. By the end of the traversal, all even elements will have been swapped to the front region of the array up to index `j - 1`, and all odd elements will naturally be pushed to the right.

### Visual Trace (Example 1: `nums = [3, 1, 2, 4]`)
- Initial: `i = 0`, `j = 0`, `nums = [3, 1, 2, 4]`
- `i = 0`: `nums[0] = 3` (odd). No swap. `i` becomes 1. (`nums = [3, 1, 2, 4]`, `j = 0`)
- `i = 1`: `nums[1] = 1` (odd). No swap. `i` becomes 2. (`nums = [3, 1, 2, 4]`, `j = 0`)
- `i = 2`: `nums[2] = 2` (even). Swap `nums[2]` and `nums[0]`. `j` becomes 1, `i` becomes 3. (`nums = [2, 1, 3, 4]`, `j = 1`)
- `i = 3`: `nums[3] = 4` (even). Swap `nums[3]` and `nums[1]`. `j` becomes 2, `i` becomes 4. (`nums = [2, 4, 3, 1]`, `j = 2`)
- Loop terminates. Final output: `[2, 4, 3, 1]`.

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the number of elements in `nums`. We traverse the array exactly once with the `i` pointer.
- Space complexity: $$O(1)$$, as the rearrangement is performed in place using only a constant amount of extra variables.

# Code
```cpp
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n = nums.size();
        int i = 0 , j=0;
        for(;i<n;i++){
            if(nums[i]%2 == 0) swap(nums[j++],nums[i]);
        }

        return nums;
    }
};
```
