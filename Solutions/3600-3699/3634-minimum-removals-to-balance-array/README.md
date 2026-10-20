# [3634. Minimum Removals to Balance Array](https://leetcode.com/problems/minimum-removals-to-balance-array/)
**Difficulty:** `Medium` | **Tags:** `array`, `binary-search`, `sliding-window`, `sorting`

---

## Problem Description
You are given an integer array `nums` and an integer `k`.

An array is considered **balanced** if the value of its **maximum** element is **at most** `k` times the **minimum** element.

You may remove **any** number of elements from `nums`​​​​​​​ without making it **empty**.

Return the **minimum** number of elements to remove so that the remaining array is balanced.

**Note:** An array of size 1 is considered balanced as its maximum and minimum are equal, and the condition always holds true.

**Example 1:**

**Input:** nums = [2,1,5], k = 2

**Output:** 1

**Explanation:**

* Remove `nums[2] = 5` to get `nums = [2, 1]`.
* Now `max = 2`, `min = 1` and `max <= min * k` as `2 <= 1 * 2`. Thus, the answer is 1.

**Example 2:**

**Input:** nums = [1,6,2,9], k = 3

**Output:** 2

**Explanation:**

* Remove `nums[0] = 1` and `nums[3] = 9` to get `nums = [6, 2]`.
* Now `max = 6`, `min = 2` and `max <= min * k` as `6 <= 2 * 3`. Thus, the answer is 2.

**Example 3:**

**Input:** nums = [4,6], k = 2

**Output:** 0

**Explanation:**

* Since `nums` is already balanced as `6 <= 4 * 2`, no elements need to be removed.

**Constraints:**

* `1 <= nums.length <= 105`
* `1 <= nums[i] <= 109`
* `1 <= k <= 105`

---

## Solution & Editorial
# Intuition
To minimize the number of removals, we must maximize the number of elements kept in the array such that the condition `max <= min * k` holds. By sorting the array, any subset that satisfies the condition will be a contiguous subarray in the sorted version, allowing us to use a sliding window approach.

# Approach
1. Sort the array `nums` in non-decreasing order. This ensures that for any window `[l, r]`, the minimum is `nums[l]` and the maximum is `nums[r]`.
2. Use two pointers, `l` and `r`, to represent the current window of valid elements. Iterate `r` from `0` to `n-1`.
3. For each `r`, check if `nums[r] > nums[l] * k`. If this condition is violated, increment `l` until the condition `nums[r] <= nums[l] * k` is satisfied.
4. Maintain the maximum window size `ans = max(ans, r - l + 1)` encountered during the iteration.
5. The minimum number of removals is simply the total number of elements `n` minus the maximum window size `ans`.

### Visual Trace (Example 1: nums = [1, 2, 5], k = 2)
| r | l | nums[l] | nums[r] | Condition (nums[r] <= nums[l]*k) | Window Size | Max Window |
|---|---|---|---|---|---|---|
| 0 | 0 | 1 | 1 | 1 <= 2 (True) | 1 | 1 |
| 1 | 0 | 1 | 2 | 2 <= 2 (True) | 2 | 2 |
| 2 | 1 | 2 | 5 | 5 <= 4 (False) -> l=2 | 1 | 2 |

# Complexity
- Time complexity: $$O(N \log N)$$ due to the sorting step. The sliding window traversal itself is $$O(N)$$ as each pointer `l` and `r` moves at most `N` times.
- Space complexity: $$O(1)$$ (ignoring the space required for sorting, which depends on the implementation).

# Code
```cpp
class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int ans = 0;
        int n = nums.size();
        int l = 0;
        for(int r=0;r<nums.size();r++){
            while((long long)nums[r] > (long long)nums[l] *k){
                l++;
            }
            ans = max(ans,r-l+1);
        }
        return n-ans;
    }
};
```
