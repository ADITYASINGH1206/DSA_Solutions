/**
 * Problem: Construct Binary Search Tree from Preorder Traversal (1008)
 * Link: https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/
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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i = 0;
        return build(preorder, i, INT_MAX);
    }
    
    TreeNode* build(vector<int>& preorder, int& i, int bound) {
        if (i == preorder.size() || preorder[i] > bound) {
            return nullptr;
        }
        TreeNode* root = new TreeNode(preorder[i++]);
        root->left = build(preorder, i, root->val);
        root->right = build(preorder, i, bound);
        return root;
    }
};

// class Solution {
// public:
//     TreeNode* bstFromPreorder(vector<int>& preorder) {
//         TreeNode* root = new TreeNode(preorder[0]);
//         int n = preorder.size();
//         TreeNode* temp = root;
//         TreeNode* prev= root;
//         for(int i = 1;i<n;i++){
//             temp = root;
//             int val = preorder[i];
//             while(temp){
//                 if(temp->val > val){
//                     prev = temp;
//                     temp = temp->left;
//                 }
//                 else{
//                     prev= temp;
//                     temp = temp->right;
//                 }
//             }

//             if(prev->val > val){
//                 TreeNode* l1 = new TreeNode(val);
//                 prev->left = l1;
//                 continue;
//             }
//             else{
//                 TreeNode* r1 = new TreeNode(val);
//                 prev->right = r1;
//                 continue;
//             }

//         }
//         return root;
//     }
// };
