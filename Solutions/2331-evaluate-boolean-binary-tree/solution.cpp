/**
 * Problem: Evaluate Boolean Binary Tree (2331)
 * Link: https://leetcode.com/problems/evaluate-boolean-binary-tree/
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
    bool evaluateTree(TreeNode* root) {
        return dfs(root);
    }

    bool dfs(TreeNode* root){
        if(!root->left){
            return (root->val == 0 ? false : true);
        }else{
            if(root->val == 2){
                return dfs(root->left) || dfs(root->right);
            }else{
                return dfs(root->left) && dfs(root->right);
            }
        }

        return false;

    }


};
