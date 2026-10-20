/**
 * Problem: Maximum Level Sum of a Binary Tree (1161)
 * Link: https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/
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
    int maxLevelSum(TreeNode* root) {
        int ans = 1;
        int maxi = INT_MIN;
        queue<TreeNode*>q;
        q.push(root);
        int depth = 0;
        while(!q.empty()){
            int s=q.size();
            int sum = 0;
            depth++;
            for(int i=0;i<s;i++){
                TreeNode *node=q.front();
                q.pop();
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
                sum+=node->val;
            }
            if(sum>maxi){
                maxi = sum;
                ans = depth;
            }
        }
        return ans;
    }
};
