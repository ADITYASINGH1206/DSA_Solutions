/**
 * Problem:   Count Symmetric Integers (2843)
 * Link: https://leetcode.com/problems/count-symmetric-integers/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int ans =0;
        for(int i = low;i<=high;i++){
            string str= to_string(i);
            int n = str.length();
            int left = 0, right = n-1;
            int left_d = 0, right_d = 0;
            if(n%2 ==0){
                while(left<right){
                    left_d += str[left++]-'0';
                    right_d+= str[right--]-'0';
                }
                if(left_d == right_d) ans++;
            }
        }
        return ans;
    }
};
