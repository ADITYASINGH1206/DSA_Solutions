/**
 * Problem: Count Nodes Equal to Average of Subtree (2265)
 * Link: https://leetcode.com/problems/count-nodes-equal-to-average-of-subtree/
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
    int ans = 0;

    int averageOfSubtree(TreeNode* root) {
        postOrder(root);
        return ans;
    }

    pair<int, int> postOrder(TreeNode* root) {
        if (root == nullptr) {
            return {0, 0}; 
        }

        pair<int, int> leftSubtree = postOrder(root->left);
        pair<int, int> rightSubtree = postOrder(root->right);

        int currentSum = leftSubtree.first + rightSubtree.first + root->val;
        int currentCount = leftSubtree.second + rightSubtree.second + 1;

        if (currentSum / currentCount == root->val) {
            ans++;
        }
        return {currentSum, currentCount};
    }
};
