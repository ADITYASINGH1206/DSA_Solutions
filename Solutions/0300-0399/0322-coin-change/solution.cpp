/**
 * Problem: Coin Change (322)
 * Link: https://leetcode.com/problems/coin-change/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

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
