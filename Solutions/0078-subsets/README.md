# [78. Subsets](https://leetcode.com/problems/subsets/)
**Difficulty:** `Medium` | **Tags:** `array`, `backtracking`, `bit-manipulation`

---

## Problem Description
Given an integer array `nums` of **unique** elements, return *all possible* *subsets* *(the power set)*.

The solution set **must not** contain duplicate subsets. Return the solution in **any order**.

**Example 1:**

```
Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
```

**Example 2:**

```
Input: nums = [0]
Output: [[],[0]]
```

**Constraints:**

* `1 <= nums.length <= 10`
* `-10 <= nums[i] <= 10`
* All the numbers of `nums` are **unique**.

---

## Solution & Editorial
# Intuition
The problem asks us to find all possible subsets (the power set) of a given array of unique integers. Since each element in the array can either be included or excluded in a subset, we can explore all binary choice combinations using backtracking (depth-first search).

# Code
```cpp
class Solution {
public:
    void backtrack(int i,vector<int>& nums,vector<int>& ds,vector<vector<int>>& ans){
        if(i == nums.size()){
            ans.push_back(ds);
            return;
        }

        ds.push_back(nums[i]);
        backtrack(i+1,nums,ds,ans);
        ds.pop_back();
        backtrack(i+1,nums,ds,ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        backtrack(0,nums,ds,ans);
        return ans;
    }
};
```
