# [198. House Robber](https://leetcode.com/problems/house-robber/)
**Difficulty:** `Medium` | **Tags:** `array`, `dynamic-programming`

---

## Problem Description
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and **it will automatically contact the police if two adjacent houses were broken into on the same night**.

Given an integer array `nums` representing the amount of money of each house, return *the maximum amount of money you can rob tonight **without alerting the police***.

**Example 1:**

```
Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.
```

**Example 2:**

```
Input: nums = [2,7,9,3,1]
Output: 12
Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
Total amount you can rob = 2 + 9 + 1 = 12.
```

**Constraints:**

* `1 <= nums.length <= 100`
* `0 <= nums[i] <= 400`

---

## Solution & Editorial
# Intuition
To maximize the stolen money without alerting the police, we can break the problem down into a sequence of optimal sub-choices. At each house, we have two options: either rob the current house (which means we cannot rob the immediately preceding house) or skip the current house and keep the maximum loot from the previous house. This optimal substructure allows us to solve the problem using dynamic programming.

# Approach
1. Initialize two variables, `prev1` and `prev2`, representing the maximum profit up to the previous house and two houses back, respectively. Both start at `0`.
2. Iterate through each house `i` in the input array `nums`.
3. For each house, calculate `pick` as the sum of `nums[i]` and `prev2` (since robbing house `i` excludes robbing house `i-1`). Calculate `notPick` as `prev1` (carrying over the maximum loot without robbing house `i`).
4. Determine the maximum profit for the current house as `current = max(pick, notPick)`.
5. Shift the tracking variables forward: update `prev2 = prev1` and `prev1 = current`.
6. After iterating through all houses, return `prev1` as the final maximum loot.

### Visual Trace Walkthrough (Example 1: `nums = [1, 2, 3, 1]`)

| `i` | `nums[i]` | `prev2` | `prev1` | `pick` (`nums[i] + prev2`) | `notPick` (`prev1`) | `current` (`max(pick, notPick)`) | New `prev2` | New `prev1` |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| 0 | 1 | 0 | 0 | $1 + 0 = 1$ | $0$ | $\max(1, 0) = 1$ | 0 | 1 |
| 1 | 2 | 0 | 1 | $2 + 0 = 2$ | $1$ | $\max(2, 1) = 2$ | 1 | 2 |
| 2 | 3 | 1 | 2 | $3 + 1 = 4$ | $2$ | $\max(4, 2) = 4$ | 2 | 4 |
| 3 | 1 | 2 | 4 | $1 + 2 = 3$ | $4$ | $\max(3, 4) = 4$ | 4 | 4 |

Final output: `4`.

# Complexity
- Time complexity: $$O(N)$$ where $$N$$ is the number of houses in `nums`. We perform a single linear scan through the array.
- Space complexity: $$O(1)$$ auxiliary space. We only use two variables (`prev1` and `prev2`) to maintain the state, dropping the $$O(N)$$ space complexity of standard DP tables.

# Code
```cpp
class Solution{
public:
    int rob(vector<int>& nums){
        int n = nums.size();
        if(n == 0) return 0;

        int prev1= 0;
        int prev2= 0;

        for(int i=0;i<n;i++){
            int pick = nums[i] + prev2;
            int notPick = prev1;

            int current = max(pick,notPick);

            prev2 = prev1;
            prev1 = current;
        }
        return prev1;
    }

};

// class Solution{
// public:
//     int rob(vector<int> & nums){
//         int n = nums.size();
//         vector<int> dp(n,-1);
//         dp[0] = nums[0];
//         for(int i = 1;i<n;i++){
//             int pick = nums[i];
//             if(i>1) pick+= dp[i-2];
//             int notPick = 0 + dp[i-1];
//             dp[i] = max(pick,notPick);
//         }
//         return dp[n-1];
//     }
// };


// class Solution {
// public:
//     int f(int ind,vector<int>& nums,vector<int>& dp){
//         if(ind == 0)return nums[ind];
//         if(ind < 0)return 0;

//         if(dp[ind] != -1) return dp[ind];

//         int pick = nums[ind] +f(ind-2,nums,dp);
//         int notPick = 0 + f(ind-1,nums,dp);

//         return dp[ind] = max(pick,notPick);

//     }
//     int rob(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> dp(n,-1);
//         return f(n-1,nums,dp);
//     }
// };
```
