/**
 * Problem: Path Sum III (437)
 * Link: https://leetcode.com/problems/path-sum-iii/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void backtrack(TreeNode* root, int target, long long sum, unordered_map<long long, int>& mp, int& ans) {
        if (root == NULL) return;
        
        sum += root->val;
        
        if (mp.count(sum - target)) {
            ans += mp[sum - target];
        }
        mp[sum]++;
        
        backtrack(root->left, target, sum, mp, ans);
        backtrack(root->right, target, sum, mp, ans);
        
        mp[sum]--;
    }
    
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long long, int> mp;
        mp[0] = 1; 
        int ans = 0;
        backtrack(root, targetSum, 0, mp, ans);
        return ans;
    }
};
