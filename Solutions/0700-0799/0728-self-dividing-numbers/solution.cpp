/**
 * Problem: Self Dividing Numbers (728)
 * Link: https://leetcode.com/problems/self-dividing-numbers/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool dig(int num){
        int n = num;
        while(num){
            int digit = num%10;
            if(digit!=0){
                if(n%digit!=0){
                return false;
                }
            }else{
                return false;
            }
        num/=10;
    }
        return true;
    }
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int>ans;
        for(int i = left;i<=right;i++){
            if(dig(i)){
                ans.push_back(i);
            }
        }
        return ans;
    }

};
