/**
 * Problem: Jewels and Stones (771)
 * Link: https://leetcode.com/problems/jewels-and-stones/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int ans=0;
        for(int i=0;i<stones.size();i++){
            for(int j=0;j<jewels.size();j++){
                if(stones[i] == jewels[j]){
                    ans++;
                };
            }

        }
        return ans;
    }
};
