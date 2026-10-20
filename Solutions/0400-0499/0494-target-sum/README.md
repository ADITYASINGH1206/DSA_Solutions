# [494. Target Sum](https://leetcode.com/problems/target-sum/)
**Difficulty:** `Medium` | **Tags:** `array`, `dynamic-programming`, `backtracking`, `knapsack-problem`, `0-1-knapsack`

---

## Problem Description
You are given an integer array `nums` and an integer `target`.

You want to build an **expression** out of nums by adding one of the symbols `'+'` and `'-'` before each integer in nums and then concatenate all the integers.

* For example, if `nums = [2, 1]`, you can add a `'+'` before `2` and a `'-'` before `1` and concatenate them to build the expression `"+2-1"`.

Return the number of different **expressions** that you can build, which evaluates to `target`.

**Example 1:**

```
Input: nums = [1,1,1,1,1], target = 3
Output: 5
Explanation: There are 5 ways to assign symbols to make the sum of nums be target 3.
-1 + 1 + 1 + 1 + 1 = 3
+1 - 1 + 1 + 1 + 1 = 3
+1 + 1 - 1 + 1 + 1 = 3
+1 + 1 + 1 - 1 + 1 = 3
+1 + 1 + 1 + 1 - 1 = 3
```

**Example 2:**

```
Input: nums = [1], target = 1
Output: 1
```

**Constraints:**

* `1 <= nums.length <= 20`
* `0 <= nums[i] <= 1000`
* `0 <= sum(nums[i]) <= 1000`
* `-1000 <= target <= 1000`

---

## Solution & Editorial
# Intuition
This problem asks us to find the number of ways to assign either a '+' or '-' sign to each element in the `nums` array such that the total sum equals the given `target`. Since every element has two independent choices, we can model this as a binary decision tree and explore all possible expression combinations using depth-first search backtracking.

# Approach
1. Define a recursive helper function `backtrack` that takes the original `nums` array, the `target` value, the current index `ind`, the running `sum`, and a reference to the counter `ans`.
2. Base Case: When `ind` reaches the size of `nums` (`n`), check if the accumulated `sum` equals the `target`. If it matches, increment `ans` by 1 and return.
3. Recursive Steps: For each element at index `ind`, branch into two choices: add `nums[ind]` to the running sum or subtract `nums[ind]` from the running sum, advancing `ind` to `ind + 1` in both recursive calls.
4. In the main function `findTargetSumWays`, initialize `ans` to 0, invoke `backtrack` starting from index 0 with a sum of 0, and return `ans`.

### Visual Walkthrough for `nums = [1, 1]`, `target = 0`
- Start at `ind = 0`, `sum = 0`
  - Branch 1: `ind = 1`, `sum = 1`
    - Branch 1.1: `ind = 2`, `sum = 2` (Mismatch, `2 != 0`)
    - Branch 1.2: `ind = 2`, `sum = 0` (Match! `ans` increments)
  - Branch 2: `ind = 1`, `sum = -1`
    - Branch 2.1: `ind = 2`, `sum = 0` (Match! `ans` increments)
    - Branch 2.2: `ind = 2`, `sum = -2` (Mismatch, `-2 != 0`)
- Total matching paths = 2.

# Complexity
- Time complexity: $$O(2^N)$$ where $$N$$ is the number of elements in `nums`. Each element presents 2 choices ('+' or '-'), yielding a binary recursion tree of depth $$N$$ and $$2^N$$ total leaf nodes.
- Space complexity: $$O(N)$$ corresponding to the maximum depth of the recursion stack during the depth-first traversal.

# Code
```cpp
class Solution {
public:
    void backtrack(vector<int>&nums,int target,int ind,int sum,int& ans){
        int n = nums.size();
        if(ind == n){
            if(sum == target) ans++;
            return;
        }

        backtrack(nums,target,ind+1,sum+nums[ind],ans);
        backtrack(nums,target,ind+1,sum-nums[ind],ans);
        
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int ans = 0;
        backtrack(nums,target,0,0,ans);
        return ans;
    }
};
```
