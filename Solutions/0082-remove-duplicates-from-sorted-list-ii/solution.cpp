/**
 * Problem: Remove Duplicates from Sorted List II (82)
 * Link: https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* prev = dummy;
        
        while (head != nullptr) {
            if (head->next != nullptr && head->val == head->next->val) {
                while (head->next != nullptr && head->val == head->next->val) {
                    head = head->next;
                }
                prev->next = head->next;
            } else {
                prev = prev->next;
            }
            head = head->next;
        }
        
        ListNode* newHead = dummy->next;
        delete dummy;
        return newHead;
    }
};
