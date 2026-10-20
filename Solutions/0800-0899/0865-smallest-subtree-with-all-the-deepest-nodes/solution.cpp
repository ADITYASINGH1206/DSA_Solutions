/**
 * Problem: Smallest Subtree with all the Deepest Nodes (865)
 * Link: https://leetcode.com/problems/smallest-subtree-with-all-the-deepest-nodes/
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
    int maxi(TreeNode* root){
        if(!root) return 0;
        int lh = maxi(root->left);
        int rh = maxi(root->right);

        return 1 + max(lh,rh);
    }
    TreeNode* dfs(TreeNode* root, int maxi, int len) {
        if (!root) return nullptr;  
        if (maxi - 1 == len) return root;
        TreeNode* left = dfs(root->left, maxi, len + 1);
        TreeNode* right = dfs(root->right, maxi, len + 1);
        
        if (left && right) return root;
        return left ? left : right;
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        int maxx = maxi(root);
        return dfs(root,maxx,0);
    }
};
