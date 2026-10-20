/**
 * Problem: All Nodes Distance K in Binary Tree (863)
 * Link: https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/
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
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void markParents(TreeNode* root, unordered_map<TreeNode*,TreeNode*>& parentsMp){
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();
            if(temp->left != NULL){
                parentsMp[temp->left] = temp;
                q.push(temp->left);
            }
            if(temp->right != NULL){
                parentsMp[temp->right] = temp;
                q.push(temp->right);
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*> parentsMp;
        markParents(root,parentsMp);

        unordered_map<TreeNode*,bool> visited;
        queue<TreeNode*>q;
        q.push(target);
        visited[target] = true;
        int cur_level = 0;
        while(!q.empty()){
            int n = q.size();
            if(cur_level++ == k) break;
            for(int i =0;i<n;i++){
                TreeNode* temp = q.front();
                q.pop();
                if(temp->left && !visited[temp->left]){
                    q.push(temp->left);
                    visited[temp->left] = true;
                }
                if(temp->right && !visited[temp->right]){
                    q.push(temp->right);
                    visited[temp->right] = true;
                }
                if(parentsMp[temp] && !visited[parentsMp[temp]]){
                    q.push(parentsMp[temp]);
                    visited[parentsMp[temp]] = true;
                }
            }
        }
        vector<int> ans;
        while(!q.empty()){
            TreeNode* cur = q.front();
            q.pop();
            ans.push_back(cur->val);
        }
        return ans;
        
    }
};
