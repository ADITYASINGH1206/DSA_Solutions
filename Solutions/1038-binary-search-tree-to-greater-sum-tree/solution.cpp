/**
 * Problem: Binary Search Tree to Greater Sum Tree (1038)
 * Link: https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/
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
    TreeNode* bstToGst(TreeNode* root) {
        int cur = 0;
        postorder(root,cur);
        return root;

    }
    void postorder(TreeNode* root,int& cur){
        if(root == NULL) return;

        postorder(root->right,cur);
        cur+= root->val;
        root->val = cur;
        postorder(root->left,cur);
        
    }
};
