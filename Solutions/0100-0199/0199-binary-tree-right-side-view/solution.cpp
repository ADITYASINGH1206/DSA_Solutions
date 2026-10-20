/**
 * Problem: Binary Tree Right Side View (199)
 * Link: https://leetcode.com/problems/binary-tree-right-side-view/
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
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        traversal(root, ans,0);
        return ans;
    }
    void traversal(TreeNode* node, vector<int>& ans,int depth) {
        if (node == nullptr) {
            return;
        }
        if (depth == ans.size()) {
            ans.push_back(node->val);
        }
        traversal(node->right, ans, depth + 1);
        traversal(node->left, ans, depth + 1);
    }
};
