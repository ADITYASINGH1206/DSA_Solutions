/**
 * Problem: Count Values With Equally Spaced Occurrences I (4048)
 * Link: https://leetcode.com/problems/count-values-with-equally-spaced-occurrences-i/
 * Difficulty: Easy
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
            if (idxs.size() == 3) {
                if (idxs[1] - idxs[0] == idxs[2] - idxs[1]) {
                    ans++;
                }
            }
        }
        
        return ans;
    }
};
