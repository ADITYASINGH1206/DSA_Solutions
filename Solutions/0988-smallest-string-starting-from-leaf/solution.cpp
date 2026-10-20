/**
 * Problem: Smallest String Starting From Leaf (988)
 * Link: https://leetcode.com/problems/smallest-string-starting-from-leaf/
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
    void dfs(TreeNode* node, string path, string& ans) {
        if (node == nullptr) return;
        path += char('a' + node->val);
        if (node->left == nullptr && node->right == nullptr) {
            reverse(path.begin(), path.end());
            if (ans.empty() || path < ans) {
                ans = path;
            }
            reverse(path.begin(), path.end()); 
        }
        dfs(node->left, path, ans);
        dfs(node->right, path, ans);
    }
    string smallestFromLeaf(TreeNode* root) {
        string ans;
        dfs(root, "", ans);
        return ans;
    }
    

};
