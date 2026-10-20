/**
 * Problem: Count Dominant Nodes in a Binary Tree (3997)
 * Link: https://leetcode.com/problems/count-dominant-nodes-in-a-binary-tree/
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
    int cnt=0;
    int dfs(TreeNode* root){
        if(root == NULL)return 0;

        int left=dfs(root->left);
        int right=dfs(root->right);

        if(root->val>=max(left,right))cnt++; 
        return max({root->val,left,right}); 
    }
    int countDominantNodes(TreeNode* root) {
        dfs(root);
        return cnt;
    }
};
