/**
 * Problem: Remove Duplicates from Sorted List (83)
 * Link: https://leetcode.com/problems/remove-duplicates-from-sorted-list/
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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode* current = head;
        while(current != nullptr && current->next != nullptr){
            if(current->val == current->next->val){
                current->next = current->next->next;
            }
            else{
                current = current->next;
            }
        }
        return head;
    }
};

// class Solution {
// public:
//     ListNode* deleteDuplicates(ListNode* head) {
//         set<int> nums;
//         ListNode* temp = head;
//         while(temp){
//             nums.insert(temp->val);
//             temp = temp->next;
//         }
//         ListNode* ans = new ListNode(0);
//         temp = ans;
//         for(auto num:nums){
//             ListNode* node = new ListNode(num);
//             temp->next = node;
//             temp = temp->next;
//         }

//         return ans->next;
//     }
// };
