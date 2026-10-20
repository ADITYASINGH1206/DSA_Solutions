/**
 * Problem: Sum of Decoded Numbers (4039)
 * Link: https://leetcode.com/problems/sum-of-decoded-numbers/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long modulo = 1e9 + 7;
    long long power(long long x, long long y) {
        long long res = 1;
        x = x % modulo; 
        
        while (y > 0) {
            if (y % 2 == 1) {
                res = (res * x) % modulo;
            }
            y = y / 2;
            x = (x * x) % modulo;
        }
        return res;
    }
    
    int sumDecoded(vector<long long>& nums) {
        int n = nums.size();
        long long ans = 0;
        
        for(int i = 0; i < n; i++){
            long long num = nums[i];
            
            int width = num % 10;
            long long d = num / 10; 
            string ds = to_string(d);
            string x = ds.substr(0, width);
            string y = ds.substr(width);
            long long x1 = x.empty() ? 0 : stoll(x);
            long long y1 = y.empty() ? 0 : stoll(y);
            ans += power(x1, y1);
            ans = ans % modulo;
        }   
        
        return ans;
    }
};
