/**
 * Problem: Rotate List (61)
 * Link: https://leetcode.com/problems/rotate-list/
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
    ListNode* nthNode(ListNode* temp,int n){
        int c = 1;
        while(temp != NULL){
            if(c == n) return temp;
            c++;
            temp = temp->next;

        }
        return temp;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || k == 0) return head;
        ListNode* tail = head;
        int len = 1;
        while(tail->next != NULL){
            len++;
            tail = tail->next;
        }

        if(k % len == 0) return head;

        k = k%len;

        tail->next = head;
        ListNode* newLastNode = nthNode(head,len-k);
        
        head = newLastNode->next;
        newLastNode->next = NULL;

        return head;
    }
};
