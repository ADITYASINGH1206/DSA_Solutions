/**
 * Problem: Minimum Number of Increments on Subarrays to Form a Target Array (1526)
 * Link: https://leetcode.com/problems/minimum-number-of-increments-on-subarrays-to-form-a-target-array/
 * Difficulty: Hard
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
int minNumberOperations(vector<int>& target){
    int ans = target[0];
    for (int i = 1; i < target.size(); i++)
        ans += max(target[i] - target[i - 1], 0);
    return ans;
    }
};
