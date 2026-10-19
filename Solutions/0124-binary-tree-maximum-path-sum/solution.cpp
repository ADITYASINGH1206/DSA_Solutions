/**
 * Problem: Binary Tree Maximum Path Sum (124)
 * Link: https://leetcode.com/problems/binary-tree-maximum-path-sum/
 * Difficulty: Hard
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
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        maxPath(root,ans);
        return ans;
    }
    int maxPath(TreeNode* node,int& ans){
        if(node == NULL){
            return 0;
        }

        int lh = max(0,maxPath(node->left,ans));
        int rh = max(0,maxPath(node->right,ans));

        ans = max(ans,node->val + lh+rh);

        return node->val + max(lh,rh);
    }
    
};
