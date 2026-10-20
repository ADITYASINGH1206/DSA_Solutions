/**
 * Problem: Maximum Twin Sum of a Linked List (2130)
 * Link: https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/
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
    int pairSum(ListNode* head) {
        ListNode *temp = head;
        vector<int> arr;
        int ans = INT_MIN;
        while(temp != NULL){
            arr.push_back(temp->val);
            temp = temp->next;
        }
        int n = arr.size();
        for(int i = 0;i<n/2;i++){
            ans = max(ans,arr[i] + arr[n-i-1]);

        }
        return ans;
    }
};
