/**
 * Problem: Merge Nodes in Between Zeros (2181)
 * Link: https://leetcode.com/problems/merge-nodes-in-between-zeros/
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
    ListNode* mergeNodes(ListNode* head) {
        int sum = 0;
        ListNode* temp = head->next; 
        vector<int> sums;
        while(temp != nullptr){ 
            sum += temp->val;
            if(temp->val == 0){
                sums.push_back(sum);
                sum = 0;
            }
            temp = temp->next; 
        }
        
        ListNode* ans = new ListNode(0);
        ListNode* dans = ans;
        for(int i = 0; i < sums.size(); i++){
            ans->next = new ListNode(sums[i]);
            ans = ans->next;
        }

        return dans->next;
    }
};
