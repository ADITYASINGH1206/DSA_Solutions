/**
 * Problem: Maximum Difference Between Node and Ancestor (1026)
 * Link: https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/
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
    void dfs(TreeNode* root,int mini,int maxi,int& ans){
        if(root == NULL) return;

        ans = max(ans,max(abs(root->val-mini),abs(root->val-maxi)));
        mini = min(mini,root->val);
        maxi = max(maxi,root->val);

        dfs(root->left,mini,maxi,ans);
        dfs(root->right,mini,maxi,ans);
    }
    int maxAncestorDiff(TreeNode* root) {
        int ans = 0;
        dfs(root,root->val,root->val,ans);
        return ans;

    }
};
