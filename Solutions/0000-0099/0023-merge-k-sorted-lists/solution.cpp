/**
 * Problem: Merge k Sorted Lists (23)
 * Link: https://leetcode.com/problems/merge-k-sorted-lists/
 * Difficulty: Hard
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        vector<int> nums;
        for(auto list:lists){
            while(list){
                nums.push_back(list->val);
                list = list->next;
            }
        }
        sort(nums.begin(),nums.end());
        int n= nums.size();
        ListNode* ans = new ListNode(0);
        ListNode* temp = ans;
        for(int i = 0;i<n;i++){
            ListNode* node = new ListNode(nums[i]);
            temp->next = node;
            temp = temp->next;
        }

        return ans->next;
    }
};
