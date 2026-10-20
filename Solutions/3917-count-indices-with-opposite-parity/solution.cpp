/**
 * Problem: Count Indices With Opposite Parity (3917)
 * Link: https://leetcode.com/problems/count-indices-with-opposite-parity/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> countOppositeParity(vector<int>& nums) {
        int n = nums.size();
        vector<int> answer(n);
        int odd = 0;
        int even = 0;
        
        for (int i = n - 1; i >= 0; i--) {
            if (nums[i] % 2 == 0) { 
                answer[i] = odd;
                even++;
            } else {                
                answer[i] = even;
                odd++;
            }
        }
        
        return answer;
    }
};
