/**
 * Problem: First Element with Unique Frequency (3843)
 * Link: https://leetcode.com/problems/first-element-with-unique-frequency/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (int num : nums) {
            mp[num]++;
        }

        unordered_map<int, int> freq;
        for (auto const& pair : mp) {
            int frequency = pair.second;
            freq[frequency]++;
        }

        for (int num : nums) {
            int frequency = mp[num];
            if (freq[frequency] == 1) {
                return num;
            }
        }

        return -1;
    }
};
