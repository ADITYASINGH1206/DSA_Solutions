/**
 * Problem: Diameter of Binary Tree (543)
 * Link: https://leetcode.com/problems/diameter-of-binary-tree/
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
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        checkHeight(root,ans);
        return ans;

    }
    int checkHeight(TreeNode* root,int& ans){
        if(root == NULL) return 0;

        int lh = checkHeight(root->left,ans);
        int rh = checkHeight(root->right,ans);

        ans = max(ans,lh+rh);

        return 1+ max(lh,rh);
    }
};
