/**
 * Problem: Convert BST to Greater Tree (538)
 * Link: https://leetcode.com/problems/convert-bst-to-greater-tree/
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
    TreeNode* convertBST(TreeNode* root) {
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
