# [518. Coin Change II](https://leetcode.com/problems/coin-change-ii/)
**Difficulty:** `Medium` | **Tags:** `array`, `dynamic-programming`, `knapsack-problem`, `complete-knapsack`

---

## Problem Description
You are given an integer array `coins` representing coins of different denominations and an integer `amount` representing a total amount of money.

Return *the number of combinations that make up that amount*. If that amount of money cannot be made up by any combination of the coins, return `0`.

You may assume that you have an infinite number of each kind of coin.

The **final** answer is **guaranteed** to fit into a signed **32-bit** integer.

**Example 1:**

```
Input: amount = 5, coins = [1,2,5]
Output: 4
Explanation: there are four ways to make up the amount:
5=5
5=2+2+1
5=2+1+1+1
5=1+1+1+1+1
```

**Example 2:**

```
Input: amount = 3, coins = [2]
Output: 0
Explanation: the amount of 3 cannot be made up just with coins of 2.
```

**Example 3:**

```
Input: amount = 10, coins = [10]
Output: 1
```

**Constraints:**

* `1 <= coins.length <= 300`
* `1 <= coins[i] <= 5000`
* All the values of `coins` are **unique**.
* `0 <= amount <= 5000`

---

## Solution & Editorial
# Intuition
This problem asks for the number of unique combinations to make up a given amount using an infinite supply of coin denominations. Since order does not matter in combinations and coins can be reused, we can formulate this as a classic unbounded knapsack problem. We can use top-down dynamic programming with memoization to avoid redundant subproblem evaluations.

# Approach
1. Define a recursive function `countWays(ind, amount, coins, memo)` where `ind` represents the current coin index being considered and `amount` is the remaining target.
2. Base Cases:
   - If `amount == 0`, we have successfully formed the target amount, so return `1`.
   - If `amount < 0` or `ind == coins.size()`, we cannot form the amount, so return `0`.
3. Check if the subproblem result `memo[ind][amount]` is already computed. If so, return the cached value.
4. Branch into two choices:
   - `take`: Include the current coin by calling `countWays(ind, amount - coins[ind], coins, memo)`. Notice `ind` does not increment because we can reuse the same coin.
   - `skip`: Exclude the current coin by calling `countWays(ind + 1, amount, coins, memo)`.
5. Cache and return the sum of both choices: `memo[ind][amount] = take + skip`.

### Visual Trace Walkthrough
For `amount = 5`, `coins = [1, 2, 5]`:

| State `(ind, amount)` | `take` Choice | `skip` Choice | Result | Explanation |
| :--- | :--- | :--- | :--- | :--- |
| `(2, 5)` [coin=5] | `(2, 0)` -> 1 | `(3, 5)` -> 0 | `1 + 0 = 1` | Using coin 5 once |
| `(1, 1)` [coin=2] | `(1, -1)` -> 0 | `(2, 1)` -> 1 | `0 + 1 = 1` | Remaining amount formed by smaller coins |
| `(0, 5)` [coin=1] | `(0, 4)` -> 4 | `(1, 5)` -> 1 | `4 + 1 = 5` | Total ways including or skipping coin 1 |

# Complexity
- Time complexity: $$O(N \times \text{amount})$$, where $$N$$ is the number of coins and `amount` is the target value. Each state `(ind, amount)` is computed at most once and takes $$O(1)$$ time.
- Space complexity: $$O(N \times \text{amount})$$ to store the memoization table, plus $$O(N + \text{amount})$$ for the recursion stack depth.

# Code
```cpp
//Memo
class Solution {
public:
    int countWays(int ind, int amount, vector<int>& coins, vector<vector<int>>& memo) {
        if (amount == 0) return 1;
        if (amount < 0 || ind == coins.size()) return 0;

        if (memo[ind][amount] != -1) return memo[ind][amount];
        
        int take = countWays(ind, amount - coins[ind], coins, memo);
        int skip = countWays(ind + 1, amount, coins, memo);
        
        return memo[ind][amount] = take + skip;
    }
    
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> memo(coins.size(), vector<int>(amount + 1, -1));
        return countWays(0, amount, coins, memo);
    }
};

//Recurse
// class Solution {
// public:
//     void coin(vector<int>& coins,int target,int sum,vector<int> way,set<vector<int>>& ways){
//         if(sum == target){
//             vector<int> temp = way;
//             sort(temp.begin(),temp.end());
//             ways.insert(temp);
//             return;
//         } 

//         if(sum > target) return;
//         for(int i =0;i<coins.size();i++){
//             way.push_back(coins[i]);
//             coin(coins,target,sum+coins[i],way,ways);
//             way.pop_back();
//         }
//     }
//     int change(int amount, vector<int>& coins) {
//         int ans = 0;
//         set<vector<int>> ways;
//         vector<int> way;
//         coin(coins,amount,0,way,ways);
//         return ways.size();
//     }
// };
```
