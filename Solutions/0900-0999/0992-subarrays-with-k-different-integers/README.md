# [992. Subarrays with K Different Integers](https://leetcode.com/problems/subarrays-with-k-different-integers/)
**Difficulty:** `Hard` | **Tags:** `array`, `hash-table`, `sliding-window`, `counting`

---

## Problem Description
Given an integer array `nums` and an integer `k`, return *the number of **good subarrays** of* `nums`.

A **good array** is an array where the number of different integers in that array is exactly `k`.

* For example, `[1,2,3,1,2]` has `3` different integers: `1`, `2`, and `3`.

A **subarray** is a **contiguous** part of an array.

**Example 1:**

```
Input: nums = [1,2,1,2,3], k = 2
Output: 7
Explanation: Subarrays formed with exactly 2 different integers: [1,2], [2,1], [1,2], [2,3], [1,2,1], [2,1,2], [1,2,1,2]
```

**Example 2:**

```
Input: nums = [1,2,1,3,4], k = 3
Output: 3
Explanation: Subarrays formed with exactly 3 different integers: [1,2,1,3], [2,1,3], [1,3,4].
```

**Constraints:**

* `1 <= nums.length <= 2 * 104`
* `1 <= nums[i], k <= nums.length`

---

## Solution & Editorial
# Intuition
Counting subarrays with *exactly* $k$ distinct integers can be difficult directly because the condition is non-monotonic with respect to a single sliding window boundary. However, we can use the identity: $\text{Exact}(k) = \text{AtMost}(k) - \text{AtMost}(k-1)$. This reduces the problem to finding the number of subarrays with at most $k$ distinct integers, which can be efficiently solved using a standard sliding window technique.

# Approach
1. Define a helper function `sub_atmost_k(nums, k)` that returns the total number of subarrays containing at most $k$ distinct integers.
2. In the helper function, maintain a sliding window defined by pointers `left` and `right`, along with a frequency map `map` to track the count of elements inside the current window.
3. Expand the window by incrementing `right`, adding `nums[right]` to the frequency map.
4. While the number of distinct elements (`map.size()`) exceeds `k`, shrink the window from the left by decrementing the count of `nums[left]` and incrementing `left`. If an element's frequency drops to zero, remove it completely from the map.
5. For each position of `right`, all subarrays ending at `right` and starting anywhere from `left` to `right` are valid (totaling `right - left + 1` subarrays). Accumulate this count into `ans`.
6. Finally, return `sub_atmost_k(nums, k) - sub_atmost_k(nums, k - 1)` from the main function.

### Visual Trace Walkthrough (Example 1: nums = [1, 2, 1, 2, 3], k = 2)
Computing `sub_atmost_k(nums, 2)`:
- `right = 0`, nums[0] = 1. Map: {1: 1}. Size = 1 <= 2. `ans` += (0 - 0 + 1) = 1. (Subarray: [1])
- `right = 1`, nums[1] = 2. Map: {1: 1, 2: 1}. Size = 2 <= 2. `ans` += (1 - 0 + 1) = 3. (Subarrays: [1, 2], [2])
- `right = 2`, nums[2] = 1. Map: {1: 2, 2: 1}. Size = 2 <= 2. `ans` += (2 - 0 + 1) = 6. (Subarrays: [1, 2, 1], [2, 1], [1])
- `right = 3`, nums[3] = 2. Map: {1: 2, 2: 2}. Size = 2 <= 2. `ans` += (3 - 0 + 1) = 10. 
- `right = 4`, nums[4] = 3. Map: {1: 2, 2: 2, 3: 1}. Size = 3 > 2. Shrink window: remove nums[0]=1, left becomes 1. Map: {1: 1, 2: 2, 3: 1}. Size still 3 > 2. Shrink again: remove nums[1]=2, left becomes 2. Map: {1: 1, 2: 1, 3: 1}. Size still 3 > 2. Shrink again: remove nums[2]=1, left becomes 3. Map: {2: 1, 3: 1}. Size = 2 <= 2. `ans` += (4 - 3 + 1) = 12.

Computing `sub_atmost_k(nums, 1)` yields `5`. 
Final Answer: `12 - 5 = 7`.

# Complexity
- Time complexity: $$O(N)$$ — Each element is visited at most twice by the `right` pointer and at most twice by the `left` pointer across the sliding window operations. Hash map insertions and deletions take $$O(1)$$ on average.
- Space complexity: $$O(K)$$ — The unordered map stores at most $k + 1$ distinct elements at any given time.

# Code
```cpp
class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int sub = sub_atmost_k(nums,k);
        int sub1 = sub_atmost_k(nums,k-1);
        return (sub - sub1);
    }
    int sub_atmost_k(vector<int>& nums,int k){
        unordered_map<int,int> map;
        int left = 0 , right = 0,ans = 0;
        while(right<nums.size()){
            map[nums[right]]++;
            while(map.size()>k){
                map[nums[left]]--;
                if(map[nums[left]]==0)map.erase(nums[left]);
                left++;
            }
            ans += right-left+1;
            right++;
        }
        return ans;
    }
};
```
