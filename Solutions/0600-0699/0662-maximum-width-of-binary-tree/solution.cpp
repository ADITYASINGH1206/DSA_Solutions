/**
 * Problem: Maximum Width of Binary Tree (662)
 * Link: https://leetcode.com/problems/maximum-width-of-binary-tree/
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
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (root == NULL) return 0;
        
        int ans = 0;
        queue<pair<TreeNode*, unsigned int>> q;
        q.push({root, 0});
        
        while (!q.empty()) {
            int n = q.size();
            unsigned int min_idx = q.front().second; 
            unsigned int first, last;
            
            for (int i = 0; i < n; i++) {
                unsigned int cur_id = q.front().second - min_idx;
                TreeNode* temp = q.front().first;
                q.pop();
                
                if (i == 0) first = cur_id;
                if (i == n - 1) last = cur_id;
                
                if (temp->left != NULL) {
                    q.push({temp->left, cur_id * 2 + 1});
                }
                if (temp->right != NULL) {
                    q.push({temp->right, cur_id * 2 + 2});
                }
            }
            
            ans = max(ans, static_cast<int>(last - first + 1));
        }
        return ans;
    }
};
