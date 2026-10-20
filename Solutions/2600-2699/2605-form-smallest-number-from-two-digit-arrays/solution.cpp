/**
 * Problem: Form Smallest Number From Two Digit Arrays (2605)
 * Link: https://leetcode.com/problems/form-smallest-number-from-two-digit-arrays/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minNumber(vector<int>& nums1, vector<int>& nums2) {
        vector<bool>n(10,false);
        int x = 10,y=10;
        int ans = 10;
        for(int num:nums1){
            x=min(x,num);
            n[num]=true;
        }
        bool valid =false;
        for(int num:nums2){
            if(n[num]){
                valid=true;
                ans=min(ans,num);
            }
            y=min(y,num);
        }
        if(valid){
            return ans;
        }
        ans = min(x,y)*10+max(x,y);
        return ans;
    }
};
