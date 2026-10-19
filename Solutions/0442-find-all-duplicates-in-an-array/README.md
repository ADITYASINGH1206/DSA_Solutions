# [442. Find All Duplicates in an Array](https://leetcode.com/problems/find-all-duplicates-in-an-array/)
**Difficulty:** `Medium` | **Tags:** `array`, `hash-table`, `sorting`

---

## Problem Description
Given an integer array `nums` of length `n` where all the integers of `nums` are in the range `[1, n]` and each integer appears **at most** **twice**, return *an array of all the integers that appears **twice***.

You must write an algorithm that runs in `O(n)` time and uses only *constant* auxiliary space, excluding the space needed to store the output

**Example 1:**

```
Input: nums = [4,3,2,7,8,2,3,1]
Output: [2,3]
```

**Example 2:**

```
Input: nums = [1,1,2]
Output: [1]
```

**Example 3:**

```
Input: nums = [1]
Output: []
```

**Constraints:**

* `n == nums.length`
* `1 <= n <= 105`
* `1 <= nums[i] <= n`
* Each element in `nums` appears **once** or **twice**.

---

## Solution & Editorial
# Intuition
The problem requires us to identify all elements that appear twice in an array of size $$n$$ where all elements are constrained within the range $$[1, n]$$. Since elements can be tracked dynamically as we iterate, we can leverage a frequency map to record the occurrences of each number on the fly.

# Approach
1. Initialize an empty vector `ans` to store our duplicate values and an `unordered_map<int, int> mp` to keep track of the frequency of each number encountered.
2. Iterate through each element `num` in the `nums` array.
3. Check if `mp[num]` is already true (non-zero). If it is, this means `num` has already been seen once before, making it a duplicate, so we push `num` into `ans`.
4. If `mp[num]` is zero, increment the frequency count in the map for `num`.
5. Finally, return the `ans` vector containing all duplicate integers.

### Visual Trace Walkthrough (Example 1: `nums = [4, 3, 2, 7, 8, 2, 3, 1]`)

| Iteration | `num` | `mp` State Before | Action | `mp` State After | `ans` |
| :--- | :--- | :--- | :--- | :--- | :--- |
| 1 | 4 | `{}` | `mp[4]` is 0 | `{4: 1}` | `[]` |
| 2 | 3 | `{4: 1}` | `mp[3]` is 0 | `{4: 1, 3: 1}` | `[]` |
| 3 | 2 | `{4: 1, 3: 1}` | `mp[2]` is 0 | `{4: 1, 3: 1, 2: 1}` | `[]` |
| 4 | 7 | `{4: ...}` | `mp[7]` is 0 | `... 7: 1` | `[]` |
| 5 | 8 | `{...}` | `mp[8]` is 0 | `... 8: 1` | `[]` |
| 6 | 2 | `{..., 2: 1}` | `mp[2]` is > 0 (Duplicate!) | `{..., 2: 1}` | `[2]` |
| 7 | 3 | `{..., 3: 1}` | `mp[3]` is > 0 (Duplicate!) | `{..., 3: 1}` | `[2, 3]` |
| 8 | 1 | `{...}` | `mp[1]` is 0 | `... 1: 1` | `[2, 3]` |

# Complexity
- Time complexity: $$O(n)$$ — We iterate through the array of size $$n$$ once. Hash map insertions and lookups operate in $$O(1)$$ average time per element.
- Space complexity: $$O(n)$$ — In the worst-case scenario, all elements are unique or we store up to $$n$$ frequency counts in the hash map, plus auxiliary space for the result vector.

# Code
```cpp
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        unordered_map<int,int> mp;
        for(int num:nums){
            if(mp[num]) ans.push_back(num);
            else{
                mp[num]++;
            }
        }

        return ans;
    }
};
```
