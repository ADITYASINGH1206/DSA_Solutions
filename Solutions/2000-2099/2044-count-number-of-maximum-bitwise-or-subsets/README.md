# [2044. Count Number of Maximum Bitwise-OR Subsets](https://leetcode.com/problems/count-number-of-maximum-bitwise-or-subsets/)
**Difficulty:** `Medium` | **Tags:** `array`, `backtracking`, `bit-manipulation`, `enumeration`

---

## Problem Description
Given an integer array `nums`, find the **maximum** possible **bitwise OR** of a subset of `nums` and return *the **number of different non-empty subsets** with the maximum bitwise OR*.

An array `a` is a **subset** of an array `b` if `a` can be obtained from `b` by deleting some (possibly zero) elements of `b`. Two subsets are considered **different** if the indices of the elements chosen are different.

The bitwise OR of an array `a` is equal to `a[0] OR a[1] OR ... OR a[a.length - 1]` (**0-indexed**).

**Example 1:**

```
Input: nums = [3,1]
Output: 2
Explanation: The maximum possible bitwise OR of a subset is 3. There are 2 subsets with a bitwise OR of 3:
- [3]
- [3,1]
```

**Example 2:**

```
Input: nums = [2,2,2]
Output: 7
Explanation: All non-empty subsets of [2,2,2] have a bitwise OR of 2. There are 23 - 1 = 7 total subsets.
```

**Example 3:**

```
Input: nums = [3,2,1,5]
Output: 6
Explanation: The maximum possible bitwise OR of a subset is 7. There are 6 subsets with a bitwise OR of 7:
- [3,5]
- [3,1,5]
- [3,2,5]
- [3,2,1,5]
- [2,5]
- [2,1,5]
```

**Constraints:**

* `1 <= nums.length <= 16`
* `1 <= nums[i] <= 105`

---

## Solution & Editorial
# Intuition
To find the number of subsets with the maximum possible bitwise OR, we first observe that the maximum possible OR value is simply the bitwise OR of all elements in the array. Since the input size is small (N ≤ 16), we can explore all possible subsets using recursion to count how many achieve this maximum value.

# Approach
1. **Calculate Maximum OR**: Iterate through the entire `nums` array and compute the bitwise OR of all elements. This value, `maxOr`, represents the target we are looking for.
2. **Recursive Enumeration**: Use a helper function `helper(index, currentOr)` to traverse the array. At each index, we have two choices:
   - Include `nums[index]` in the current subset (update `currentOr` to `currentOr | nums[index]`).
   - Exclude `nums[index]` from the current subset (keep `currentOr` as is).
3. **Base Case**: When `index` reaches `nums.size()`, check if `currentOr == maxOr`. If true, increment the global `count`.

### Visual Trace (Example 1: nums = [3, 1])
- `maxOr` = 3 | 1 = 3
- `helper(0, 0)`:
  - `helper(1, 3)` (include 3):
    - `helper(2, 3)` (include 1) -> `3 == 3` (count=1)
    - `helper(2, 3)` (exclude 1) -> `3 == 3` (count=2)
  - `helper(1, 0)` (exclude 3):
    - `helper(2, 1)` (include 1) -> `1 != 3`
    - `helper(2, 0)` (exclude 1) -> `0 != 3`

# Complexity
- Time complexity: $$O(2^N)$$, where $$N$$ is the length of the array. We explore every possible subset, and there are $$2^N$$ subsets in total.
- Space complexity: $$O(N)$$, representing the maximum depth of the recursion stack.

# Code
```cpp
class Solution {
public:
    int count = 0; 
    void helper(vector<int>& nums, int index, int currentOr, int maxOr) {
        if (index == nums.size()) {
            if (currentOr == maxOr) {
                count++;
            }
            return;
        }
        helper(nums, index + 1, currentOr | nums[index], maxOr);
        helper(nums, index + 1, currentOr, maxOr);
    }

    int countMaxOrSubsets(vector<int>& nums) {
        int maxOr = 0;
        for (int num : nums) {
            maxOr |= num;
        }
        helper(nums, 0, 0, maxOr);

        return count;
    }
};
```
