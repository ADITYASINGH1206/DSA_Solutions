# [322. Coin Change](https://leetcode.com/problems/coin-change/)
**Difficulty:** `Medium` | **Tags:** `array`, `dynamic-programming`, `breadth-first-search`, `knapsack-problem`, `complete-knapsack`

---

## Problem Description
You are given an integer array `coins` representing coins of different denominations and an integer `amount` representing a total amount of money.

Return the **fewest** number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

You may assume that you have an infinite number of each kind of coin.

**Example 1:**

```
Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1
```

**Example 2:**

```
Input: coins = [2], amount = 3
Output: -1
```

**Example 3:**

```
Input: coins = [1], amount = 0
Output: 0
```

**Constraints:**

* `1 <= coins.length <= 12`
* `1 <= coins[i] <= 231 - 1`
* `0 <= amount <= 104`

---

## Solution & Editorial
# Intuition
The problem asks for the minimum number of coins needed to make up a given amount. Since we have an infinite supply of each coin and choices at each step affect future possibilities, this is a classic unbounded knapsack variation. We can use dynamic programming tabulation to build up the solution from amount 0 to the target amount.

# Approach
1. Initialize a 1D DP vector `dp` of size `amount + 1` with a sentinel value greater than any possible valid coin count (such as `amount + 1`).
2. Set base case `dp[0] = 0`, because 0 coins are required to make an amount of 0.
3. Iterate through every sub-amount `i` from 1 up to `amount`.
4. For each sub-amount `i`, iterate through each available `coin` in `coins`. If `i - coin >= 0`, transition by taking `min(dp[i], 1 + dp[i - coin])`.
5. After filling the DP table, check if `dp[amount]` is still greater than `amount`. If so, return `-1` since the amount cannot be formed; otherwise, return `dp[amount]`.

### Visual Dry Run (Example 1: coins = [1, 2, 5], amount = 6)
- `dp` initialized to `[0, 7, 7, 7, 7, 7, 7]` (where 7 represents infinity sentinel `amount + 1`).
- `i = 1`: check coins [1, 2, 5] -> `dp[1] = min(7, 1 + dp[0]) = 1`
- `i = 2`: check coins [1, 2, 5] -> `dp[2] = min(7, 1 + dp[1], 1 + dp[0]) = 1`
- `i = 3`: check coins [1, 2, 5] -> `dp[3] = min(7, 1 + dp[2], 1 + dp[1]) = 2`
- `i = 4`: check coins [1, 2, 5] -> `dp[4] = min(7, 1 + dp[3], 1 + dp[2]) = 2`
- `i = 5`: check coins [1, 2, 5] -> `dp[5] = min(7, 1 + dp[4], 1 + dp[3], 1 + dp[0]) = 1`
- `i = 6`: check coins [1, 2, 5] -> `dp[6] = min(7, 1 + dp[5], 1 + dp[4], 1 + dp[1]) = 2`

# Complexity
- Time complexity: $$O(\text{amount} \times n)$$ where $n$ is the number of coins. We have an outer loop running `amount` times and an inner loop running once per coin.
- Space complexity: $$O(\text{amount})$$ for storing the 1D DP table of size `amount + 1`.

# Code
```cpp
//Tabulation
class Solution{
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount+1);
        dp[0] = 0;

        for(int i =1;i<=amount;i++){
            for(int coin:coins){
                if(i-coin>=0){
                    dp[i] = min(dp[i],1+dp[i-coin]);
                }
            }
        }
        return dp[amount] > amount ? -1 : dp[amount];
    }
};

//Memo
// class Solution{
// public:
//     int moves(vector<int>& coins,int rem,vector<int>& memo){
//         if(rem == 0) return 0;
//         if(rem <0) return 1e9;

//         if(memo[rem] != -1) return memo[rem];

//         int min_coins = 1e9;
//         for(int i =0;i<coins.size();i++){
//             int res= moves(coins,rem-coins[i],memo);
//             if(res!=1e9) min_coins=min(min_coins,res+1);
//         }
//         return memo[rem] = min_coins;
//     }
//     int coinChange(vector<int>& coins, int amount) {
//         vector<int> memo(amount + 1, -1);
        
//         int ans = moves(coins, amount, memo);
//         return ans == 1e9 ? -1 : ans; 
//     }
// };




//Recurse
// class Solution {
// public:
//     int moves(vector<int>& coins, int rem) {
//         if (rem == 0) return 0;
//         if (rem < 0) return 1e9; 

//         int min_coins = 1e9;
        
//         for (int i = 0; i < coins.size(); i++) {
//             int res = moves(coins, rem - coins[i]);
//             if (res != 1e9) {
//                 min_coins = min(min_coins, res + 1);
//             }
//         }
        
//         return min_coins;
//     }
    
//     int coinChange(vector<int>& coins, int amount) {
//         int ans = moves(coins, amount);
//         return ans == 1e9 ? -1 : ans; 
//     }
// };
```
