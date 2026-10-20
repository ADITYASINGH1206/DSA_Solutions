/**
 * Problem: Minimum Number of Operations to Move All Balls to Each Box (1769)
 * Link: https://leetcode.com/problems/minimum-number-of-operations-to-move-all-balls-to-each-box/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> ans;
        for(int i =0;i<boxes.size();i++){
            int count=0;
            for(int j =0;j<boxes.size();j++){
                if(i!=j && boxes[j] =='1'){
                    count+= abs(i-j);
                }
            }
            ans.push_back(count);
        }
        return ans;
    }
};
