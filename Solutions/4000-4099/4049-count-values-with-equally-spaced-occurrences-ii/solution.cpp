/**
 * Problem: Count Values With Equally Spaced Occurrences II (4049)
 * Link: https://leetcode.com/problems/count-values-with-equally-spaced-occurrences-ii/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_map<int, vector<int>> indices;
        
        for (int i = 0; i < nums.size(); ++i) {
            indices[nums[i]].push_back(i);
        }
        
        int ans = 0;
        for (auto [val, idxs] : indices) {
            if (idxs.size() < 3) continue;
            
            bool special = true;
            int diff = idxs[1] - idxs[0];
            
            for (int i = 2; i < idxs.size(); i++) {
                if (idxs[i] - idxs[i-1] != diff) {
                    special = false;
                    break;
                }
            }
            
            if (special) ans++;
        }
        
        return ans;
    }
};
