/**
 * Problem: Find Elements in a Contaminated Binary Tree (1261)
 * Link: https://leetcode.com/problems/find-elements-in-a-contaminated-binary-tree/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 * int val;
 * TreeNode *left;
 * TreeNode *right;
 * TreeNode() : val(0), left(nullptr), right(nullptr) {}
 * TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class FindElements {
private:
    unordered_set<int> values;
    void dfs(TreeNode* node, int current_val) {
        if (node == nullptr) return;
        node->val = current_val;
        values.insert(current_val);
        dfs(node->left, 2 * current_val + 1);
        dfs(node->right, 2 * current_val + 2);
    }

public:
    FindElements(TreeNode* root) {
        dfs(root, 0);
    }
    
    bool find(int target) {
        return values.count(target) > 0;
    }
};
