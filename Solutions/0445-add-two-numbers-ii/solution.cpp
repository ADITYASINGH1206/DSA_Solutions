/**
 * Problem: Add Two Numbers II (445)
 * Link: https://leetcode.com/problems/add-two-numbers-ii/
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> stk1,stk2;

        while (l1 != nullptr) {
            stk1.push(l1->val);
            l1 = l1->next;
        }

        while (l2 != nullptr) {
            stk2.push(l2->val);
            l2 = l2->next;
        }


        ListNode* ans = nullptr;
        int carry = 0;

        while(!stk1.empty() || !stk2.empty()|| carry!=0){
            int d1 = !stk1.empty() ? stk1.top() : 0;
            int d2 = !stk2.empty() ? stk2.top() : 0;

            int sum = d1+d2+carry;
            carry = sum/10;
            sum = sum%10;

            ListNode* node = new ListNode(sum);
            node->next = ans;
            ans = node;

            if(!stk1.empty()) stk1.pop();
            if(!stk2.empty()) stk2.pop();

        }
        return ans;

    }
};
