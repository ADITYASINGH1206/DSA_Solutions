# [2016. Maximum Difference Between Increasing Elements](https://leetcode.com/problems/maximum-difference-between-increasing-elements/)
**Difficulty:** `Easy` | **Tags:** `array`

---

## Problem Description
Given a **0-indexed** integer array `nums` of size `n`, find the **maximum difference** between `nums[i]` and `nums[j]` (i.e., `nums[j] - nums[i]`), such that `0 <= i < j < n` and `nums[i] < nums[j]`.

Return *the **maximum difference**.* If no such `i` and `j` exists, return `-1`.

**Example 1:**

```
Input: nums = [7,1,5,4]
Output: 4
Explanation:
The maximum difference occurs with i = 1 and j = 2, nums[j] - nums[i] = 5 - 1 = 4.
Note that with i = 1 and j = 0, the difference nums[j] - nums[i] = 7 - 1 = 6, but i > j, so it is not valid.
```

**Example 2:**

```
Input: nums = [9,4,3,2]
Output: -1
Explanation:
There is no i and j such that i < j and nums[i] < nums[j].
```

**Example 3:**

```
Input: nums = [1,5,2,10]
Output: 9
Explanation:
The maximum difference occurs with i = 0 and j = 3, nums[j] - nums[i] = 10 - 1 = 9.
```

**Constraints:**

* `n == nums.length`
* `2 <= n <= 1000`
* `1 <= nums[i] <= 109`

---

## Solution & Editorial
# Intuition
To maximize the difference `nums[j] - nums[i]` where `i < j`, we need to pair every element `nums[j]` with the smallest element encountered so far to its left. By maintaining the running minimum, we can calculate the potential maximum difference in a single pass.

# Approach
1. Initialize `ans` to `-1` to handle cases where no valid pair exists.
2. Keep track of the minimum value seen so far in `mini`, initialized to `nums[0]`.
3. Iterate through the array starting from index `1`:
   - If the current element `nums[i]` is greater than `mini`, update `ans` with the maximum of its current value or `nums[i] - mini`.
   - Otherwise, update `mini` to `nums[i]` because a smaller starting value provides a better opportunity for a larger difference later.

### Visual Trace (nums = [7, 1, 5, 4])
| Index | Value | mini | ans | Action |
| :--- | :--- | :--- | :--- | :--- |
| 0 | 7 | 7 | -1 | Initial state |
| 1 | 1 | 1 | -1 | 1 < 7, update mini |
| 2 | 5 | 1 | 4 | 5 > 1, update ans = max(-1, 5-1) |
| 3 | 4 | 1 | 4 | 4 > 1, update ans = max(4, 4-1) |

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the length of the array. We perform a single linear scan of the input.
- Space complexity: $$O(1)$$, as we only use two integer variables (`ans` and `mini`) regardless of input size.

# Code
```cpp
class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int ans = -1;
        int mini = nums[0];
        for(int i =1;i<nums.size();i++){
            if(nums[i]>mini){
                ans=max(ans,nums[i]-mini);
            }else{
                mini=nums[i];
            }
        }
        return ans;
    }
};
```
