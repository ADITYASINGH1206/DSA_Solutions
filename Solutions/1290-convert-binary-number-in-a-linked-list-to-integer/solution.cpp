/**
 * Problem: Convert Binary Number in a Linked List to Integer (1290)
 * Link: https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/
 * Difficulty: Easy
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
    int getDecimalValue(ListNode* head) {
        int ans = 0;
        ListNode* curr = head;

        while(curr){
           int val = curr->val;
           ans = 2*ans + val;
           curr = curr->next;
        }

        return ans;
    }
};
