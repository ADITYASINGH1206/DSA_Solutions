/**
 * Problem: Two Sum IV - Input is a BST (653)
 * Link: https://leetcode.com/problems/two-sum-iv-input-is-a-bst/
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
    bool findTarget(TreeNode* root, int k) {
        vector<int> inorder;
        traverse(root,inorder);
        int l = 0;
        int h = inorder.size()-1;
        while(l<h){
            if(inorder[l]+inorder[h] == k) return true;
            else if(inorder[l] + inorder[h] > k) h--;
            else l++;
        }
        return false;
    }

    void traverse(TreeNode* root,vector<int>& inorder){
        if(root == NULL) return;

        traverse(root->left,inorder);
        inorder.push_back(root->val);
        traverse(root->right,inorder);
    }
};
