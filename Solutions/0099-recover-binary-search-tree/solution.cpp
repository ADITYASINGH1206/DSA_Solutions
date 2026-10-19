/**
 * Problem: Recover Binary Search Tree (99)
 * Link: https://leetcode.com/problems/recover-binary-search-tree/
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
    TreeNode* first = nullptr;
    TreeNode* second = nullptr;
    TreeNode* prev = nullptr;
    void recoverTree(TreeNode* root) {
        inorder(root);
        swap(first->val,second->val);
    }
    void inorder(TreeNode* root){
        if(root == NULL) return;

        inorder(root->left);

        if(prev != NULL && root->val < prev->val){
            if(first == nullptr) first = prev;
            second = root;
        }

        prev = root;
        inorder(root->right);
    }

};
