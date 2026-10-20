/**
 * Problem: Remove Stones to Minimize the Total (1962)
 * Link: https://leetcode.com/problems/remove-stones-to-minimize-the-total/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        int sum=0;
        int n=piles.size();
        priority_queue<int> pq;
        for(int i=0;i<n;i++){
            sum+=piles[i];
            pq.push(piles[i]);
        }
        while(k--){
            int a = pq.top();
            pq.pop();
            sum-=a/2;
            pq.push((a+1)/2);
        }
        return sum;
    }
};
