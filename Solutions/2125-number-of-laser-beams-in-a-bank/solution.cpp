/**
 * Problem: Number of Laser Beams in a Bank (2125)
 * Link: https://leetcode.com/problems/number-of-laser-beams-in-a-bank/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        vector<int>laser;
        int ans=0;
        for(int i=0;i<bank.size();i++){
            string row = bank[i];
            int count = 0;
            for(int j=0;j<row.size();j++){
                if(row[j]=='1'){
                    count++;
                }
            }
            if(count >0){
                laser.push_back(count);
            }
            
        }
        for(int i =1;i<laser.size();i++){
            ans+=laser[i]*laser[i-1];
        }
        return ans;
    }
};
