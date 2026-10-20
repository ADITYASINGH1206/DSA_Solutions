/**
 * Problem: Sort Even and Odd Indices Independently (2164)
 * Link: https://leetcode.com/problems/sort-even-and-odd-indices-independently/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        int n = nums.size();
        vector<int> odd;
        vector<int> even;
        int l = 0;
        int r = 0;
        for(int i = 0;i<n;i++){
            if(i%2==0) even.push_back(nums[i]);
            else odd.push_back(nums[i]);
        }
        sort(odd.rbegin(),odd.rend());
        sort(even.begin(),even.end());
        vector<int> ans(n,0);
        for(int i = 0;i<n;i++){
            if(i%2==0) ans[i] = even[l++];
            else ans[i] = odd[r++];
        }
        return ans;
    }
};
