/**
 * Problem: Binary Tree Paths (257)
 * Link: https://leetcode.com/problems/binary-tree-paths/
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
    void dfs(TreeNode* root, vector<string>& ans, vector<int>& path) {
        if (root == NULL) return;
        path.push_back(root->val);

        if (!root->left && !root->right) {
            string s = to_string(path[0]);
            for (int i = 1; i < path.size(); i++) {
                s += "->" + to_string(path[i]);
            }
            ans.push_back(s);
        } 
        else {
            dfs(root->left, ans, path);
            dfs(root->right, ans, path);
        }
        path.pop_back();
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        vector<int> path;
        dfs(root, ans, path);
        return ans;
    }
};
