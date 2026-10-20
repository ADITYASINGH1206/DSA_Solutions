/**
 * Problem: Total Distance Traveled (2739)
 * Link: https://leetcode.com/problems/total-distance-traveled/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int distanceTraveled(int mainTank, int additionalTank) {
        int ans = 0;
        while(mainTank >= 5 && additionalTank >0){
            ans += 50;
            mainTank -= 5;
            additionalTank--;
            mainTank +=1;
        }
        ans += mainTank*10;
        return ans;
    }
};
