/**
 * Problem: Count Good Nodes in Binary Tree (1448)
 * Link: https://leetcode.com/problems/count-good-nodes-in-binary-tree/
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
    void dfs(TreeNode* root,int& ans,int maxi){
        if(root == NULL) return;

        if(root->val >= maxi){
            maxi = root->val;
            ans++;
        }
        dfs(root->left,ans,maxi);
        dfs(root->right,ans,maxi);
    }
    int goodNodes(TreeNode* root) {
        int ans = 0;
        dfs(root,ans,root->val);
        return ans;

    }
};
