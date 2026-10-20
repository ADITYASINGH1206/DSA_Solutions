# [164. Maximum Gap](https://leetcode.com/problems/maximum-gap/)
**Difficulty:** `Medium` | **Tags:** `array`, `sorting`, `bucket-sort`, `radix-sort`, `pigeonhole-principle`

---

## Problem Description
Given an integer array `nums`, return *the maximum difference between two successive elements in its sorted form*. If the array contains less than two elements, return `0`.

You must write an algorithm that runs in linear time and uses linear extra space.

**Example 1:**

```
Input: nums = [3,6,9,1]
Output: 3
Explanation: The sorted form of the array is [1,3,6,9], either (3,6) or (6,9) has the maximum difference 3.
```

**Example 2:**

```
Input: nums = [10]
Output: 0
Explanation: The array contains less than 2 elements, therefore return 0.
```

**Constraints:**

* `1 <= nums.length <= 105`
* `0 <= nums[i] <= 109`

---

## Solution & Editorial
# Intuition
The problem requires finding the maximum difference between successive elements in the sorted version of an array. If we sort the array directly, the successive differences can be checked in a single linear pass.

# Approach
1. Check if the size of `nums` is less than 2. If so, return `0` because no successive elements exist.
2. Sort the array `nums` in non-decreasing order using `sort`.
3. Initialize a variable `diff` to `0` to keep track of the maximum successive difference.
4. Iterate through the sorted array using a `while` loop with index `i` from `0` to `n - 2`.
5. In each iteration, update `diff` with the maximum of its current value and `nums[i + 1] - nums[i]`.
6. Return `diff` after completing the scan.

### Visual Walkthrough (Example 1: `nums = [3, 6, 9, 1]`)
- **Initial State:** `nums = [3, 6, 9, 1]`, `n = 4`
- **After Sorting:** `nums = [1, 3, 6, 9]`
- **Iteration 1 (`i = 0`):** Compare `nums[0]` (1) and `nums[1]` (3). Difference = `2`. `diff = max(0, 2) = 2`.
- **Iteration 2 (`i = 1`):** Compare `nums[1]` (3) and `nums[2]` (6). Difference = `3`. `diff = max(2, 3) = 3`.
- **Iteration 3 (`i = 2`):** Compare `nums[2]` (6) and `nums[3]` (9). Difference = `3`. `diff = max(3, 3) = 3`.
- **Final Output:** `3`

# Complexity
- Time complexity: $$O(N \log N)$$ due to the sorting step of size $N$, followed by an $$O(N)$$ linear scan.
- Space complexity: $$O(1)$$ auxiliary space, assuming in-place sorting overhead is negligible.

# Code
```cpp
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int diff = 0;
        if(n < 2){
            return 0;
        }
        int i = 0;
        while(i < n-1){
            diff = max(diff, nums[i+1] - nums[i]);
            i++;
        }
        return diff;    
    }
};
```
