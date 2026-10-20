/**
 * Problem: Arithmetic Subarrays (1630)
 * Link: https://leetcode.com/problems/arithmetic-subarrays/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int n = nums.size();
        int ls = l.size();
        vector<bool> ans(ls,false);
        int k = 0;
        while(k<ls){
            vector<int> subarr;
            for(int i = l[k];i<=r[k];i++){
                subarr.push_back(nums[i]);
            }
            sort(subarr.begin(),subarr.end());
            bool ap = true;
            int size = subarr.size();
            if(size == 1){
                ans[k] = true;
                k++;
                continue;
            }
            int dif = subarr[1]-subarr[0];
            for(int i =1;i<subarr.size();i++){
                if(subarr[i]-subarr[i-1] != dif){
                    ap = false;
                    break;
                }
            }
            ans[k] = ap;
            k++;
        }
        return ans;
    }
};
