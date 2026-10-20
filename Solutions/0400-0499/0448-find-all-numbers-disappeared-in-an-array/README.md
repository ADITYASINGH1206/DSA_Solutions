# [448. Find All Numbers Disappeared in an Array](https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/)
**Difficulty:** `Easy` | **Tags:** `array`, `hash-table`

---

## Problem Description
Given an array `nums` of `n` integers where `nums[i]` is in the range `[1, n]`, return *an array of all the integers in the range* `[1, n]` *that do not appear in* `nums`.

**Example 1:**

```
Input: nums = [4,3,2,7,8,2,3,1]
Output: [5,6]
```

**Example 2:**

```
Input: nums = [1,1]
Output: [2]
```

**Constraints:**

* `n == nums.length`
* `1 <= n <= 105`
* `1 <= nums[i] <= n`

**Follow up:** Could you do it without extra space and in `O(n)` runtime? You may assume the returned list does not count as extra space.

---

## Solution & Editorial
# Intuition
The problem asks us to find all integers in the range $$[1, n]$$ that are missing from an array of size $$n$$. Since all values in `nums` fall within the valid range $$[1, n]$$, we can use a frequency vector of size $$n + 1$$ to count the occurrences of each element and then identify numbers with a frequency of zero.

# Approach
1. Initialize a frequency vector `freq` of size `nums.size() + 1` filled with zeros, and an empty vector `ans` to store the missing numbers.
2. Iterate through each element in `nums` and increment its corresponding count in `freq` using `freq[nums[i]]++`.
3. Iterate from index `1` to `nums.size()`. If `freq[i]` is equal to `0`, it means `i` never appeared in `nums`, so append `i` to `ans`.
4. Return `ans` containing all missing numbers.

### Visual Walkthrough (Example 1: `nums = [4,3,2,7,8,2,3,1]`, $$n = 8$$)
- Initial `freq` of size 9: `[0, 0, 0, 0, 0, 0, 0, 0, 0]`
- After counting elements in `nums`:
  `freq` becomes `[0, 1, 2, 2, 1, 0, 0, 1, 1]`
- Scanning `freq` from 1 to 8:
  - `i = 1`: freq[1] = 1
  - `i = 2`: freq[2] = 2
  - `i = 3`: freq[3] = 2
  - `i = 4`: freq[4] = 1
  - `i = 5`: freq[5] = 0 -> push 5 to `ans`
  - `i = 6`: freq[6] = 0 -> push 6 to `ans`
  - `i = 7`: freq[7] = 1
  - `i = 8`: freq[8] = 1
- Final `ans`: `[5, 6]`

# Complexity
- Time complexity: $$O(n)$$ — We perform two linear passes: one to populate the frequency array of size $$n$$ and another to scan it from $$1$$ to $$n$$.
- Space complexity: $$O(n)$$ — We allocate an auxiliary `freq` vector of size $$n + 1$$. The space required for the output array `ans` is excluded per problem convention.

# Code
```cpp
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int>freq(nums.size()+1,0);
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            freq[nums[i]]++;
        }
        for(int i=1;i<=nums.size();i++){
            if(freq[i] ==0){
                ans.push_back(i);
            }
        }
        return ans;
    }
};
```
