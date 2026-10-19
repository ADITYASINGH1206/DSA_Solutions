/**
 * Problem: Largest Values From Labels (1090)
 * Link: https://leetcode.com/problems/largest-values-from-labels/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int numWanted, int useLimit) {
        int labelmax=0;
        priority_queue<pair<int,int>> pq;
        for(int i=0;i<values.size();i++){
            pq.push({values[i],labels[i]});
            labelmax=max(labelmax,labels[i]);
        }
        int sum=0;
        int z=numWanted;
        vector<int> used(labelmax+1,useLimit);
        while(!pq.empty() && z>0){
            auto it=pq.top();
            int value=it.first;
            int label=it.second;
            if(used[label]>0){
                sum+=value;
                used[label]--;
                z--;
            }
            pq.pop();
        }
        return sum;
    }
};
