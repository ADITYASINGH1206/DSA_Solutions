/**
 * Problem: Insert Greatest Common Divisors in Linked List (2807)
 * Link: https://leetcode.com/problems/insert-greatest-common-divisors-in-linked-list/
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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* temp = head;
        while (temp->next) {
            int g = gcd(temp->val,temp->next->val);
            ListNode* g1 = new ListNode(g,temp->next);
            temp->next = g1;
            temp = temp->next->next;
        }
        return head;
    }
};
