/**
 * Problem: Sort List (148)
 * Link: https://leetcode.com/problems/sort-list/
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
    ListNode* sortList(ListNode* head) {
        ListNode* temp = head;
        vector<int> nums;
        while(temp){
            nums.push_back(temp->val);
            temp = temp->next;
        }

        sort(nums.begin(),nums.end());
        ListNode* ans = new ListNode(0);
        temp = ans;
        for(int num:nums){
            ListNode* node = new ListNode(num);
            temp->next = node;
            temp = temp->next;
        }

        return ans->next;
    }
};
