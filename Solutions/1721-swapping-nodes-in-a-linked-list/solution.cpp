/**
 * Problem: Swapping Nodes in a Linked List (1721)
 * Link: https://leetcode.com/problems/swapping-nodes-in-a-linked-list/
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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* start = nullptr;
        
        for (int i = 1; i < k; ++i) {
            fast = fast->next;
        }
        
        start = fast;
        
        while (fast->next != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }
        swap(start->val, slow->val);
        
        return head;
    }
};
