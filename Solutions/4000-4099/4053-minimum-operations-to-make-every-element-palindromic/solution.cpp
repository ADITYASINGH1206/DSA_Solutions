/**
 * Problem: Minimum Operations to Make Every Element Palindromic (4053)
 * Link: https://leetcode.com/problems/minimum-operations-to-make-every-element-palindromic/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minOperations(vector<int>& nums) {
        static vector<long long> even;
        static vector<long long> odd;
        static bool in = false;
        if (!in) {
            for (int i = 1; i < 100000; i++) {
                long long p1 = i, p2 = i;
                long long t1 = i / 10, t2 = i;
                while (t1 > 0) { 
                    p1 = p1 * 10 + (t1 % 10); 
                    t1 /= 10; 
                }
                while (t2 > 0) { 
                    p2 = p2 * 10 + (t2 % 10); 
                    t2 /= 10; 
                }
                
                if (p1 % 2 == 0) even.push_back(p1); else odd.push_back(p1);
                if (p2 % 2 == 0) even.push_back(p2); else odd.push_back(p2);
            }
            
            sort(even.begin(), even.end());
            sort(odd.begin(), odd.end());
            in = true;
        }
        
        long long ans = 0;
        for (long long x : nums) {
            const vector<long long>& pals = (x % 2 == 0) ? even : odd;
            
            auto it = lower_bound(pals.begin(), pals.end(), x);
            long long diff = LLONG_MAX;

            if (it != pals.end()) {
                diff = min(diff, abs(*it - x));
            }
            if (it != pals.begin()) {
                diff = min(diff, abs(*(it - 1) - x));
            }
            
            ans += diff / 2;
        }
        
        return ans;
    }
};
