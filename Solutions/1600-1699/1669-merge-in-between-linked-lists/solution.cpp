/**
 * Problem: Merge In Between Linked Lists (1669)
 * Link: https://leetcode.com/problems/merge-in-between-linked-lists/
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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* curr = list1;
        for (int i = 0; i < a - 1; ++i) {
            curr = curr->next;
        }
        ListNode* prevA = curr;
        for (int i = 0; i < b - a + 1; ++i) {
            curr = curr->next;
        }
        ListNode* nodeB = curr;
        
        prevA->next = list2;
        ListNode* tail2 = list2;
        while (tail2->next != nullptr) {
            tail2 = tail2->next;
        }
        tail2->next = nodeB->next;
        
        return list1;
    }
};
