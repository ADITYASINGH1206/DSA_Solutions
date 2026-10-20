/**
 * Problem: Maximal Score After Applying K Operations (2530)
 * Link: https://leetcode.com/problems/maximal-score-after-applying-k-operations/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long ans = 0;
        int n = nums.size();
        priority_queue<int> pq;
        for(int i =0;i<n;i++){
            pq.push(nums[i]);
        }
        for(int i = 0;i<k;i++){
            int top = pq.top();
            pq.pop();
            ans += top;
            if(top%3==0) top = top/3;
            else top = top/3 +1;
            pq.push(top);
        }

        return ans;
    }
};
