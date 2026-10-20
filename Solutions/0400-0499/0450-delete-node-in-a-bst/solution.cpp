/**
 * Problem: Delete Node in a BST (450)
 * Link: https://leetcode.com/problems/delete-node-in-a-bst/
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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root) 
            if(key < root->val) root->left = deleteNode(root->left, key);     
            else if(key > root->val) root->right = deleteNode(root->right, key);       
            else{
                if(!root->left && !root->right) return NULL;          
                if (root->left && !root->right)
                    return root->left;
                if(!root->left && root->right){
                    return root->right;
                }  
                TreeNode* left = root->left;  
                TreeNode* right = root->right;                      
                while(left->right != NULL) left = left->right;     
                left->right = right;                            
                return root->left;
            }
        return root;
    }   
};
