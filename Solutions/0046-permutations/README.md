# [46. Permutations](https://leetcode.com/problems/permutations/)
**Difficulty:** `Medium` | **Tags:** `array`, `backtracking`

---

## Problem Description
Given an array `nums` of distinct integers, return all the possible permutations. You can return the answer in **any order**.

**Example 1:**

```
Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
```

**Example 2:**

```
Input: nums = [0,1]
Output: [[0,1],[1,0]]
```

**Example 3:**

```
Input: nums = [1]
Output: [[1]]
```

**Constraints:**

* `1 <= nums.length <= 6`
* `-10 <= nums[i] <= 10`
* All the integers of `nums` are **unique**.

---

## Solution & Editorial
# Intuition
To generate all permutations of an array of distinct integers, we can fix elements one by one at the current position and recursively permute the remaining suffix. By swapping elements in place, we avoid extra memory overhead for tracking visited states.

# Approach
1. Define a recursive helper function `solve(vector<int>& nums, int index)` which fixes the element at `index` and delegates the permutation of the remaining suffix starting from `index + 1`.
2. Base Case: When `index == nums.size()`, the current configuration of `nums` represents a complete permutation. Push a copy of `nums` into the global result vector `ans` and return.
3. Recursive Step: Iterate through all indices `i` from `index` to `nums.size() - 1`. Swap `nums[index]` with `nums[i]`, recurse on `index + 1`, and then backtrack by swapping `nums[index]` and `nums[i]` back to restore the original state.

### Visual Walkthrough for `nums = [1, 2, 3]`

| Call Step | `index` | `nums` State | Action / Description |
| :--- | :--- | :--- | :--- |
| `solve(nums, 0)` | `0` | `[1, 2, 3]` | Fix `nums[0]=1`, recurse with `index=1` |
| `solve(nums, 1)` | `1` | `[1, 2, 3]` | Fix `nums[1]=2`, recurse with `index=2` |
| `solve(nums, 2)` | `2` | `[1, 2, 3]` | Fix `nums[2]=3`, recurse with `index=3` |
| Base Case | `3` | `[1, 2, 3]` | `index == size`, push `[1, 2, 3]` to `ans` |
| Backtrack | `1` | `[1, 3, 2]` | Swap `nums[1]` and `nums[2]`, recurse with `index=2` |

# Complexity
- Time complexity: $$O(n \cdot n!)$$ — There are $$n!$$ possible permutations for an array of size $$n$$, and copying each permutation of length $$n$$ into the result takes $$O(n)$$ time.
- Space complexity: $$O(n)$$ — The auxiliary stack space required for recursion goes up to a maximum depth of $$n$$, excluding the memory required to store the output results.

# Code
```cpp
class Solution {
public:
    vector<vector<int>> ans;
    void solve(vector<int>& nums, int index) {
        if (index == nums.size()) {
            ans.push_back(nums);
            return;
        }
        for (int i = index; i < nums.size(); i++) {
            swap(nums[index], nums[i]);
            solve(nums, index + 1);
            swap(nums[index], nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        solve(nums, 0);
        return ans;
    }
};
```
