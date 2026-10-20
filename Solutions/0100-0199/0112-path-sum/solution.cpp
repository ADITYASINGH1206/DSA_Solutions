/**
 * Problem: Path Sum (112)
 * Link: https://leetcode.com/problems/path-sum/
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
    bool dfs(TreeNode* root,int sum,int target){
        if(root == NULL) return false;

        sum+= root->val;

        if(root->left == NULL && root->right == NULL){
            if(sum == target) return true;
            return false;
        }

        bool left = dfs(root->left,sum,target);
        bool right = dfs(root->right,sum,target);

        if(left || right) return true;

        return false;

    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        return(dfs(root,0,targetSum));
    }
};
