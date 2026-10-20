# [2958. Length of Longest Subarray With at Most K Frequency](https://leetcode.com/problems/length-of-longest-subarray-with-at-most-k-frequency/)
**Difficulty:** `Medium` | **Tags:** `array`, `hash-table`, `sliding-window`

---

## Problem Description
You are given an integer array `nums` and an integer `k`.

The **frequency** of an element `x` is the number of times it occurs in an array.

An array is called **good** if the frequency of each element in this array is **less than or equal** to `k`.

Return *the length of the **longest** **good** subarray of* `nums`*.*

A **subarray** is a contiguous non-empty sequence of elements within an array.

**Example 1:**

```
Input: nums = [1,2,3,1,2,3,1,2], k = 2
Output: 6
Explanation: The longest possible good subarray is [1,2,3,1,2,3] since the values 1, 2, and 3 occur at most twice in this subarray. Note that the subarrays [2,3,1,2,3,1] and [3,1,2,3,1,2] are also good.
It can be shown that there are no good subarrays with length more than 6.
```

**Example 2:**

```
Input: nums = [1,2,1,2,1,2,1,2], k = 1
Output: 2
Explanation: The longest possible good subarray is [1,2] since the values 1 and 2 occur at most once in this subarray. Note that the subarray [2,1] is also good.
It can be shown that there are no good subarrays with length more than 2.
```

**Example 3:**

```
Input: nums = [5,5,5,5,5,5,5], k = 4
Output: 4
Explanation: The longest possible good subarray is [5,5,5,5] since the value 5 occurs 4 times in this subarray.
It can be shown that there are no good subarrays with length more than 4.
```

**Constraints:**

* `1 <= nums.length <= 105`
* `1 <= nums[i] <= 109`
* `1 <= k <= nums.length`

---

## Solution & Editorial
# Intuition
The problem asks for the longest contiguous subarray where no element appears more than $k$ times. This is a classic sliding window problem because the "good" property is monotonic: if a subarray is good, any smaller subarray within it is also good. We can maintain a window `[low, high]` and expand `high` while keeping track of element frequencies in a hash map.

# Approach
1. Initialize a hash map `mp` to store the frequency of elements in the current window.
2. Use two pointers, `low` and `high`, both starting at the beginning of the array. Expand `high` to include new elements.
3. Whenever the frequency of `nums[high]` exceeds $k$, increment `low` and decrement the frequency of `nums[low]` until the frequency of `nums[high]` is back to $k$ or less.
4. At each step, update the maximum window size `sol = max(sol, high - low + 1)`.

### Visual Trace (Example 1: nums = [1,2,3,1,2,3,1,2], k = 2)
| high | nums[high] | mp (state) | low | Window | sol |
|---|---|---|---|---|---|
| 0 | 1 | {1:1} | 0 | [1] | 1 |
| 1 | 2 | {1:1, 2:1} | 0 | [1,2] | 2 |
| 2 | 3 | {1:1, 2:1, 3:1} | 0 | [1,2,3] | 3 |
| 3 | 1 | {1:2, 2:1, 3:1} | 0 | [1,2,3,1] | 4 |
| 4 | 2 | {1:2, 2:2, 3:1} | 0 | [1,2,3,1,2] | 5 |
| 5 | 3 | {1:2, 2:2, 3:2} | 0 | [1,2,3,1,2,3] | 6 |
| 6 | 1 | {1:3, 2:2, 3:2} | 1 | [2,3,1,2,3,1] | 6 |

# Complexity
- Time complexity: $$O(N)$$, where $N$ is the length of `nums`. Each element is added to the hash map once and removed at most once.
- Space complexity: $$O(N)$$, as the hash map can store up to $N$ unique elements in the worst case.

# Code
```cpp
class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int low = 0, high = 1, sol = 1, n = nums.size();
        unordered_map<int, int> mp;

        mp[nums[0]]++;

        while (high < n) {
            mp[nums[high]]++;

            while (mp[nums[high]] > k) {
                mp[nums[low]]--;
                low++;
            }

            sol = max(high - low + 1, sol);
            high++;
        }

        return sol;
    }
};
```
