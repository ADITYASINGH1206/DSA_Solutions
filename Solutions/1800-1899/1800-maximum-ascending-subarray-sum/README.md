# [1800. Maximum Ascending Subarray Sum](https://leetcode.com/problems/maximum-ascending-subarray-sum/)
**Difficulty:** `Easy` | **Tags:** `array`

---

## Problem Description
Given an array of positive integers `nums`, return the **maximum** possible sum of an strictly increasing subarray in`nums`.

A subarray is defined as a contiguous sequence of numbers in an array.

**Example 1:**

```
Input: nums = [10,20,30,5,10,50]
Output: 65
Explanation: [5,10,50] is the ascending subarray with the maximum sum of 65.
```

**Example 2:**

```
Input: nums = [10,20,30,40,50]
Output: 150
Explanation: [10,20,30,40,50] is the ascending subarray with the maximum sum of 150.
```

**Example 3:**

```
Input: nums = [12,17,15,13,10,11,12]
Output: 33
Explanation: [10,11,12] is the ascending subarray with the maximum sum of 33.
```

**Constraints:**

* `1 <= nums.length <= 100`
* `1 <= nums[i] <= 100`

---

## Solution & Editorial
# Intuition
To find the maximum sum of a strictly increasing subarray, we can perform a single linear scan. As we iterate through the array, we maintain a running sum of the current ascending sequence and update the global maximum whenever the sequence breaks or the array ends.

# Approach
1. Initialize `ans` and `temp` with the first element of the array, `nums[0]`. `ans` stores the global maximum sum found so far, while `temp` tracks the sum of the current strictly increasing subarray.
2. Iterate through the array starting from the second element (index `i = 1` to `n-1`).
3. If `nums[i] > nums[i-1]`, the current element extends the existing ascending sequence. Add `nums[i]` to `temp`.
4. If `nums[i] <= nums[i-1]`, the sequence is broken. Reset `temp` to `nums[i]` to start a new subarray.
5. In every iteration, update `ans = max(ans, temp)` to ensure the global maximum is captured.

### Visual Trace (Example 1: [10, 20, 30, 5, 10, 50])
| Index | Value | Condition | temp | ans |
|-------|-------|-----------|------|-----|
| 0 | 10 | Init | 10 | 10 |
| 1 | 20 | 20 > 10 | 30 | 30 |
| 2 | 30 | 30 > 20 | 60 | 60 |
| 3 | 5 | 5 <= 30 | 5 | 60 |
| 4 | 10 | 10 > 5 | 15 | 60 |
| 5 | 50 | 50 > 10 | 65 | 65 |

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the length of the array, as we perform a single pass through the input.
- Space complexity: $$O(1)$$, as we only use a constant amount of extra space for variables `ans`, `temp`, and `n`.

# Code
```cpp
class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int ans = nums[0];
        int temp = nums[0];
        int n = nums.size();
        for(int i = 1;i<n;i++){
            if(nums[i]>nums[i-1]){
                temp += nums[i];
            }
            else{
                temp = nums[i];
            }
            ans = max(ans,temp);
        }
        return ans;
    }
};
```
