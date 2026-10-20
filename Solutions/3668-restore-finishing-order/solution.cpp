/**
 * Problem: Restore Finishing Order (3668)
 * Link: https://leetcode.com/problems/restore-finishing-order/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> recoverOrder(vector<int>& order, vector<int>& friends) {
        vector<int>ans;
        for (int i=0;i<order.size();i++){
            for(int j=0;j<friends.size();j++){
                if(order[i] == friends[j]){
                    ans.push_back(order[i]);
                    break;
                }
            }
        }
        return ans;
    }
};
