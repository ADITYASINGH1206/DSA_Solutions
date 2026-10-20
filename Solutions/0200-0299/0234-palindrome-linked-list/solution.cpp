/**
 * Problem: Palindrome Linked List (234)
 * Link: https://leetcode.com/problems/palindrome-linked-list/
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
    bool isPalindrome(ListNode* head) {
        vector<int> nums;
        ListNode* temp = head;
        while(temp){
            nums.push_back(temp->val);
            temp = temp->next;
        }
        int l = 0;
        int r = nums.size()-1;
        while(l<r){
            if(nums[l] != nums[r]) return false;
            l++;
            r--;
        }
        return true;
    }
};
