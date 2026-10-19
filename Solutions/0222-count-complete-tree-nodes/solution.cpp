/**
 * Problem: Count Complete Tree Nodes (222)
 * Link: https://leetcode.com/problems/count-complete-tree-nodes/
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
    int countNodes(TreeNode* root) {
        int ans = 0;
        height(root,ans);
        return ans;
    }
    void height(TreeNode* temp,int& ans){
        if(temp == NULL){
            return ;
        }

        ans++;
        height(temp->left,ans);
        height(temp->right,ans);
        
    }
};
