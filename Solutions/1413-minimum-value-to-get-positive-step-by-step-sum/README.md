# [1413. Minimum Value to Get Positive Step by Step Sum](https://leetcode.com/problems/minimum-value-to-get-positive-step-by-step-sum/)
**Difficulty:** `Easy` | **Tags:** `array`, `prefix-sum`

---

## Problem Description
Given an array of integers `nums`, you start with an initial **positive** value *startValue**.*

In each iteration, you calculate the step by step sum of *startValue* plus elements in `nums` (from left to right).

Return the minimum **positive** value of *startValue* such that the step by step sum is never less than 1.

**Example 1:**

```
Input: nums = [-3,2,-3,4,2]
Output: 5
Explanation: If you choose startValue = 4, in the third iteration your step by step sum is less than 1.
step by step sum
startValue = 4 | startValue = 5 | nums
  (4 -3 ) = 1  | (5 -3 ) = 2    |  -3
  (1 +2 ) = 3  | (2 +2 ) = 4    |   2
  (3 -3 ) = 0  | (4 -3 ) = 1    |  -3
  (0 +4 ) = 4  | (1 +4 ) = 5    |   4
  (4 +2 ) = 6  | (5 +2 ) = 7    |   2
```

**Example 2:**

```
Input: nums = [1,2]
Output: 1
Explanation: Minimum start value should be positive.
```

**Example 3:**

```
Input: nums = [1,-2,-3]
Output: 5
```

**Constraints:**

* `1 <= nums.length <= 100`
* `-100 <= nums[i] <= 100`

---

## Solution & Editorial
# Intuition
To ensure the step-by-step sum never drops below 1, we need to identify the "lowest point" reached by the prefix sums of the array. If the minimum prefix sum is non-positive, we must increase our `startValue` enough to offset that deficit.

# Approach
1. Maintain a running `curr` sum as we iterate through `nums`.
2. Track the global minimum value `minm` encountered during these prefix sum calculations.
3. If `minm` is already positive (i.e., the sum never dropped below 1), the smallest possible `startValue` is 1.
4. If `minm` is less than or equal to 0, the `startValue` must be at least `abs(minm) + 1` to ensure the sum remains at least 1 at the point where it previously hit `minm`.

### Visual Trace (Example 1: nums = [-3, 2, -3, 4, 2])
| Iteration | num | curr | minm |
|-----------|-----|------|------|
| 1         | -3  | -3   | -3   |
| 2         | 2   | -1   | -3   |
| 3         | -3  | -4   | -4   |
| 4         | 4   | 0    | -4   |
| 5         | 2   | 2    | -4   |

Result: `abs(-4) + 1 = 5`.

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the length of `nums`, as we perform a single pass over the array.
- Space complexity: $$O(1)$$, as we only use two integer variables regardless of input size.

# Code
```cpp
class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int curr = 0;
        int minm = INT_MAX;
        for(int num:nums){
            curr+=num;
            minm=min(minm,curr);
        }
        return minm>0 ? 1:abs(minm)+1;      
    }
};
```
