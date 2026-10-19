/**
 * Problem: Construct Binary Tree from Inorder and Postorder Traversal (106)
 * Link: https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
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
    
    unordered_map<int, int> map;

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int index = postorder.size()-1;
        for (int i = 0; i < inorder.size(); i++)
            map[inorder[i]] = i;
        return helper(postorder, 0, inorder.size() - 1,index);
    }

    TreeNode* helper(vector<int>& postorder, int start, int end,int& index) {
        if (start > end) return nullptr;

        int rootVal = postorder[index--];
        TreeNode* root = new TreeNode(rootVal);
        int mid = map[rootVal];

        root->right = helper(postorder, mid + 1, end,index);
        root->left = helper(postorder, start, mid - 1,index);
        
        return root;
    }
};
