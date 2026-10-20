/**
 * Problem: Number of Senior Citizens (2678)
 * Link: https://leetcode.com/problems/number-of-senior-citizens/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countSeniors(vector<string>& details) {
        int ans = 0;
        for(string pas : details){
            int age = 0;
            age += (pas[11] - '0')*10;
            age += (pas[12] - '0');
            if(age > 60){
                ans++;
            }
        }
        return ans;
    }
};
