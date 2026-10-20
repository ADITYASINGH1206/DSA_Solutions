/**
 * Problem: Validate Stack Sequences (946)
 * Link: https://leetcode.com/problems/validate-stack-sequences/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int n = pushed.size();
        stack<int> stk;
        int l = 0;
        int r = 0;
        while(r<n || l<n){
            if(stk.empty() && l<n){
                stk.push(pushed[l]);
                l++;
            }
            if(!stk.empty()){
                if(stk.top() == popped[r]){
                    stk.pop();
                    r++;
                }
                else{
                    if(l<n){
                        stk.push(pushed[l]);
                        l++;
                    }
                    else{
                        return false;
                    }
                }
            }
        }

        return true;
    }
};
