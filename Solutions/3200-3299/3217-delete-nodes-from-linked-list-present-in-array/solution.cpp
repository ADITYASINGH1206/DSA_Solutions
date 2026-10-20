/**
 * Problem: Delete Nodes From Linked List Present in Array (3217)
 * Link: https://leetcode.com/problems/delete-nodes-from-linked-list-present-in-array/
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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        ListNode* temp = head;
        unordered_set<int> st(nums.begin(),nums.end());
        vector<int> num;
        while(temp){
            if(st.find(temp->val) == st.end()){
                num.push_back(temp->val);
            }
            temp = temp->next;
        }
        ListNode* ans = new ListNode(0);
        temp = ans;
        int n = num.size();
        for(int i = 0;i<n;i++){
            ListNode* node = new ListNode(num[i]);
            temp->next = node;
            temp = temp->next;
        }
        return ans->next;
    }
};
