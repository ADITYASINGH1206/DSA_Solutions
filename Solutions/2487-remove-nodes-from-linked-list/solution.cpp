/**
 * Problem: Remove Nodes From Linked List (2487)
 * Link: https://leetcode.com/problems/remove-nodes-from-linked-list/
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
    ListNode* removeNodes(ListNode* head) {
        vector<int> stk;
        ListNode* temp = head;
        while(temp != NULL){
            if(stk.empty()){
                stk.push_back(temp->val);
            }
            else{
                while(!stk.empty() && stk.back() < temp->val){
                    stk.pop_back();
                }
                stk.push_back(temp->val);

            }
            temp = temp->next;
        }
        ListNode* ans = new ListNode(0);
        ListNode* curr = ans;
        
        for (int val : stk) {
            curr->next = new ListNode(val);
            curr = curr->next;
        }
        return ans->next;
    }
};
