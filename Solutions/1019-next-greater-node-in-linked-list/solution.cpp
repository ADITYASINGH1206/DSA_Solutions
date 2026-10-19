/**
 * Problem: Next Greater Node In Linked List (1019)
 * Link: https://leetcode.com/problems/next-greater-node-in-linked-list/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> ans;
        vector<int> nums;
        stack<int> stk;
        ListNode* temp = head;
        
        while(temp){
            nums.push_back(temp->val);
            temp = temp->next;
        }

        int n = nums.size();
        for(int i = n - 1; i >= 0; i--){
            while(!stk.empty() && stk.top() <= nums[i]){
                stk.pop();
            }
            if(stk.empty()){
                ans.push_back(0);
            } else {
                ans.push_back(stk.top());
            }
            stk.push(nums[i]);
        }
        
        reverse(ans.begin(), ans.end());

        return ans;
    }
};
