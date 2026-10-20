/**
 * Problem: Univalued Binary Tree (965)
 * Link: https://leetcode.com/problems/univalued-binary-tree/
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
    bool isUnivalTree(TreeNode* root) {
        bool ans = dfs(root,root->val,root->val);
        return ans;
    }
    bool dfs(TreeNode* root,int prev,int cur){
        if(root == NULL)return true;
        cur = root->val;
        if(prev != cur) return false;
        bool left = dfs(root->left,prev,cur);
        bool right = dfs(root->right,prev,cur);

        prev = cur;

        return (left&right);

    }
};
