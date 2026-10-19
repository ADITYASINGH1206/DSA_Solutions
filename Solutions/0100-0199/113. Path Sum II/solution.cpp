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
    void dfs(TreeNode* root, int sum, int& target, vector<vector<int>>& ans, vector<int>& cur){
        if(root == NULL) return;

        cur.push_back(root->val);
        sum += root->val;
        
        if(!root->left && !root->right){
            if(sum == target) ans.push_back(cur);
        } 
        else {
            dfs(root->left, sum, target, ans, cur);
            dfs(root->right, sum, target, ans, cur);
        }
        
        cur.pop_back(); 
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> cur;
        dfs(root, 0, targetSum, ans, cur);
        return ans;
    }
};