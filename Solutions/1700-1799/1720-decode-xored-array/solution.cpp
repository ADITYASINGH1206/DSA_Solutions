/**
 * Problem: Decode XORed Array (1720)
 * Link: https://leetcode.com/problems/decode-xored-array/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        vector<int> ans;
        ans.push_back(first);
        for (int x : encoded) {
            ans.push_back(ans.back() ^ x);
        }
        return ans;
    }
};
