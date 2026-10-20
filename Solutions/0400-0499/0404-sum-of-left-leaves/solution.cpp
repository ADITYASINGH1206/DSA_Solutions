/**
 * Problem: Sum of Left Leaves (404)
 * Link: https://leetcode.com/problems/sum-of-left-leaves/
 * Difficulty: Easy
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
    void dfs(TreeNode* root,int& ans){
        if(root == NULL) return;

        if(root->left != NULL && !root->left->left && !root->left->right) ans+= root->left->val;
        dfs(root->left,ans);
        dfs(root->right,ans);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        int ans = 0;
        dfs(root,ans);
        return ans;
    }
};
