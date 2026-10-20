/**
 * Problem: Clumsy Factorial (1006)
 * Link: https://leetcode.com/problems/clumsy-factorial/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int clumsy(int n) {
        stack<int> stk;
        stk.push(n);
        
        int op = 0; 
        
        for(int i = n - 1; i > 0; i--){
            if(op == 0){
                int top = stk.top();
                stk.pop();
                stk.push(top * i);
            }
            else if(op == 1){
                int top = stk.top();
                stk.pop();
                stk.push(top / i);
            }
            else if(op == 2){
                stk.push(i);
            }
            else if(op == 3){

                stk.push(-i);
            }
            
            op = (op + 1) % 4; 
        }

        int ans = 0;
        while(!stk.empty()){
            ans += stk.top();
            stk.pop();
        }

        return ans;
    }
};
