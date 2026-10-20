/**
 * Problem: Coin Change II (518)
 * Link: https://leetcode.com/problems/coin-change-ii/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

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
