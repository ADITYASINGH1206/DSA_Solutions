/**
 * Problem: Partition Array into Disjoint Intervals (915)
 * Link: https://leetcode.com/problems/partition-array-into-disjoint-intervals/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int n = nums.size();
        vector<int> maxi(n,0);
        vector<int> mini(n,0);
        maxi[0] = nums[0];
        mini[n-1] = nums[n-1];
        for(int i = 1;i<n;i++){
            if(nums[i]>maxi[i-1]){
                maxi[i] = nums[i];
            }
            else{
                maxi[i] = maxi[i-1];
            }
        }
        for(int i = n-2;i>=0;i--){
            if(nums[i]<mini[i+1]){
                mini[i] = nums[i];
            }
            else{
                mini[i] = mini[i+1];
            }
        }
        for(int i = 0;i<n-1;i++){
            if(maxi[i] <= mini[i+1]) return i+1;
        }
        return -1;
    }
};
