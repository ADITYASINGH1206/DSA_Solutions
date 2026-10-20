/**
 * Problem: Kth Smallest Element in a BST (230)
 * Link: https://leetcode.com/problems/kth-smallest-element-in-a-bst/
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
    int kthSmallest(TreeNode* root, int k) {
        vector<int> result;
        traverse(root,result);
        return result[k-1];
    }

    void traverse(TreeNode* root,vector<int>& result){
        if(root == NULL) return;

        traverse(root->left,result);
        result.push_back(root->val);
        traverse(root->right,result);

    }
};
