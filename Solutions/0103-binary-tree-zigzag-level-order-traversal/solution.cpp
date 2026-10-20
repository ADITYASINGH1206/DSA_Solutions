/**
 * Problem: Binary Tree Zigzag Level Order Traversal (103)
 * Link: https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL) return ans;
        queue<TreeNode*> q;
        q.push(root);
        int cur = 1;
        while(!q.empty()){
            int s = q.size();
            vector<int> v;
            for(int i = 0;i<s;i++){
                TreeNode* temp = q.front();
                q.pop();
                if(temp->left != NULL) q.push(temp->left);
                if(temp->right != NULL) q.push(temp->right);
                v.push_back(temp->val);
            }
            if(cur == 1){
                ans.push_back(v);
                cur = -1;
            }else{
                reverse(v.begin(),v.end());
                ans.push_back(v);
                cur = 1;
            }
        }
        return ans;
    }
};
