/**
 * Problem: Remove Nth Node From End of List (19)
 * Link: https://leetcode.com/problems/remove-nth-node-from-end-of-list/
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int length = 0;
        ListNode* temp = head;
        while (temp) {
            length++;
            temp = temp->next;
        }

        int targetIndex = length - n;

        if (targetIndex == 0) {
            ListNode* newHead = head->next;
            delete head; 
            return newHead;
        }
        temp = head;
        while (targetIndex > 1) {
            temp = temp->next;
            targetIndex--;
        }

        ListNode* toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete; 
        
        return head;
    }
};
