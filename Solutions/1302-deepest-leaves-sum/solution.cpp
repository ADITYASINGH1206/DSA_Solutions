/**
 * Problem: Deepest Leaves Sum (1302)
 * Link: https://leetcode.com/problems/deepest-leaves-sum/
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
// class Solution {
// public:
//     int deepestLeavesSum(TreeNode* root) {
//         int maxH = 0;
//         int ans = 0;
//         maxH = height(root);
//         traverse(root,maxH,ans,1);
//         return ans;
        
//     }

//     int height(TreeNode* root){
//         if(root == NULL) return 0;

//         int lh = height(root->left);
//         int rh = height(root->right);

//         return 1 + max(lh,rh);
//     }

//     void traverse(TreeNode* root,int maxH,int& ans,int depth){
//         if(root == NULL) return;

//         traverse(root->left,maxH,ans,depth+1);
//         traverse(root->right,maxH,ans,depth+1);

//         if(depth == maxH){
//             ans += root->val;
//         }
//     }
// };

class Solution {
public:
    int deepestLeavesSum(TreeNode* root) {
        if(root==NULL) return 0;
        queue<TreeNode*>q;
        q.push(root);
        int sum=0;
        while(q.empty()==false){
            int n=q.size();
            sum=0;
            for(int i=0;i<n;i++){
                TreeNode* curr=q.front();
                q.pop();
                sum+=curr->val;
                if(curr->left!=NULL) q.push(curr->left);
                if(curr->right!=NULL) q.push(curr->right);
            }
        }
        return sum;
    }
};
