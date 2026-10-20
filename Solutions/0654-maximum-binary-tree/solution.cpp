/**
 * Problem: Maximum Binary Tree (654)
 * Link: https://leetcode.com/problems/maximum-binary-tree/
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
    TreeNode* TreeBuild(vector<int>& nums, int start, int end) {
        if (start > end) return nullptr;
        int max_idx = start;
        for (int i = start + 1; i <= end; i++) {
            if (nums[i] > nums[max_idx]) {
                max_idx = i;
            }
        }
        TreeNode* node = new TreeNode(nums[max_idx]);
        node->left = TreeBuild(nums, start, max_idx - 1);
        node->right = TreeBuild(nums, max_idx + 1, end);
        
        return node;
    }

    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return TreeBuild(nums, 0, nums.size() - 1);
    }
};
