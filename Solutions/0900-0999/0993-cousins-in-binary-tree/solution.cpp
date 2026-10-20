/**
 * Problem: Cousins in Binary Tree (993)
 * Link: https://leetcode.com/problems/cousins-in-binary-tree/
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
    void dfs(TreeNode* root,TreeNode* parent,int& x,vector<int>& ans,int depth){
        if(root == NULL) return;
        depth++;
        if(root->val == x){
            ans[0] = parent->val;
            ans[1] = depth;
            return;
        }
        parent = root;
        dfs(root->left,parent,x,ans,depth);
        dfs(root->right,parent,x,ans,depth);


    }
    bool isCousins(TreeNode* root, int x, int y) {
        vector<int> t1(2,0);
        vector<int> t2(2,0);
        TreeNode* temp1 = root;
        TreeNode* temp2 = root;
        dfs(temp1,temp1,x,t1,0);
        dfs(temp2,temp2,y,t2,0);
        if(t1[0] != t2[0] && t1[1] == t2[1]) return true;

        return false;
    }
};
