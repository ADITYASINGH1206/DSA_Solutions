/**
 * Problem: Largest Number After Digit Swaps by Parity (2231)
 * Link: https://leetcode.com/problems/largest-number-after-digit-swaps-by-parity/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestInteger(int num) {
        priority_queue<int>pq1;
        priority_queue<int>pq2;
        int n = num;
        while(n>0){
            int d = n%10;
            if(d%2==0) pq1.push(d);
            else pq2.push(d);
            n=n/10;
        }
        string s = to_string(num);
        string ans;
        for(int i=0;i<s.size();i++){
            if((s[i]-'0')%2==0) {
                ans+=char(pq1.top() + '0');;
                pq1.pop();
            }
            else{
                ans+=char(pq2.top() + '0');
                pq2.pop();
            }
        } 
        return stoi(ans);
    }
};
