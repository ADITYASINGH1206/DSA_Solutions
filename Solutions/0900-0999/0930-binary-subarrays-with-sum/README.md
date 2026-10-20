# [930. Binary Subarrays With Sum](https://leetcode.com/problems/binary-subarrays-with-sum/)
**Difficulty:** `Medium` | **Tags:** `array`, `hash-table`, `sliding-window`, `prefix-sum`

---

## Problem Description
Given a binary array `nums` and an integer `goal`, return *the number of non-empty **subarrays** with a sum* `goal`.

A **subarray** is a contiguous part of the array.

**Example 1:**

```
Input: nums = [1,0,1,0,1], goal = 2
Output: 4
Explanation: The 4 subarrays are bolded and underlined below:
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]
```

**Example 2:**

```
Input: nums = [0,0,0,0,0], goal = 0
Output: 15
```

**Constraints:**

* `1 <= nums.length <= 3 * 104`
* `nums[i]` is either `0` or `1`.
* `0 <= goal <= nums.length`

---

## Solution & Editorial
# Intuition
The problem asks us to count the number of contiguous subarrays that sum up to a specific `goal`. Since all elements in `nums` are either `0` or `1`, the prefix sums are monotonically increasing. This property allows us to solve the problem efficiently using a sliding window approach. Specifically, the exact count of subarrays summing to `goal` can be expressed as the difference between the number of subarrays summing at most `goal` and the number of subarrays summing at most `goal - 1`.

# Approach
1. Define a helper function `atmost(nums, goal)` which calculates the total number of subarrays whose sum is less than or equal to `goal`.
2. Handle the edge case where `goal <0` by immediately returning `0`.
3. Maintain a sliding window defined by pointers `l` (left) and `r` (right), along with running variables `sum` (current window sum) and `cnt` (accumulated valid subarray count).
4. Expand the window by iterating `r` from `0` to `nums.size() - 1`, adding `nums[r]` to `sum`.
5. If `sum > goal`, shrink the window from the left by subtracting `nums[l]` from `sum` and incrementing `l` until `sum <= goal` is restored.
6. For each position of `r`, add the number of valid ending subarrays `(r - l + 1)` to `cnt`.
7. Finally, compute `numSubarraysWithSum` by returning `atmost(nums, goal) - atmost(nums, goal - 1)`.

### Visual Walkthrough for `nums = [1, 0, 1, 0, 1]`, `goal = 2`
Computing `atmost(nums, 2)`:
- `r = 0`, `nums[0] = 1`: `sum = 1`, `l = 0`. `cnt += (0 - 0 + 1) = 1`. (`sum = 1`)
- `r = 1`, `nums[1] = 0`: `sum = 1`, `l = 0`. `cnt += (1 - 0 + 1) = 2`. (`sum = 1`)
- `r = 2`, `nums[2] = 1`: `sum = 2`, `l = 0`. `cnt += (2 - 0 + 1) = 3`. (`sum = 2`)
- `r = 3`, `nums[3] = 0`: `sum = 2`, `l = 0`. `cnt += (3 - 0 + 1) = 4`. (`sum = 2`)
- `r = 4`, `nums[4] = 1`: `sum = 3`, `sum > 2` triggers shrink:
  - `sum` becomes `3 - nums[0] = 2`, `l` becomes `1`.
  - `cnt += (4 - 1 + 1) = 4 + 4 = 8`. (`sum = 2`)
Total `atmost(nums, 2) = 8`.

Computing `atmost(nums, 1)` yields `4`. 
Result = `8 - 4 = 4`.

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the length of `nums`. Both `l` and `r` traverse the array at most twice (once for `goal` and once for `goal - 1`), resulting in linear time performance.
- Space complexity: $$O(1)$$, as only a few scalar variables are used for pointers and tracking sums.

# Code
```cpp
class Solution {
public:
    int atmost(vector<int>& nums, int goal) {
        int l=0,r=0,sum=0,cnt=0;
        if(goal<0) return 0;
        while(r<nums.size())
        {
            sum+=nums[r];
            while(sum>goal)
            {
                sum=sum-nums[l];
                l++;
            }
            cnt=cnt+(r-l+1);
            r++;
        }
    return cnt;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atmost(nums,goal)-atmost(nums,goal-1);
    }
};
```
