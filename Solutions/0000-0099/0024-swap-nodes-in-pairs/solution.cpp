/**
 * Problem: Swap Nodes in Pairs (24)
 * Link: https://leetcode.com/problems/swap-nodes-in-pairs/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 * int val;
 * ListNode *next;
 * ListNode() : val(0), next(nullptr) {}
 * ListNode(int x) : val(x), next(nullptr) {}
 * ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode dummy(0);
        dummy.next = head;
        
        ListNode* prev = &dummy;
        ListNode* curr = head;
        
        while (curr != nullptr && curr->next != nullptr) {
            ListNode* second = curr->next;
            ListNode* nextPair = curr->next->next;
            second->next = curr;       
            curr->next = nextPair;     
            prev->next = second;       

            prev = curr;               
            curr = nextPair;           
        }
        
        return dummy.next;
    }
};
