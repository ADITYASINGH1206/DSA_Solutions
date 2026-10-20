# [416. Partition Equal Subset Sum](https://leetcode.com/problems/partition-equal-subset-sum/)
**Difficulty:** `Medium` | **Tags:** `array`, `dynamic-programming`, `knapsack-problem`, `0-1-knapsack`

---

## Problem Description
Given an integer array `nums`, return `true` *if you can partition the array into two subsets such that the sum of the elements in both subsets is equal or* `false` *otherwise*.

**Example 1:**

```
Input: nums = [1,5,11,5]
Output: true
Explanation: The array can be partitioned as [1, 5, 5] and [11].
```

**Example 2:**

```
Input: nums = [1,2,3,5]
Output: false
Explanation: The array cannot be partitioned into equal sum subsets.
```

**Constraints:**

* `1 <= nums.length <= 200`
* `1 <= nums[i] <= 100`

---

## Solution & Editorial
# Intuition
This problem can be transformed into the classic 0/1 Knapsack problem. If the sum of all elements in the array is odd, it is impossible to partition it into two subsets with equal sums. If the sum is even, the problem reduces to finding whether there exists a subset of elements whose sum is exactly equal to half of the total sum (target = sum / 2).

# Approach
1. Calculate the total sum of the array using `accumulate`. If the sum is odd, immediately return `false`.
2. Define `target = sum / 2` and create a 2D boolean DP table `dp` of size `n x (target + 1)` initialized to `false`, where `dp[i][j]` represents whether a subset sum equal to `j` can be formed using a subset of the elements from index `0` to `i`.
3. Base cases: `dp[i][0]` is set to `true` for all `i` because a sum of `0` can always be formed by taking an empty subset. Also, `dp[0][nums[0]] = true` if `nums[0] <= target`.
4. Iterate through each element from index `1` to `n-1` and for each target sum from `1` to `target`, compute `notTake = dp[i-1][j]` and `take = dp[i-1][j-nums[i]]` (if `nums[i] <= j`). Set `dp[i][j] = take | notTake`.
5. Return the final result located at `dp[n-1][target]`.

### Visual Trace Walkthrough (Example 1: nums = [1, 5, 11, 5])
Total sum = 22. Target = 11. `dp` table size: $4 \times 12$.
- Initial state: `dp[i][0] = true` for all rows.
- Row 0 (`nums[0] = 1`): `dp[0][1] = true`
- Row 1 (`nums[1] = 5`): Combines previous possibilities, setting `dp[1][5]`, `dp[1][6]` to `true`.
- Row 2 (`nums[2] = 11`): Sets `dp[2][11] = true` since `11 - 11 = 0` (which was valid).
- Final cell `dp[3][11]` evaluates to `true`.

# Complexity
- Time complexity: $$O(N \times \text{target})$$, where $$N$$ is the number of elements in `nums` and `\text{target}` is the half of the total sum. We iterate through a nested loop of size $$N \times \text{target}$$.
- Space complexity: $$O(N \times \text{target})$$ due to the allocation of the 2D boolean DP table of dimensions `n` by `target + 1`.

# Code
```cpp
//Tabulation
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum%2 == 1) return false;
        int target = sum/2;
        vector<vector<bool>> dp(n,vector<bool>(target+1,false));
        for(int i =0;i<n;i++) dp[i][0] = true;
        if(nums[0] <= target) dp[0][nums[0]] = true;
        for(int i =1;i<n;i++){
            for(int j =1;j<=target;j++){
                bool notTake = dp[i-1][j];
                bool take = false;
                if(nums[i]<=j) take = dp[i-1][j-nums[i]];
                dp[i][j]=take | notTake;
            }
        }
        return dp[n-1][target];
    }
};

//MEMO
// class Solution {
// public:
//     bool subsetSum(int ind,int target,vector<int> nums,vector<vector<int>>& dp){
//         if(target == 0) return true;
//         if(ind ==0 ) return nums[ind] == target;

//         if(dp[ind][target] != -1) return dp[ind][target];

//         bool notTake = subsetSum(ind-1,target,nums,dp);
//         bool take = false;
//         if(nums[ind] <= target) take = subsetSum(ind-1,target-nums[ind],nums,dp);

//         return dp[ind][target] = take | notTake;
//     }
//     bool canPartition(vector<int>& nums) {
//         int n = nums.size();
//         int sum = accumulate(nums.begin(),nums.end(),0);
//         if(sum%2 !=0 )return false;
//         int target = sum/2;
//         vector<vector<int>> dp(n,vector<int>(target+1,-1));
//         return subsetSum(n-1,target,nums,dp);
//     }
// };
```
