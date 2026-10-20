/**
 * Problem: Find the Minimum and Maximum Number of Nodes Between Critical Points (2058)
 * Link: https://leetcode.com/problems/find-the-minimum-and-maximum-number-of-nodes-between-critical-points/
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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> ans = {-1,-1};
        vector<int> criticalPoints;
        ListNode* temp = head;
        vector<int> nums;
        while(temp){
            nums.push_back(temp->val);
            temp = temp->next;
        }
        int n = nums.size();
        if(n<4) return ans;
        for(int i = 1;i<n-1;i++){
            if(nums[i]>nums[i+1] && nums[i]>nums[i-1]) criticalPoints.push_back(i);
            else if(nums[i]<nums[i-1] && nums[i]<nums[i+1])criticalPoints.push_back(i);
        }

        int cp = criticalPoints.size();
        if(cp<2) return ans;
        
        int mini = INT_MAX;
        for(int i = 1;i<cp;i++){
            int dif = criticalPoints[i] - criticalPoints[i-1];
            mini = min(dif,mini);
        }
        ans = {mini,criticalPoints[cp-1]-criticalPoints[0]};
        return ans;
    }
};
