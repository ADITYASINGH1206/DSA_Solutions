/**
 * Problem: Binary Search Tree Iterator (173)
 * Link: https://leetcode.com/problems/binary-search-tree-iterator/
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
class BSTIterator {
public:
    stack<TreeNode*> stk;
    BSTIterator(TreeNode* root) {
        pushAll(root);
    }
    
    int next() {
        TreeNode* temp = stk.top();
        stk.pop();
        pushAll(temp->right);
        return temp->val;
    }
    
    bool hasNext() {
        return !stk.empty();
    }

    void pushAll(TreeNode* root){
        while(root){
            stk.push(root);
            root = root->left;
        }
    }
};

// class BSTIterator {
// public:
//     vector<int> nodes;
//     BSTIterator(TreeNode* root) {
//         traverse(root,nodes);
//         reverse(nodes.begin(),nodes.end());
//     }
    
//     int next() {
//         int n = nodes.size();
//         int val = nodes[n-1];
//         nodes.pop_back();
//         return val;
//     }
    
//     bool hasNext() {
//         int n = nodes.size();
//         return n;
//     }
//     void traverse(TreeNode* root,vector<int> & nodes){
//         if(root == NULL) return;

//         traverse(root->left,nodes);
//         nodes.push_back(root->val);
//         traverse(root->right,nodes);

//     }
// };
/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
