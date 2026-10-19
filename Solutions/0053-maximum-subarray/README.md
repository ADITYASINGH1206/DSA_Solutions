# [53. Maximum Subarray](https://leetcode.com/problems/maximum-subarray/)
**Difficulty:** `Medium` | **Tags:** `array`, `divide-and-conquer`, `dynamic-programming`

---

## Problem Description
Given an integer array `nums`, find the subarray with the largest sum, and return *its sum*.

**Example 1:**

```
Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: The subarray [4,-1,2,1] has the largest sum 6.
```

**Example 2:**

```
Input: nums = [1]
Output: 1
Explanation: The subarray [1] has the largest sum 1.
```

**Example 3:**

```
Input: nums = [5,4,-1,7,8]
Output: 23
Explanation: The subarray [5,4,-1,7,8] has the largest sum 23.
```

**Constraints:**

* `1 <= nums.length <= 105`
* `-104 <= nums[i] <= 104`

**Follow up:** If you have figured out the `O(n)` solution, try coding another solution using the **divide and conquer** approach, which is more subtle.

---

## Solution & Editorial
# Intuition
The problem asks us to find the contiguous subarray within a one-dimensional array of numbers that has the largest sum. By applying Kadane's Algorithm, we can dynamically maintain the maximum sum ending at the current position and reset our running sum whenever it drops below zero, as a negative sum would only decrease the potential sum of any subsequent subarray.

# Approach
1. Initialize `sum` to `0` to keep track of the current subarray sum, and `ans` to `INT_MIN` to record the global maximum subarray sum found so far.
2. Iterate through each element `nums[i]` in the array using a for loop from index `0` to `nums.size() - 1`.
3. Add the current element `nums[i]` to `sum`.
4. Update `ans` with the maximum of its current value and `sum`.
5. If `sum` falls below `0`, reset `sum` to `0` because carrying a negative prefix is never optimal for future extensions.
6. Return `ans` after the loop completes.

### Visual Trace (Example 1: nums = [-2, 1, -3, 4, -1, 2, 1, -5, 4])

| i | nums[i] | sum (before add) | sum (after add) | ans (before update) | ans (after update) | action on sum (<0?) |
|---|---------|------------------|-----------------|---------------------|--------------------|---------------------|
| 0 | -2      | 0                | -2              | -2147483648         | -2                 | reset to 0          |
| 1 | 1       | 0                | 1               | -2                  | 1                  | keep                |
| 2 | -3      | 1                | -2              | 1                   | 1                  | reset to 0          |
| 3 | 4       | 0                | 4               | 1                   | 4                  | keep                |
| 4 | -1      | 4                | 3               | 4                   | 4                  | keep                |
| 5 | 2       | 3                | 5               | 4                   | 5                  | keep                |
| 6 | 1       | 5                | 6               | 5                   | 6                  | keep                |
| 7 | -5      | 6                | 1               | 6                   | 6                  | keep                |
| 8 | 4       | 1                | 5               | 6                   | 6                  | keep                |

# Complexity
- Time complexity: $$O(N)$$ — We iterate through the array of size $$N$$ exactly once, performing constant time $$O(1)$$ operations at each step.
- Space complexity: $$O(1)$$ — Only a few primitive scalar variables (`sum` and `ans`) are utilized, requiring constant auxiliary space.

# Code
```cpp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum =0;
        int ans = INT_MIN;
        for(int i=0;i<nums.size();i++){
            sum+= nums[i];
            if(sum > ans){
                ans = sum;
            }
            if(sum<0){
                sum =0;
            }
        }
        return ans;
    }
};
```
