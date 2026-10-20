/**
 * Problem: Number of Ways to Reorder Array to Get Same BST (1569)
 * Link: https://leetcode.com/problems/number-of-ways-to-reorder-array-to-get-same-bst/
 * Difficulty: Hard
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    long long mod = 1e9 + 7;
    vector<vector<long long>> table;
    void precomputeCombinations(int n) {
        table.assign(n + 1, vector<long long>(n + 1, 1));
        for (int i = 1; i <= n; ++i) {
            table[i][0] = 1;
            for (int j = 1; j < i; ++j) {
                table[i][j] = (table[i - 1][j - 1] + table[i - 1][j]) % mod;
            }
        }
    }

    long long dfs(const vector<int>& nums) {
        if (nums.size() <= 2) return 1;

        vector<int> left, right;
        int root = nums[0];

        for (size_t i = 1; i < nums.size(); ++i) {
            if (nums[i] < root) {
                left.push_back(nums[i]);
            } else {
                right.push_back(nums[i]);
            }
        }

        int l_size = left.size();
        int r_size = right.size();

        long long left_ways = dfs(left);
        long long right_ways = dfs(right);
        long long interleaving_ways = table[l_size + r_size][l_size];

        return (((interleaving_ways * left_ways) % mod) * right_ways) % mod;
    }

public:
    int numOfWays(vector<int>& nums) {
        int n = nums.size();
        precomputeCombinations(n);
        return (dfs(nums) - 1 + mod) % mod;
    }
};
