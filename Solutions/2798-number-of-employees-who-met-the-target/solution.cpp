/**
 * Problem: Number of Employees Who Met the Target (2798)
 * Link: https://leetcode.com/problems/number-of-employees-who-met-the-target/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfEmployeesWhoMetTarget(vector<int>& hours, int target) {
        int ans = 0;
        for(int i =0;i<hours.size();i++){
            if(hours[i]>=target){
                ans++;
            }
        }
        return ans;
    }
};
