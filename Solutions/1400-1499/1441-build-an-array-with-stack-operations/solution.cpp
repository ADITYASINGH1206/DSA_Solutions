/**
 * Problem: Build an Array With Stack Operations (1441)
 * Link: https://leetcode.com/problems/build-an-array-with-stack-operations/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int size = target.size();
        stack<int> stk;
        vector<string> ans;
        int cur = 1;
        int index = 0;
        
        stk.push(1);
        ans.push_back("Push");
        
        while(index < size){
            while(stk.top() != target[index]){
                stk.pop();
                ans.push_back("Pop");
                cur++;
                stk.push(cur);
                ans.push_back("Push");
            }
            index++;
            if(index == size) break;
            cur++; 
            stk.push(cur);
            ans.push_back("Push");
        }

        return ans;
    }
};
