/**
 * Problem: Pascal's Triangle II (119)
 * Link: https://leetcode.com/problems/pascals-triangle-ii/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans;
        long long val=1;
        ans.push_back(val);
        if(rowIndex == 0){
            return ans;
        }
        for(int i=1;i<rowIndex;i++){
            val = val*(rowIndex-i+1);
            val = val /(i);
            ans.push_back(val);
        }
        ans.push_back(1);
        return ans;
    }
};
