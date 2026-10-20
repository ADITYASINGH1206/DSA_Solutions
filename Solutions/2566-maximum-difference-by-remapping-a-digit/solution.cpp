/**
 * Problem: Maximum Difference by Remapping a Digit (2566)
 * Link: https://leetcode.com/problems/maximum-difference-by-remapping-a-digit/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minMaxDifference(int num) {
        string maxi = to_string(num);
        int n = maxi.size();
        char maxi_char = maxi[0];
        for(int i =0;i<n;i++){
            if(maxi[i] != '9'){
                maxi_char = maxi[i]; 
                break;
            }
        }
        for(int i =0;i<n;i++){
            if(maxi[i] == maxi_char) maxi[i] = '9';
        }
        string mini = to_string(num);
        char mini_char = mini[0];
        for(int i =0;i<n;i++){
            if(mini[i] != '0') {
                mini_char = mini[i]; 
                break;
            }
        }
        for(int i =0;i<n;i++){
            if(mini[i] == mini_char) mini[i] = '0';
        }

        int ans = stoi(maxi)-stoi(mini);
        return ans;
    }
};
