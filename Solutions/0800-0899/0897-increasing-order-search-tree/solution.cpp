/**
 * Problem: Increasing Order Search Tree (897)
 * Link: https://leetcode.com/problems/increasing-order-search-tree/
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
    void Inorder(TreeNode* root,vector<int>&in){
        if(!root) return;

        Inorder(root->left,in);
        in.push_back(root->val);
        Inorder(root->right,in);
    }

    TreeNode* create(vector<int>&in, int index){
        if(index>=in.size()){
            return NULL;
        }

        TreeNode* root = new TreeNode(in[index]);
        root->left = NULL;
        root->right = create(in,index+1);

        return root;
    }

    TreeNode* increasingBST(TreeNode* root) {
        vector<int>in;
        Inorder(root,in);
        return create(in,0);
    }
};
