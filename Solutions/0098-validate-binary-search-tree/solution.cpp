/**
 * Problem: Validate Binary Search Tree (98)
 * Link: https://leetcode.com/problems/validate-binary-search-tree/
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
class Solution{
    public:
        bool isValidBST(TreeNode* root){
            return isValidBST(root,LLONG_MIN,LLONG_MAX);
        }
        bool isValidBST(TreeNode* root,long mini,long maxi){
            if(root == NULL)return true;
            if(root->val >= maxi || root->val <= mini) return false;
            return isValidBST(root->left,mini,root->val) && isValidBST(root->right,root->val,maxi);
        }
};
// class Solution {
// public:
//     bool isValidBST(TreeNode* root) {
//         vector<int> result;
//         traverse(root,result);
//         int n = result.size();
//         if(n>1){
//             for(int i =1;i<n;i++){
//                 if(result[i]<=result[i-1]) return false;
//             }
//         }
//         return true;
//     }
    
//     void traverse(TreeNode* root,vector<int>& result){
//         if(root == NULL) return;

//         traverse(root->left,result);
//         result.push_back(root->val);
//         traverse(root->right,result);
//     }
// };
