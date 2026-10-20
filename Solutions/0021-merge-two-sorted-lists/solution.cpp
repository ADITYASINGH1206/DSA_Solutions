/**
 * Problem: Merge Two Sorted Lists (21)
 * Link: https://leetcode.com/problems/merge-two-sorted-lists/
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* ans = new ListNode(0);
        ListNode* temp= ans;
        while(list1 && list2){
            if(list1->val < list2->val){
                temp->next = list1;
                list1 = list1->next;
                temp = temp->next;
            }
            else{
                temp->next = list2;
                list2= list2->next;
                temp = temp->next;
            }
        }
        while(list1){
            temp->next = list1;
            list1 = list1->next;
            temp = temp->next;
        }
        while(list2){
            temp->next = list2;
            list2 = list2->next;
            temp = temp->next;
        }

        return ans->next;
    }
};
