/**
 * Problem: Flatten Binary Tree to Linked List (114)
 * Link: https://leetcode.com/problems/flatten-binary-tree-to-linked-list/
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
    TreeNode* prev = NULL;
    void flatten(TreeNode* root) {
        TreeNode* temp = root;

        if(temp == NULL)return;

        flatten(temp->right);
        flatten(temp->left);
        temp->right = prev;
        temp->left = NULL;
        prev = temp; 
    }
};
