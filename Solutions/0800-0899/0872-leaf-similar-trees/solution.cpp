/**
 * Problem: Leaf-Similar Trees (872)
 * Link: https://leetcode.com/problems/leaf-similar-trees/
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
    void dfs(TreeNode* root,vector<int>& leaves){
        if(root == NULL) return ;
        if(root->left == NULL && root->right == NULL) leaves.push_back(root->val);
        dfs(root->left,leaves);
        dfs(root->right,leaves);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leaves1;
        vector<int> leaves2;
        dfs(root1,leaves1);
        dfs(root2,leaves2);
        int n1 = leaves1.size();
        int n2 = leaves2.size();
        if(n1 != n2) return false;
        for(int i = 0;i<n1;i++){
            if(leaves1[i] != leaves2[i]) return false;
        }
        return true;
    }
};
